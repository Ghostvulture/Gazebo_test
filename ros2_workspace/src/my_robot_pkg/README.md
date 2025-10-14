# C++ Robot Control Package

这个包包含了三个主要的C++可执行文件，用于控制双足机器人的轮子：

## 🚀 可执行文件

### 1. `keyboard_wheel_controller` - 键盘控制器
直接通过键盘控制机器人轮子的转矩。

**控制键：**
- `W/S`: 前进/后退
- `A/D`: 左转/右转  
- `Q/E`: 减小/增大转矩
- `SPACE`: 紧急停止
- `X/C`: 停止运动
- `ESC`: 退出程序

### 2. `wheel_torque_driver` - 高级轮子驱动器
订阅`/cmd_vel`话题，使用PID控制算法控制轮子转矩。

**特性：**
- PID控制算法
- 差分驱动运动学
- 速度平滑过滤
- 安全超时保护

**参数：**
- `wheel_radius`: 轮子半径 (默认: 0.05m)
- `wheel_separation`: 轮子间距 (默认: 0.3m)
- `max_torque`: 最大转矩 (默认: 20.0 N⋅m)
- `kp`, `ki`, `kd`: PID参数

### 3. `simple_vel_publisher` - 测试速度发布器
自动发布测试速度命令到`/cmd_vel`话题，用于测试轮子驱动器。

## 🛠️ 编译和运行

### 编译包
```bash
cd /home/xyz/Desktop/xluo/Gazebo_test/ros2_workspace
colcon build --packages-select my_robot_pkg
source install/setup.bash
```

### 运行方式

#### 1. 使用启动文件（推荐）

**键盘控制模式：**
```bash
ros2 launch my_robot_pkg robot_control.launch.py
```

**高级控制模式（订阅/cmd_vel）：**
```bash
ros2 launch my_robot_pkg robot_control.launch.py use_keyboard:=false
```

**测试模式（自动运动）：**
```bash
ros2 launch my_robot_pkg robot_control.launch.py use_keyboard:=false use_test_vel:=true
```

#### 2. 单独运行

**只启动Gazebo：**
```bash
ign gazebo -r /home/xyz/Desktop/xluo/Gazebo_test/urdf.sdf
```

**键盘控制器：**
```bash
ros2 run my_robot_pkg keyboard_wheel_controller
```

**轮子驱动器：**
```bash
ros2 run my_robot_pkg wheel_torque_driver
```

**测试发布器：**
```bash
ros2 run my_robot_pkg simple_vel_publisher
```

#### 3. 手动发送速度命令
```bash
# 前进
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist '{linear: {x: 0.5, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}'

# 转弯
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist '{linear: {x: 0.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.0}}'

# 停止
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist '{linear: {x: 0.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}'
```

## 📊 调试信息

### 查看轮子调试信息
```bash
ros2 topic echo /wheel_debug
```

### 监视话题
```bash
# 查看所有话题
ros2 topic list

# 监视速度命令
ros2 topic echo /cmd_vel

# 查看Gazebo服务
ros2 service list | grep gazebo
```

## 🔧 技术细节

### 控制系统架构
1. **键盘输入** → **转矩计算** → **ApplyLinkWrench服务**
2. **速度命令** → **PID控制** → **转矩输出** → **ApplyLinkWrench服务**

### 坐标系统
- 机器人模型名称: `bipedal_4`
- 左轮链接: `bipedal_4::Lwheel_Link`
- 右轮链接: `bipedal_4::Rwheel_Link`
- 转矩方向: Y轴（轮子旋转轴）

### 差分驱动运动学
```cpp
// 速度到轮子速度的转换
left_wheel_vel = (linear_vel - angular_vel * wheel_separation / 2) / wheel_radius
right_wheel_vel = (linear_vel + angular_vel * wheel_separation / 2) / wheel_radius
```

## ⚠️ 注意事项

1. **依赖关系**: 确保安装了 `ros-humble-gazebo-msgs`
2. **权限**: 键盘控制器需要终端输入权限
3. **Gazebo版本**: 需要支持Ignition Gazebo和ApplyLinkWrench服务
4. **服务可用性**: 控制器会检查Gazebo服务是否就绪
5. **安全超时**: 轮子驱动器有500ms的命令超时保护

## 🎮 使用建议

1. **首次使用**: 从键盘控制模式开始测试
2. **调试**: 使用测试速度发布器验证系统工作
3. **参数调优**: 根据实际机器人调整PID参数和物理参数
4. **性能监视**: 观察调试话题了解控制效果
