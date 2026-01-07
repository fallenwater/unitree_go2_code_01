'''
需求：将ROS2中常用的速度指令（geometry_msgs::msg::Twist），
         转换成四组机器人的速度指令（unitree_api::msg::Request）。
    流程：
        1.包含头文件；
        2.初始化ROS2客户端；
        3.自定义节点类；
          3-1.创建四组机器人速度指令发布对象；
          3-2.创建ROS2速度指令twist订阅对象；
          3-3.在订阅对象的回调函数中将Twsit转换成Request并发布。
        4.调用spin函数，并传入节点对象指针；
        5.资源释放。
'''
#################################################
# 通过 ros2 run teleop_twist_keyboard teleop_twist_keyboard 指令调用ros2的twist参数控制
#################################################
# 1.导包
import json
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from unitree_api.msg import Request
from .sport_model import ROBOT_SPORT_API_IDS

class TwistBridge(Node):
    def __init__(self):
        super().__init__('twist_bridge_node_py')
        # 3-1.创建四组机器人速度指令发布对象；
        self.request_pub = self.create_publisher(Request,"/api/sport/request",10)
        # 3-2.创建ROS2速度指令twist订阅对象；(消息类型，话题名称。回调函数，qos)
        self.twist_pub_ = self.create_subscription(Twist,"cmd_val",self.twist_cb,10)
    
    def twist_cb(self,twist: Twist):        # twist: Twist  为twist参数赋予消息类型 Twist
        # 3-3.在订阅对象的回调函数中将Twsit转换成Request并发布。
        request = Request()
        x = twist.linear.x      # x速度
        y = twist.linear.y      # y速度
        z = twist.angular.z     # z角速度
        # 设置 api_id
        api_id = ROBOT_SPORT_API_IDS["BALANCESTAND"]
        if x != 0 or y != 0 or z != 0:
            api_id = ROBOT_SPORT_API_IDS["MOVE"]
            # 设置参数
            js = {"x": x, "y": y, "z": z}
            request.parameter = json.dumps(js)  # 转换成字符串
        request.header.identity.api_id = api_id     # 组织api_id(对应unitree参数)
        self.request_pub.publish(request)   # 将参数发布出去


def main():
    rclpy.init()
    rclpy.spin(TwistBridge())
    rclpy.shutdown()

if __name__ == '__main__':
    main()