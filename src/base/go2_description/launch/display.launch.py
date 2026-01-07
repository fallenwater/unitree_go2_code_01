from launch import LaunchDescription
from launch_ros.actions import Node

# 封装终端指令相关类--------------
# from launch.actions import execute_process
# from launch.substitutions import FindExecutable
# 参数声明与获取-----------------
# from launch.actions import DeclareLaunchArgument
# from launch.substitutions import LaunchConfiguration
# 文件包含相关-------------------
# from launch.actions import IncludeLaunchDescription
# from launch.launch_description_sources import PythonLaunchDescriptionSource
# 分组相关----------------------
# from launch_ros.actions import PushRosNamespace
# from launch.actions import GroupAction
# 事件相关----------------------
# from launch.event_handlers import OnProcessStart, OnProcessExit 
# from launch.actions import ExecuteProcess, RegisterEventHandler, LogInfo
# 获取功能包下share目录路径-------
# from ament_index_python import get_package_share_directory

from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command,LaunchConfiguration
from ament_index_python import get_package_share_directory      # 获取功能报路径
import os
from launch.conditions import IfCondition
from launch.actions import DeclareLaunchArgument

def generate_launch_description():
    # 获取功能包路径
    go2_description_pkg = get_package_share_directory("go2_description")

    use_joint_state_publisher = DeclareLaunchArgument(
        name = "use_joint_state_publisher",
        default_value = "true"
    )
    
    # 使用 xacro 读取 urdf 文件里面的内容
    # robot_desc = ParameterValue(Command(["xacro ", 
    #                     os.path.join(go2_description_pkg,"urdf","go2_description.urdf")]))  # 拼接起来
     
    # 不限制urdf文件路径，调用参数即可指定模型路径
    model = DeclareLaunchArgument(
        name = "urdf_path",
        default_value = os.path.join(go2_description_pkg,"urdf","go2_description.urdf")
    )
    robot_desc = ParameterValue(Command(["xacro ", LaunchConfiguration("urdf_path")]))  # 拼接起来

    # robot_state_publisher === 加载机器人 urdf 文件  
    robot_state_publisher = Node(
        package="robot_state_publisher",                            # 包
        executable="robot_state_publisher",                         # 可执行文件
        parameters=[{"robot_description": robot_desc}],             # 参数
    )

    # joint_state_publisher === 发布关节状态，连接多个骨架
    # 以后更合理的方式是由程序动态获取关节信息并发布，并且不再能用joint_state_publisher
    # 这个节点的启动应该是有附加条件的
    joint_state_publisher = Node(
        package="joint_state_publisher",             # 包
        executable="joint_state_publisher",          # 可执行文件
        condition = IfCondition(LaunchConfiguration("use_joint_state_publisher"))
    
    )
    # 如果不需要执行默认的关节节点，切换成动态关节信息，运行程序时需要加上如下的 参数！！
    # ros2 launch go2_description display.launch.py use_joint_state_publisher:=false
    return LaunchDescription([
        model,
        use_joint_state_publisher,
        robot_state_publisher,
        joint_state_publisher,
    ])