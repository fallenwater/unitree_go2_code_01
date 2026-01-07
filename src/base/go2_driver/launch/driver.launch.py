from launch import LaunchDescription
from launch_ros.actions import Node

# 封装终端指令相关类--------------
# from launch.actions import execute_process
# from launch.substitutions import FindExecutable
# 参数声明与获取-----------------
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
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
from launch.conditions import IfCondition


import os
'''
    launch文件需要集成功能:
        1.机器人模型可视化；
        2.速度消息桥接；
        3.里程计消息发布、广播里程计坐标变换、发布关节状态
'''

def generate_launch_description():

    go2_desc_pkg = get_package_share_directory("go2_description")
    go2_driver_pkg = get_package_share_directory("go2_driver")

    # 为 rviz2 添加开关，通过参数的方式控制 rviz2 的是否启动
    use_rviz = DeclareLaunchArgument(
        name="use_rviz",
        default_value="true"
    ) 

    return LaunchDescription([
        use_rviz,
        # 机器人模型可视化
        IncludeLaunchDescription(
            launch_description_source = PythonLaunchDescriptionSource(
                launch_file_path=os.path.join(go2_desc_pkg,"launch","display.launch.py")
            ),
            # 以下参数配置为false才能获得实际狗的姿态
            launch_arguments=[("use_joint_state_publisher","false")]

        ),
        # 包含rviz2,通过launch文件快速启动rviz2，（用已经配置好的插件来启动模型）
        Node(
            package = "rviz2",
            executable = "rviz2",
            condition=IfCondition(LaunchConfiguration("use_rviz")),
            arguments = ["-d", os.path.join(go2_driver_pkg,"rviz","display.rviz")],
          # 为rviz2的启动添加动态开关
        ),
        # 雷达坐标系重映射  radar  ->  utlidar_lidar
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            # arguments=["--frame-id","radar","--child-frame-id","utlidar_lidar"]
            arguments=['0', '0', '0', '1', '0', '0', "radar", "utlidar_lidar"]
        ),
        # 速度消息桥接
        Node(
            package="go2_twist_bridge",
            executable="twist_bridge"
        ),
        # 3.里程计消息发布、广播里程计坐标变换、发布关节状态信息
        Node(
            package="go2_driver",
            executable="driver",
            # name="driver_cpp",
            output="screen",
            parameters=[os.path.join(go2_driver_pkg,"params","driver.yaml")]
        ),
        
    ])
