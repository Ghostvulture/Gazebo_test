#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription([
        # 声明参数
        DeclareLaunchArgument(
            'publish_rate',
            default_value='50.0',
            description='Feedback publish rate (Hz)'
        ),
        
        # 简化反馈收集器
        Node(
            package='my_robot_pkg',
            executable='simple_feedback_main',
            name='simple_feedback_collector',
            output='screen',
            parameters=[{
                'publish_rate': LaunchConfiguration('publish_rate')
            }]
        ),
        
        # 简化力矩指令器
        Node(
            package='my_robot_pkg',
            executable='simple_torque_main',
            name='simple_torque_commander',
            output='screen'
        )
    ])
