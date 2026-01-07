/*  
    需求：以动态调参的方式控制 go2 运动。
    步骤：
        1.包含头文件；
        2.初始化 ROS2 客户端；
        3.定义节点类；
            
            
        4.调用spin函数,并传入节点对象指针；
        5.释放资源。
*/

// 代码功能：运行后，通过rqt控制节点中的参数，控制机器狗运动
// 1.包含头文件；
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "unitree_api/msg/request.hpp"
#include "sport_model.hpp"
#include "nlohmann/json.hpp"

// using std::placeholders::_1;
using namespace std::chrono_literals;
// 3.定义节点类；
class Go2Ctrl : public rclcpp::Node{
    public:
        Go2Ctrl():Node("go2_ctrl"){
            RCLCPP_INFO(this->get_logger(),"Go2Ctrl创建!");

            // 设置参数
            this->declare_parameter("sport_api_id",ROBOT_SPORT_API_ID_BALANCESTAND);
            this->declare_parameter("x",0.0);       // x线速度0.1
            this->declare_parameter("y",0.0);
            this->declare_parameter("z",0.0);       // 角速度0.5

            // 创建发布对象
            req_pub_ = this->create_publisher<unitree_api::msg::Request>("/api/sport/request", 10);
            // 设置时间间隔 回调函数
            timer_ = this->create_wall_timer(100ms, std::bind(&Go2Ctrl::on_timer, this));

            
        }
    private:
        rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr req_pub_;
        // 设置一个定时器
        rclcpp::TimerBase::SharedPtr timer_;
        void on_timer(){
            // 创建速度指令并发布
            unitree_api::msg::Request request;

            auto id = this->get_parameter("sport_api_id").as_int();     // 捕获参数
            // 设置参数
            request.header.identity.api_id = id; // 运动模式

            if(id == ROBOT_SPORT_API_ID_MOVE)
            {
                // 通过 js 打包数据成字符串样式
                nlohmann::json js;
                js["x"] = this->get_parameter("x").as_double();        
                js["y"] = this->get_parameter("y").as_double(); 
                js["z"] = this->get_parameter("z").as_double();     

                // RCLCPP_INFO(this->get_logger(),"发送指令!");
                // 通过parameter设置速度(只能接收字符串样式的内容，需要通过js转)
                request.parameter = js.dump();

            }
            req_pub_->publish(request);
        }

};


int main(int argc, char * argv[])
{
    // 2.初始化 ROS2 客户端；
    rclcpp::init(argc, argv);
    // 4.调用spin函数,并传入节点对象指针。
    rclcpp::spin(std::make_shared<Go2Ctrl>());
    // 5.释放资源；
    rclcpp::shutdown();
    return 0;
}