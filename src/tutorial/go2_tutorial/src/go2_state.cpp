/*  
    需求：订阅里程计消息，当机器人位移超出指定阈值，输出机器人此刻的坐标
    实现流程：
        1.订阅里程计消息；
        2.在订阅方的回调函数中计算当前机器人位置与上一个记录点的距离
          如果距离大于阈值就输出坐标并更新记录点
        
          第一个记录点如何生成？
                当第一次订阅到里程计消息时，就为记录点赋值。
            
*/

// 1.包含头文件；
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "nav_msgs/msg/odometry.hpp"
// using std::placeholders::_1;

using namespace std::placeholders;

// 3.定义节点类；
class Go2State : public rclcpp::Node{
    public:
        Go2State():Node("go2_state"){
            RCLCPP_INFO(this->get_logger(),"Go2State创建!");
             
            last_x = last_y = 0.0;
            is_first = true;       
            this->declare_parameter("distance",0.5);
            odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
                                    "odom", 10, std::bind(&Go2State::odom_cb, this, _1));
        }
    private:
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
        double last_x, last_y;      // 上一次坐标x，y
        bool is_first;              // 判断是否是连接上节点后的第一次获取该消息
        void odom_cb(const nav_msgs::msg::Odometry::SharedPtr odom){
            // 初始化第一个记录点数据
            // 获取机器人当前坐标
            double x = odom->pose.pose.position.x;
            double y = odom->pose.pose.position.y;

            // 如果是第一次订阅到该消息，那么就赋值
            if (is_first)
            {
                last_x = x;
                last_y = y;
                is_first = false;
                RCLCPP_INFO(this->get_logger(),"起点坐标:(%.2f,%.2f)",last_x,last_y);
                return;
            }

            // 计算是否超出阈值
            double distance_x = x - last_x;
            double distance_y = y - last_y;
            
            // 计算距离
            double distance = sqrt(pow(distance_x,2) + pow(distance_y,2));
            
            if (distance > this->get_parameter("distance").as_double())
            {
                // 输出坐标
                RCLCPP_INFO(this->get_logger(),"坐标：(%.2f,%.2f)",x,y);
                last_x = x;
                last_y = y;
            }
            
        }
};


int main(int argc, char * argv[])
{
    // 2.初始化 ROS2 客户端；
    rclcpp::init(argc, argv);
    // 4.调用spin函数,并传入节点对象指针。
    rclcpp::spin(std::make_shared<Go2State>());
    // 5.释放资源；
    rclcpp::shutdown();
    return 0;
}