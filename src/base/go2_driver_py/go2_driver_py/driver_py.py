'''
    需求：该节点启动时，需要实现三个主要功能。
        1.发布里程计消息；
        2.广播里程计相关坐标变换；
        3.发布关节状态信息。
    分析1:发布里程计消息:
        1.先了解里程计消息的字段；
        2.这些数据从哪获取？ 机器人已经发布了相关话题了；
        3.实现上，可以先订阅状态话题，然后解析转换成里程计消息.
    分析2:广播里程计相关坐标变换:
        1.需要发布机器人 base基座标系 与 odom坐标系 的相对关系;
        2.这些相对关系与里程计数据类似;
        3.最后发布即可.
    分析3:发布关节状态信息:
        1.先了解关节状态信息;
        2.怎么获取这些数据？机器人已经发布了相关话题了;
        3.实现上，可以先订阅低层状态话题，然后解析转换成关节消息.
'''

# 1.查看话题是否启动
# ros2 topic list | grep -i odom
# 2.打印话题输出结果
# ros2 topic echo /odom
 
# 🌃通过此代码，在ros2 launch go2_driver_py driver_py后，
# 能够实时返回机器狗的运动状态(例如姿态、位置)
# 并且在狗运动时能够实时观察到狗的位姿信息


# 1.导包;
import rclpy
import time
from rclpy.node import Node
from std_msgs.msg import String
from nav_msgs.msg import Odometry           # 里程计（被发布的消息）
from unitree_go.msg import SportModeState   # 运动状态（数据源）
from unitree_go.msg import LowState         # 底层状态信息，这两个信息一同实现rviz2关节实时变化
from sensor_msgs.msg import JointState      # 关节状态信息，这两个信息一同实现rviz2关节实时变化

from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster

# 3.自定义节点类；
class Driver(Node):
    def __init__(self):
        super().__init__("driver")
        self.get_logger().info("Driver创建了!(python)")

        # 将父级坐标系 声明成参数，默认值为"odom"
        self.declare_parameter("odom_frame", "odom")
        self.declare_parameter("base_frame", "base")
        self.declare_parameter("publish_tf","true")
        # 获取这个 值odom 的键 再取value
        self.odom_frame = self.get_parameter("odom_frame").value
        self.base_frame = self.get_parameter("base_frame").value
        self.publish_tf = self.get_parameter("publish_tf").value

        # 创建 odom 的发布对象(消息类型，话题名称，qos)
        self.odom_pub = self.create_publisher(Odometry,"odom",10)
        # 创建 SportModeState 的订阅对象(消息类型，话题名称，回调函数，qos)
        self.mode_sub = self.create_subscription(SportModeState,
                                "lf/sportmodestate",self.mode_cb,10)
        # 创建坐标变换广播器
        self.tf_bro = TransformBroadcaster(self)

        # 创建关节状态发布对象(话题名称自拟)
        self.joint_pub = self.create_publisher(JointState, "joint_states", 10)
        # 创建底层状态获取对象（回调函数中实现数据转换）😅  底层对象话题已经固定为如下
        self.state_sub = self.create_subscription(LowState, "lf/lowstate", self.state_cb, 10)

    def state_cb(self, state: LowState):
        # 获取并发布关节状态
        joint_state = JointState()

        # 数据组织
        joint_state.header.stamp = self.get_clock().now().to_msg()

        # 设置16个关节名称
        joint_state.name = [
            "FL_hip_joint", "FL_thigh_joint","FL_calf_joint",
            "FR_hip_joint", "FR_thigh_joint","FR_calf_joint",
            "RL_hip_joint", "RL_thigh_joint","RL_calf_joint",
            "RR_hip_joint", "RR_thigh_joint","RR_calf_joint"
        ]
        # 设置旋转角度
        for i in range(12):     # motor_state一共20个，但是只有12个有效旋转电机状态    
            q = float(state.motor_state[i].q)    # 旋转角度
            joint_state.position.append(q)

        # 发布
        self.joint_pub.publish(joint_state) # 发布对对象

    def mode_cb(self, mode: SportModeState):        # 通过mode: 指向具体的mode类型
        # 解析生成odom对象
        odom = Odometry()
        # 时间戳，获取当前时刻
        odom.header.stamp = self.get_clock().now().to_msg() # to_msg后才能赋值
        # 原点坐标系
        odom.header.frame_id = self.odom_frame   # 父级坐标系
        # 机器狗基坐标系
        odom.child_frame_id = self.base_frame
        
        # 位置
        odom.pose.pose.position.x = float(mode.position[0])
        odom.pose.pose.position.y = float(mode.position[1])
        odom.pose.pose.position.z = float(mode.position[2])

        # 姿态(四元数姿态)
        odom.pose.pose.orientation.w = float(mode.imu_state.quaternion[0])
        odom.pose.pose.orientation.x = float(mode.imu_state.quaternion[1])
        odom.pose.pose.orientation.y = float(mode.imu_state.quaternion[2])
        odom.pose.pose.orientation.z = float(mode.imu_state.quaternion[3])

        # 速度
        odom.twist.twist.linear.x = float(mode.velocity[0])
        odom.twist.twist.linear.y = float(mode.velocity[1])
        odom.twist.twist.linear.z = float(mode.velocity[2])

        odom.twist.twist.angular.z = float(mode.yaw_speed)
        # 发布
        self.odom_pub.publish(odom)

        # 广播坐标变换
        if self.publish_tf:
            # 生成坐标变换数据并发布
            trans_form = TransformStamped()
            # 时间戳
            trans_form.header.stamp = self.get_clock().now().to_msg()
            # 父集坐标系(原点坐标系)
            trans_form.header.frame_id = self.odom_frame
            # 子集坐标系(机械狗基坐标系)
            trans_form.child_frame_id = self.base_frame

            # 设置偏移量
            trans_form.transform.translation.x = odom.pose.pose.position.x
            trans_form.transform.translation.y = odom.pose.pose.position.y
            trans_form.transform.translation.z = odom.pose.pose.position.z

            # 设置旋转角度(都是四元数类型 quaternion)
            # w,x.y.z一起转换
            trans_form.transform.rotation = odom.pose.pose.orientation

            # 发布
            self.tf_bro.sendTransform(trans_form)



def main():
    # 2.初始化ROS2客户端;
    rclpy.init()
    # 4.调用spin函数,并传入节点对象指针；
    rclpy.spin(Driver())
    # 5.释放资源；
    rclpy.shutdown()

if __name__ == '__main__':
    main()