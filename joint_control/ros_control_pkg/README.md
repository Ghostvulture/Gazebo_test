# Bipedal Robot Balance Control with ROS + Gazebo

这是一个使用ROS和Gazebo实现双足机器人平衡控制的项目，专注于通过轮子的PID控制实现差速驱动平衡。

## 项目概述

### 技术架构
```
ROS节点 ←→ Gazebo仿真 ←→ SDF机器人模型
   ↓           ↓              ↓
PID控制器  ← IMU传感器 →   关节控制器
```

### 控制策略
- **主要控制目标**: 通过轮子差速驱动维持机器人直立平衡
- **传感器**: IMU提供姿态反馈 (pitch角度和角速度)
- **执行器**: 左右轮子关节扭矩控制
- **控制算法**: PID平衡控制 + 速度前馈控制

## 项目结构

```
ros_control_pkg/
├── CMakeLists.txt                 # CMake构建配置
├── package.xml                    # ROS包定义
├── test_control.sh               # 测试脚本 ⭐
├── src/
│   ├── wheel_pid_controller.cpp   # C++版本PID控制器
│   └── balance_controller.py      # Python版本平衡控制器 ⭐
├── launch/
│   ├── balance_control.launch     # 完整系统启动文件
│   └── simple_balance_test.launch # 简单测试启动文件
├── config/
│   └── control_params.yaml       # 控制参数配置 ⭐
└── README.md                      # 本文档
```

## 快速开始

### 1. 环境准备
```bash
# 确保ROS已安装并sourced
source /opt/ros/humble/setup.bash  # 或者你的ROS版本

# 确保Ignition Gazebo已安装
ign gazebo --version
```

### 2. 构建项目
```bash
cd ros_control_pkg
./test_control.sh build
source ~/catkin_ws/devel/setup.bash
```

### 3. 运行仿真和控制

#### 方法1: 分步运行 (推荐用于调试)
```bash
# 终端1: 启动Gazebo仿真
./test_control.sh sim

# 终端2: 启动ROS核心
roscore

# 终端3: 启动平衡控制器
./test_control.sh control
```

#### 方法2: 一键启动
```bash
./test_control.sh full
```

### 4. 测试控制
```bash
# 另开终端进行手动控制测试
./test_control.sh test
```

## 控制器详解

### Python平衡控制器 (balance_controller.py) ⭐

**特点**:
- 主要用于平衡控制的PID实现
- 易于参数调试和修改
- 包含安全保护机制

**核心功能**:
```python
# 平衡控制PID
error = target_angle - current_pitch
balance_output = kp * error + ki * integral + kd * derivative

# 差速驱动计算
left_torque = balance_output + velocity_command + steering_torque
right_torque = balance_output + velocity_command - steering_torque
```

**订阅话题**:
- `/imu/data` (sensor_msgs/Imu) - IMU传感器数据
- `/cmd_vel` (geometry_msgs/Twist) - 速度命令

**发布话题**:
- `/model/bipedal_4/joint/Lwheel_joint/cmd_force` - 左轮扭矩
- `/model/bipedal_4/joint/Rwheel_joint/cmd_force` - 右轮扭矩

### C++轮子控制器 (wheel_pid_controller.cpp)

**特点**:
- 更高性能的实现
- 完整的PID控制和速度控制
- 适合生产环境

## 参数调优指南

### 关键参数 (config/control_params.yaml)

```yaml
balance_controller:
  # 平衡PID参数
  balance_kp: 25.0    # 比例增益 - 主要影响响应速度
  balance_ki: 1.0     # 积分增益 - 消除稳态误差
  balance_kd: 4.0     # 微分增益 - 提供阻尼，防止震荡
  
  # 物理参数
  wheel_base: 0.33    # 轮距
  max_torque: 12.0    # 最大扭矩限制
```

### 参数调试步骤

1. **启动系统并观察**:
   ```bash
   ./test_control.sh full
   # 观察机器人是否能够保持直立
   ```

2. **如果机器人倾倒**:
   - 增加 `balance_kp` (比例增益)
   - 检查 `max_torque` 是否足够

3. **如果震荡严重**:
   - 增加 `balance_kd` (微分增益)
   - 减少 `balance_kp`

4. **如果有稳态误差**:
   - 增加 `balance_ki` (积分增益)
   - 注意防止积分饱和

### 实时参数调整
修改 `config/control_params.yaml` 后重启控制器即可生效。

## 开发Pipeline

### 典型开发流程
```
1. 修改控制算法 → 2. 测试仿真 → 3. 参数调优 → 4. 验证性能
      ↓                ↓               ↓              ↓
balance_controller.py → Gazebo → control_params.yaml → 测试脚本
```

### 调试工具

1. **实时监控**:
   ```bash
   # 监控轮子扭矩输出
   rostopic echo /model/bipedal_4/joint/Lwheel_joint/cmd_force
   
   # 监控IMU数据
   rostopic echo /imu/data
   ```

2. **手动命令**:
   ```bash
   # 发送速度命令
   rostopic pub /cmd_vel geometry_msgs/Twist "linear: {x: 0.1, y: 0, z: 0}" -1
   ```

3. **可视化**:
   - Gazebo中观察机器人行为
   - 通过RViz查看TF树和传感器数据

## 扩展开发

### 添加新功能

1. **传感器集成**:
   ```cpp
   // 在SDF中添加新传感器
   <sensor name="camera" type="camera">
     ...
   </sensor>
   ```

2. **控制算法优化**:
   ```python
   # 在balance_controller.py中添加新控制逻辑
   def advanced_control_algorithm(self):
       # 实现更复杂的控制策略
   ```

3. **参数动态调整**:
   ```bash
   # 使用rosparam动态修改参数
   rosparam set /balance_controller/balance_kp 30.0
   ```

### 集成其他控制器

可以轻松添加其他关节的控制器:
```python
# 添加腿部关节控制
leg_pub = rospy.Publisher('/model/bipedal_4/joint/Lbig_joint/cmd_force', Float64)
```

## 故障排除

### 常见问题

1. **机器人无法保持直立**:
   - 检查IMU数据是否正常
   - 调整PID参数
   - 验证扭矩限制

2. **控制响应延迟**:
   - 检查控制频率设置
   - 优化控制算法

3. **仿真不稳定**:
   - 减少物理时间步长
   - 调整质量和惯量参数

### 调试命令
```bash
# 检查ROS节点状态
rosnode list
rosnode info /balance_controller

# 检查话题通信
rostopic list
rostopic hz /imu/data

# 检查参数设置
rosparam list
rosparam get /balance_controller/balance_kp
```

## 性能指标

### 评估标准
- **平衡时间**: 从初始倾斜到稳定直立的时间
- **稳态误差**: 稳定后的角度偏差
- **响应速度**: 对外部扰动的恢复时间
- **能耗**: 控制所需的平均扭矩

### 基准参数
- 平衡时间: < 3秒
- 稳态误差: < 2度
- 最大倾斜角: < 15度 (不倾倒)

---

## 开发团队支持

如有问题，请检查:
1. ROS环境是否正确配置
2. Gazebo插件是否加载
3. IMU传感器数据是否正常
4. 参数设置是否合理

祝你开发顺利！🚀
