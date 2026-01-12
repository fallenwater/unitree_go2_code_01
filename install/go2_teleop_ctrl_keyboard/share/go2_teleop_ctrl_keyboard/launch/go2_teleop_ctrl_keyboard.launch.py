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

import os 



def generate_launch_description():

    return LaunchDescription([
        Node(
            package="go2_teleop_ctrl_keyboard",
            executable="go2_teleop_ctrl_keyboard",
            # 这里可以新增一个窗口执行对应程序
            prefix="xterm -e",      # xterm能直接启动但是terminator不行
            # prefix=["terminator", "-e", "bash", "-c"],      # 可自行选择用哪个命令行窗口执行程序，这边我用了terminator
            output="screen"
        )
    ])