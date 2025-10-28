# 完整的反馈包
std_msgs/Header header

# 六个电机的反馈 [Lwheel, Rwheel, Lbig, Lsmall, Rbig, Rsmall]
MotorFeedback[] motors

# IMU数据
geometry_msgs/Vector3 angular_velocity    # 角速度 (rad/s)
geometry_msgs/Vector3 linear_acceleration # 线性加速度 (m/s²)
