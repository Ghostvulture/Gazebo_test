#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess, DeclareLaunchArgument, LogInfo
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Launch configuration variables
    use_keyboard = LaunchConfiguration('use_keyboard')
    use_test_vel = LaunchConfiguration('use_test_vel')
    
    # Launch arguments
    declare_use_keyboard_cmd = DeclareLaunchArgument(
        'use_keyboard',
        default_value='true',
        description='Use keyboard controller instead of velocity driver')
    
    declare_use_test_vel_cmd = DeclareLaunchArgument(
        'use_test_vel',
        default_value='false',
        description='Use test velocity publisher')

    # Path to the SDF file
    sdf_file_path = '/home/xyz/Desktop/xluo/Gazebo_test/urdf.sdf'
    
    # Start Gazebo with the robot model
    start_gazebo_cmd = ExecuteProcess(
        cmd=['ign', 'gazebo', '-r', sdf_file_path],
        output='screen',
        name='gazebo_simulation'
    )

    # Keyboard wheel controller node
    keyboard_controller_node = Node(
        package='my_robot_pkg',
        executable='keyboard_wheel_controller',
        name='keyboard_wheel_controller',
        output='screen',
        condition=IfCondition(use_keyboard)
    )
    
    # Advanced wheel torque driver node (subscribes to /cmd_vel)
    wheel_driver_node = Node(
        package='my_robot_pkg',
        executable='wheel_torque_driver',
        name='wheel_torque_driver',
        output='screen',
        parameters=[{
            'wheel_radius': 0.05,
            'wheel_separation': 0.3,
            'max_torque': 20.0,
            'kp': 8.0,
            'ki': 2.0,
            'kd': 0.5
        }],
        condition=UnlessCondition(use_keyboard)
    )
    
    # Test velocity publisher (optional)
    test_vel_node = Node(
        package='my_robot_pkg',
        executable='simple_vel_publisher',
        name='simple_vel_publisher',
        output='screen',
        condition=IfCondition(use_test_vel)
    )

    # Create the launch description and populate
    ld = LaunchDescription()

    # Add launch arguments
    ld.add_action(declare_use_keyboard_cmd)
    ld.add_action(declare_use_test_vel_cmd)
    
    # Add information
    ld.add_action(LogInfo(msg='Starting Gazebo simulation...'))
    
    # Add actions to launch description
    ld.add_action(start_gazebo_cmd)
    ld.add_action(keyboard_controller_node)
    ld.add_action(wheel_driver_node)
    ld.add_action(test_vel_node)

    return ld
