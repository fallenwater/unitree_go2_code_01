'''
    需求：客户端向服务端发送整形数据，并接收服务端的响应结果。
    步骤：
        1.判断提交的数据是否合法：起码提交一个参数
        2.ros2 初始化；
        3.创建自定义的节点类对象；
        4.连接服务端，如果服务端没启动的话会失败；
        5.连接成功后需要向服务端发送数据；
        6.处理响应结果；
        7.资源释放。
'''

# 1.导包;
import rclpy
from rclpy.node import Node
from rclpy.logging import get_logger
from std_msgs.msg import String
import sys
from go2_tutorial_inter.srv import Cruising 
from rclpy.task import Future

# 3.自定义节点类；
class Go2CruisingClient(Node):
    def __init__(self):
        super().__init__("go2_cruising_client")
        self.get_logger().info("Go2CruisingClient创建了!(python)")
        #创建客户端
        self.client = self.create_client(Cruising, "cruising")      # 默认带有qos，无需自行添加
        
    
    # 连接服务
    def connect_server(self):
        while not self.client.wait_for_service(1.0):
            if not rclpy.ok():
                get_logger("rclpy").error("连接被中断")
                return False
            self.get_logger().info("服务连接中")
        return True
    
    # 发送数据
    def send_request(self,flag) -> Future:      # 发送数据，并声明该函数参数返回值为 Future类型
        # 组织数据
        req = Cruising.Request()
        req.flag = int(flag)
        # 发送请求
        return self.client.call_async(req)
    
def main():
    # 1.判断提交的数据是否合法：起码提交一个参数
    if len(sys.argv) != 2:
        get_logger("rclpy").error("请提交一个整形数据：") 
        return
    # 2.ros2 初始化；
    rclpy.init()
    # 3.创建自定义的节点类对象；
    cru_client = Go2CruisingClient()
    # 4.连接服务端，如果服务端没启动的话会失败；
    flag = cru_client.connect_server()
    if not flag:
        return
    # 5.连接成功后需要向服务端发送数据；
    future = cru_client.send_request(sys.argv[1])
    # 6.处理响应结果；
    rclpy.spin_until_future_complete(cru_client,future)
    if future.done():           # 如果future正常结束了
        response : Cruising.Response = future.result()      # 取出里面的数据
        get_logger("rclpy").info("机器人坐标：(%.2f,%.2f)" % (response.point.x, response.point.y))
    else:
        get_logger("rclpy").info("请求失败！")
    # 7.资源释放。
    rclpy.shutdown()

if __name__ == '__main__':
    main()