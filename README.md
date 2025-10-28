# Gazebo_test

### Pipeline

``` 
      [SDF world+Robot]
              │
              ▼
       Ignition Gazebo <──ros_gz_bridge──> ROS
   (物理引擎 + 插件运行)                     │
            │                              │
            │                              │
         传感器数据                       控制输入
            │                              │
            ▼                              ▼
          ROS2                           Gazebo
```

## respository structure

```
├─basic_test
├─bipedal_4
│  ├─config
│  ├─launch
│  ├─meshes
│  ├─textures
│  └─urdf
├─ros2_workspace
│  ├─build
│  ├─log
│  └─src
│      └─my_robot_pkg
│          ├─include
│          │  └─my_robot_pkg
│          ├─launch
│          └─src
│              └─model
└─sensor_test
    └─build
        └─CMakeFiles
            ├......
```


# 运行现有程序

in shell A, start gazebo simulation

```
ign gazebo urdf.sdf
```

in shell B, bridge them with yaml
```
ros2 run ros_gz_bridge parameter_bridge --ros-args -p config_file:=src/my_robot_pkg/src/init_bridge.yaml
```

now we have a code to only let wheel run, run this code in shell C:

```
ros2 run my_robot_pkg gazebo_keyboard_controller --ros-args -p max_force:=10.0
```
# 修改后
first build the package
```
colcon build
```
then source the overlay 
```
source install/setup.bash
```