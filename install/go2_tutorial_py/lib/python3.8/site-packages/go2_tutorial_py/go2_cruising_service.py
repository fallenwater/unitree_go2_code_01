'''
    需求：处理客户端提交的数据（0或非0)
          如果是0:停止巡航
          如果非0:开始巡航
          不管提交什么数据，都需要响应机器人的位置信息。
    流程：
        1.创建服务端；
        2.回调函数处理请求，分情况处理（控制机器人巡航），最后响应结果。
'''

# 1.导包;
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from go2_tutorial_inter.srv import Cruising
from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry
from unitree_api.msg import Request 
from .sport_model import ROBOT_SPORT_API_IDS
import json

'''
发送如下指令可控制机器狗巡航启停
ros2 service call /cruising go2_tutorial_inter/srv/Cruising "{flag: 1}"
ros2 service call /cruising go2_tutorial_inter/srv/Cruising "{flag: 0}"
启动动作由参数设置x y z

可通过rqt 找到节点 “go2_cruising_service” , 调节参数xyz
'''

# 3.自定义节点类；
class Go2CruisingService(Node):
    def __init__(self):
        super().__init__("go2_cruising_service")
        self.get_logger().info("Go2CruisingService创建了!(python)")
        # 创建服务端
        self.service = self.create_service(Cruising,"cruising",self.cru_cb)         # 服务端， 同节点发送数据 ，服务端会响应回调函数执行指定任务
        # 创建空的Point
        self.point = Point()
        # 订阅里程计数据(里程计数据实时记录机器狗位置信息)
        self.odom_sub = self.create_subscription(Odometry, "odom", self.odom_cb, 10)
        # 设置巡航参数
        self.declare_parameter("x",0.1)
        self.declare_parameter("y",0.0)
        self.declare_parameter("z",1.0)

        # 创建速度控制发布对象
        '''
        param_client_ = std::make_shared<rclcpp::AsyncParametersClient>(this, "go2_ctrl");  // 连接上两个节点
        这种功能python无法实现,所以直接在这边编写相关控制代码
        '''
        self.api_id = ROBOT_SPORT_API_IDS["BALANCESTAND"]
        self.req_pub = self.create_publisher(Request, "/api/sport/request", 10)
        self.timer = self.create_timer(0.1, self.on_timer)      # 创建定时器，定时执行 发送 publish 的功能

    def on_timer(self):     # 在定时器回调函数中发布速度指令
        req = Request()
        # 设置数据
        req.header.identity.api_id = self.api_id       # 设置一个api_id值，决定机器狗的动作
        # 设置参数
        js = {
            "x": self.get_parameter("x").value,
            "y": self.get_parameter("y").value,
            "z": self.get_parameter("z").value,

        }
        req.parameter = json.dumps(js)          # 将数据转换成字符串样式并传给req.parameter
        self.req_pub.publish(req)                  # 调用publisher功能发布指令

    def cru_cb(self, request : Cruising.Request, response : Cruising.Response):
        # 处理请求
        flag = request.flag

        if (flag == 0):
            self.get_logger().info("结束巡航")
            self.api_id = ROBOT_SPORT_API_IDS["STOPMOVE"]
        else:
            self.get_logger().info("开始巡航")
            self.api_id = ROBOT_SPORT_API_IDS["MOVE"]

        # 产生响应
        response.point = self.point
        return response
    
    # 里程计回调函数
    def odom_cb(self, odom : Odometry):     # 订阅 Odomtry类型的里程计消息
        self.point = odom.pose.pose.position            # 为临时变量point 赋值，实时获取到里程计数据


def main():
    # 2.初始化ROS2客户端;
    rclpy.init()
    # 4.调用spin函数,并传入节点对象指针；
    rclpy.spin(Go2CruisingService())
    # 5.释放资源；
    rclpy.shutdown()

if __name__ == '__main__':
    main()