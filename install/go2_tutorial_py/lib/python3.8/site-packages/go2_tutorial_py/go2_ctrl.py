'''
    需求：以动态调参的方式控制 go2 运动。
    步骤：
        1.包含头文件；
        2.初始化 ROS2 客户端；
        3.定义节点类；
            
            
        4.调用spin函数,并传入节点对象指针；
        5.释放资源。
'''
# 通过rqt ，调节对应节点的参数，实现机器狗运动状态的动态修改
# 1.导包;
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from unitree_api.msg import Request
from .sport_model import ROBOT_SPORT_API_IDS
import json

# 3.自定义节点类；
class Go2Ctrl(Node):
    def __init__(self):
        super().__init__("go2_ctrl")
        self.get_logger().info("Go2Ctrl创建了!(python)")

        # 设置参数
        self.declare_parameter("sport_api_id", ROBOT_SPORT_API_IDS["BALANCESTAND"])
        self.declare_parameter("x", 0.0)
        self.declare_parameter("y", 0.0)
        self.declare_parameter("z", 0.0)


        # 1.创建发布对象
        self.req_pub = self.create_publisher(Request,"/api/sport/request", 10)
        # 2.创建定时器并周期性发布速度指令
        self.timer = self.create_timer(0.1, self.on_timer)
    
    def on_timer(self):
        # 3.发布速度指令
        request = Request()

        # 获取运动参数
        id = self.get_parameter("sport_api_id").get_parameter_value().integer_value
        
        request.header.identity.api_id = id
        # request.header.identity.api_id = ROBOT_SPORT_API_IDS["MOVE"]
        
        if id == ROBOT_SPORT_API_IDS["MOVE"]:
            js = {
                "x": self.get_parameter("x").get_parameter_value().double_value,
                "y": self.get_parameter("y").get_parameter_value().double_value,
                "z": self.get_parameter("z").get_parameter_value().double_value,
            }
            request.parameter = json.dumps(js)          # 打包字符串参数
            self.get_logger().info("发送速度指令！！！")

        self.req_pub.publish(request)

def main():
    # 2.初始化ROS2客户端;
    rclpy.init()
    # 4.调用spin函数,并传入节点对象指针；
    rclpy.spin(Go2Ctrl())
    # 5.释放资源；
    rclpy.shutdown()

if __name__ == '__main__':
    main()