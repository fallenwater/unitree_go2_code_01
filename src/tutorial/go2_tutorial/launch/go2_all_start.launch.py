from launch import LaunchDescription
from launch_ros.actions import Node

# 封装终端指令相关类--------------
# from launch.actions import execute_process
# from launch.substitutions import FindExecutable
# 参数声明与获取-----------------
# from launch.actions import DeclareLaunchArgument
# from launch.substitutions import LaunchConfiguration
# 文件包含相关-------------------
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
# 分组相关----------------------
# from launch_ros.actions import PushRosNamespace
# from launch.actions import GroupAction
# 事件相关----------------------
# from launch.event_handlers import OnProcessStart, OnProcessExit 
# from launch.actions import ExecuteProcess, RegisterEventHandler, LogInfo
# 获取功能包下share目录路径-------
from ament_index_python import get_package_share_directory
import os


def generate_launch_description():

    # 包含按键控制launch启动文件(要求能够同时创建新的中断来控制机器狗)
    go2_teleop_ctrl_keyboard = get_package_share_directory("go2_teleop_ctrl_keyboard")

    go2_teleop_ctrl_keyboard_launch = IncludeLaunchDescription(
        launch_description_source=PythonLaunchDescriptionSource(
            launch_file_path=os.path.join(
                go2_teleop_ctrl_keyboard,"launch","go2_teleop_ctrl_keyboard.launch.py")
        )
    )

    go2_driver_pkg = get_package_share_directory("go2_driver")      # 获取功能包下share目录路径---home\xn\unitree_go2_ws\...\go2_driver

    # 包含驱动
    go2_driver_launch = IncludeLaunchDescription(
        launch_description_source=PythonLaunchDescriptionSource(
            launch_file_path=os.path.join(go2_driver_pkg,"launch","driver.launch.py")       # 获得go2_driver下的launch.py文件
        )
    )
    
    # 包含巡航功能
    go2_tutorial_pkg = get_package_share_directory("go2_tutorial")
    go2_ctrl_launch = IncludeLaunchDescription(
        launch_description_source=PythonLaunchDescriptionSource(
            launch_file_path=os.path.join(go2_tutorial_pkg,"launch","go2_ctrl.launch.py")
        )
    )
    # 包含巡航启停服务端，客户端单独调用
    cru_service_node = Node(
        package="go2_tutorial",
        executable="go2_cruising_service",
        parameters=[os.path.join(go2_tutorial_pkg,"params","go2_cruising_service.yaml")]
    )

    return LaunchDescription([
        go2_teleop_ctrl_keyboard_launch,
        go2_driver_launch,
        go2_ctrl_launch,
        cru_service_node,
    ])