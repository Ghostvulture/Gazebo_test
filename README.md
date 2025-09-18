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

