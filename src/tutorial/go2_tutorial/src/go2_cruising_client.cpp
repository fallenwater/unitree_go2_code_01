
/*  
    需求：客户端向服务端发送整形数据，并接收服务端的响应结果。
    步骤：
        1.判断提交的数据是否合法：起码提交一个参数
        2.ros2 初始化；
        3.创建自定义的节点类对象；
        4.连接服务端，如果服务端没启动的话会失败；
        5.连接成功后需要向服务端发送数据；
        6.处理响应结果；
        7.资源释放。
*/

// 1.包含头文件；
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "go2_tutorial_inter/srv/cruising.hpp"

using namespace std::chrono_literals;
// using std::placeholders::_1;

// 3.定义节点类；
class Go2CrusingClient : public rclcpp::Node{
    public:
        Go2CrusingClient():Node("go2_cruising_client"){
            RCLCPP_INFO(this->get_logger(),"Go2CrusingClient创建!");
            cru_client_ = this->create_client<go2_tutorial_inter::srv::Cruising>("cruising");   // 创建客户端
        }
        // 连接服务端
        bool connect_server(){
            while (!cru_client_->wait_for_service(1s))
            {
                if (!rclcpp::ok())
                {
                    return false;
                }
                RCLCPP_INFO(this->get_logger(),"服务连接中......");
            }
            return true;
        }
        // 发送请求并返回响应结果
        std::shared_future<std::shared_ptr<go2_tutorial_inter::srv::Cruising_Response>>  send_request(int32_t flag){
            auto req_ = std::make_shared<go2_tutorial_inter::srv::Cruising::Request>();
            req_->flag = flag;

            return cru_client_->async_send_request(req_);
        }
    private:
        rclcpp::Client<go2_tutorial_inter::srv::Cruising>::SharedPtr cru_client_;
};


int main(int argc, char * argv[])
{
    // 1.验证
    if (argc != 2)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"),"请提交一个整形数据！");
        return 1;
    }
    // 2.初始化 ROS2 客户端；
    rclcpp::init(argc, argv);
    // 3.创建节点lei对象；
    auto client_ = std::make_shared<Go2CrusingClient>();
    // 4.连接服务端，如果服务端没启动的话会失败；

    auto flag = client_->connect_server();

    // 5.连接成功后需要向服务端发送数据；
    if (!flag)
    {
        return 1;
    }
    // 通过 atoi 将argv[1]第一个参数转换为字符串，然后发送请求
    auto response_future = client_->send_request(atoi(argv[1]));
    // 6.处理响应结果；(需要传入当前节点和返回结果,作用于判断当前响应结果的状态码是否成功)
    if (rclcpp::spin_until_future_complete(client_,response_future) == rclcpp::FutureReturnCode::SUCCESS){
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"响应成功！");
        auto response_ = response_future.get();     // 获得cruising的response的指针、
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"机器人坐标:(%.2f,%.2f)",response_->point.x,response_->point.y);
    } else{
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"),"响应失败！");
    }
    // 7.资源释放。
    // 5.释放资源；
    rclcpp::shutdown();
    return 0;
}