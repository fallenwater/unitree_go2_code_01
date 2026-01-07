'''
    需求：订阅里程计消息，当机器人位移超出指定阈值，输出机器人此刻的坐标
    实现流程：
        1.订阅里程计消息；
        2.在订阅方的回调函数中计算当前机器人位置与上一个记录点的距离
          如果距离大于阈值就输出坐标并更新记录点
        
          第一个记录点如何生成？
                当第一次订阅到里程计消息时，就为记录点赋值。
            
'''

# 1.导包;
import math
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
#include "nav_msgs/msg/odometry.hpp"
from nav_msgs.msg import Odometry

# 3.自定义节点类；
class Go2State(Node):
    def __init__(self):
        super().__init__("go2_state")
        self.get_logger().info("go2_state创建了!(python)")

        # 第一次获取里程计消息的标记
        self.is_first = True
        # 记录点的坐标对应变量
        self.last_x = 0.0
        self.last_y = 0.0
        # 将阈值设置为参数
        self.declare_parameter("distance",0.1)

        self.odom_sub = self.create_subscription(Odometry, "odom", self.odom_cb, 10)
        

    def odom_cb(self, odom : Odometry):
        # 获取当前坐标
        x = odom.pose.pose.position.x
        y = odom.pose.pose.position.y


        # 设置第一个记录点
        if self.is_first:
            self.last_x = x
            self.last_y = y
            self.is_first = False
            self.get_logger().info("原点坐标:(%.2f,%.2f)" % (x,y))
            
            return          # 判断完是初始点了，可以直接退出这轮循环了
        
        # 计算是否超出距离
        dis_x = x - self.last_x
        dis_y = y - self.last_y

        distance = math.sqrt(dis_x ** 2 + dis_y ** 2)
        self.get_logger().info("坐标:(%.2f,%.2f)" % (x,y))

        # 判断
        if distance >= self.get_parameter(distance).value:
            # 输出座标点
            self.get_logger().info("阈值坐标:(%.2f,%.2f)" % (x,y))
            # 记录点数据更新
            self.last_x = x
            self.last_y = y

def main():
    # 2.初始化ROS2客户端;
    rclpy.init()
    # 4.调用spin函数,并传入节点对象指针；
    rclpy.spin(Go2State())
    # 5.释放资源；
    rclpy.shutdown()

if __name__ == '__main__':
    main()