
/*  
    需求：处理客户端提交的数据（0或非0)
          如果是0:停止巡航
          如果非0:开始巡航
          不管提交什么数据，都需要响应机器人的位置信息。
    流程：
        1.创建服务端；
        2.回调函数处理请求，分情况处理（控制机器人巡航），最后响应结果。

*/
// ros2 launch go2_tutorial go2_cruising.launch.py 
// 调用以上代码启动巡航后，可以通过以下代码获取当前机器狗位置坐标信息
// ros2 service call /cruising go2_tutorial_inter/srv/Cruising "{flag: 1}"  
// 向服务端发送指令，获取服务端的 位置 参数

// 1.包含头文件；
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "go2_tutorial_inter/srv/cruising.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "sport_model.hpp"

using namespace std::placeholders;      // 参数占位
using namespace std::chrono_literals;   // 时间设置
// using std::placeholders::_1;

// 3.定义节点类；
class Go2CrusingService : public rclcpp::Node{
    public:
        Go2CrusingService():Node("go2_cruising_service"){               // 服务节点
            RCLCPP_INFO(this->get_logger(),"Go2CrusingService创建!");

            // 设置参数
            // this->declare_parameter("sport_api_id",ROBOT_SPORT_API_ID_BALANCESTAND);
            this->declare_parameter("x",0.0);       // x线速度0.1
            this->declare_parameter("y",0.0);
            this->declare_parameter("z",1.0);       // 角速度0.5


            // 创建远程参数客户端(依赖于当前节点和被远程连接的节点名称 go2_ctrl)
            // 此功能在python中无法实现
            param_client_ = std::make_shared<rclcpp::AsyncParametersClient>(this, "go2_ctrl");  // 连接上两个节点
            // 让客户端连接到服务端
            while ( !param_client_->wait_for_service(1s) )  // 连接不上就一直循环
            {   
                if (!rclcpp::ok())
                {
                    return; // 通过ctrl + c 手动终端
                    RCLCPP_ERROR(this->get_logger(),"未连接，已手动中断");
                }
                RCLCPP_INFO(this->get_logger(),"服务连接中......");
            }
            RCLCPP_INFO(this->get_logger(),"成功连接到参数服务端！！");
            // 通过订阅里程计消息获取机器人的位置信息
            odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>("odom", 10, std::bind(&Go2CrusingService::odom_cb,this,_1));
            // 创建服务端
            cru_service_ = this->create_service<go2_tutorial_inter::srv::Cruising>("cruising",std::bind(&Go2CrusingService::cru_cb, this, _1, _2));
        }
    private:
        // 可以通过 参数客户端 来实现参数的远程输入
        rclcpp::AsyncParametersClient::SharedPtr param_client_;
        rclcpp::Service<go2_tutorial_inter::srv::Cruising>::SharedPtr cru_service_;
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
        geometry_msgs::msg::Point current_point;            // 当前座标点
        // 实时获取机器人位置
        void odom_cb(const nav_msgs::msg::Odometry::SharedPtr odom){
            current_point = odom->pose.pose.position;
        }
        void cru_cb(const go2_tutorial_inter::srv::Cruising::Request::SharedPtr request, 
                    const go2_tutorial_inter::srv::Cruising::Response::SharedPtr response){
            // 处理请求
            auto flag = request->flag;
            // 向 go2_ctrl 节点注入参数，如果是 0 ，那么 api_id 设置为 stop_move, 否则 api_id 设置为 Move
            int32_t id;
            if (flag != 0)
            {
                id = ROBOT_SPORT_API_ID_MOVE;           // id 开始移动
                RCLCPP_INFO(this->get_logger(),"开始巡航......");
                
            }else{
                id = ROBOT_SPORT_API_ID_STOPMOVE;       // id 停止移动
                RCLCPP_INFO(this->get_logger(),"结束巡航......");
                

            }
            // 向巡航节点（服务端）注入参数
            param_client_->set_parameters({
                // rclcpp::Parameter("x",0.1),
                // rclcpp::Parameter("y",0.0),
                // rclcpp::Parameter("z",0.5),
                this->get_parameter("x"),
                this->get_parameter("y"),
                this->get_parameter("z"),
                rclcpp::Parameter("sport_api_id", id),
            });
            // 生成响应
            response->point = current_point;
        }
        
};


int main(int argc, char * argv[])
{
    // 2.初始化 ROS2 客户端；
    rclcpp::init(argc, argv);
    // 4.调用spin函数,并传入节点对象指针。
    rclcpp::spin(std::make_shared<Go2CrusingService>());
    // 5.释放资源；
    rclcpp::shutdown();
    return 0;
}