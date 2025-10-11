# Gazebo_test

### Pipeline

``` 
   [SDF World + URDF Robot]
              │
              ▼
       Ignition Gazebo
   (物理引擎 + 插件运行)
              │
   ┌──────────┴───────────┐
   │                      │
  传感器数据             控制输入
   │                      │
   ▼                      ▼
ROS <──ros_gz_bridge──> C++ 控制节点
```

## structure
### sensor_test

```
.
├── build
│   ├──...
|
├── CMakeLists.txt
├── lidar_node.cpp
├── save.config
├── sensor_launch.ign
└── sensor.sdf

```
运行文件：
```terminal
ign launch sensor_launch.ign
```