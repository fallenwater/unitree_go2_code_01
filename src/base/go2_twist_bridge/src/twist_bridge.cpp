/*
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
*/
// 1.包含头文件；
#include "rclcpp/rclcpp.hpp"
#include "unitree_api/msg/request.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sport_model.hpp"
#include "nlohmann/json.hpp"

using namespace std::placeholders;

class TwistBridge : public rclcpp::Node{
    public:
        TwistBridge(): Node("twist_bridge_node"){
            RCLCPP_INFO(this->get_logger(),
                "TwistBridge已创建,可以将geometry_msgs/msg/twist消息转换成unitree_api/msg/request消息");
                
            // 3-1.创建四组机器人速度指令发布对象；
            request_pub_ = this->create_publisher<unitree_api::msg::Request>
                            ("/api/sport/request",10);

            // 3-2.创建ROS2速度指令twist订阅对象；
            twist_sub_ = this->create_subscription<geometry_msgs::msg::Twist>
                            ("cmd_vel",10, std::bind(&TwistBridge::twist_cb, this, _1 ));
              
        }
    private:
        rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr request_pub_;
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr twist_sub_;
        void twist_cb(const geometry_msgs::msg::Twist::SharedPtr twist){
            // 3-3.在订阅对象的回调函数中将Twsit转换成Request并发布。
            unitree_api::msg::Request request;
            // 转换
            // 获取 twist 消息的线速度和角速度
            double x = twist->linear.x;
            double y = twist->linear.y;
            double z = twist->angular.z;  //z方向的角速度
            // 默认 api_id 为平衡站立
            auto api_id = ROBOT_SPORT_API_ID_BALANCESTAND;
            if ( x != 0 || y != 0|| z != 0)
            {
                api_id = ROBOT_SPORT_API_ID_MOVE;
                // 设置运动参数 --- 组织一个字符串样式的速度指令
                nlohmann::json js;
                js["x"] = x;
                js["y"] = y;
                js["z"] = z;
                // 将三个运动参数转换为 request 适配的字符串格式
                request.parameter = js.dump();
            }
            request.header.identity.api_id = api_id;
            request_pub_->publish(request); // 发送request 
          }
};
int main(int argc, char const *argv[])
{
    // 2.初始化ROS2客户端；
    rclcpp::init(argc,argv);
    // 4.调用spain函数，并传入节点对象指针；
    rclcpp::spin(std::make_shared<TwistBridge>());
    // 5.资源释放。
    rclcpp::shutdown();
    return 0;
}