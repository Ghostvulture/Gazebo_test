#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
import os

def generate_launch_description():
    # 获取桥接配置文件路径
    pkg_share = '/home/xyz/Desktop/xluo/Gazebo_test/ros2_workspace/src/my_robot_pkg/src'
    bridge_config = os.path.join(pkg_share, 'init_ros2_bridge.yaml')
    
    return LaunchDescription([
        # 启动ROS-Gazebo桥接
        Node(
            package='ros_gz_bridge',
            executable='parameter_bridge',
            name='ros_gz_bridge',
            arguments=[
                '--ros-args', 
                '-p', f'config_file:={bridge_config}'
            ],
            output='screen',
            respawn=True,
        ),
        
        # 启动键盘控制节点
        Node(
            package='my_robot_pkg',
            executable='keyboard_wheel_controller',
            name='keyboard_wheel_controller',
            output='screen',
            parameters=[
                {'max_force': 8.0},  # 最大力矩
                {'update_rate': 50.0}  # 更新频率
            ]
        ),
    ])
