# unitree_go2_code_01
learning about unitree_go2 from zhaoxuzuo &amp;code reflection

Go2 官方 SDK2 用的是 `unitree_api` / `unitree_go` 这套私有消息，跟 ROS 生态里的 `cmd_vel`、`odom`、`joint_states` 不通用。这个仓库补的是中间那一层——把狗接成一块标准 ROS 2 底盘，让 rviz2、键盘遥控、`cmd_vel` 发布者和上层导航框架能直接拿来用。

## 环境

| 项    | 版本                                        |
| ----- | ------------------------------------------- |
| 系统  | Ubuntu 22.04                                |
| ROS 2 | Humble                                      |
| SDK   | Unitree SDK2（`unitree_api`、`unitree_go`） |
| 构建  | ament_cmake（C++17）/ ament_python          |

`unitree_api`、`unitree_go` 来自 Unitree 官方 SDK2，需按官方文档单独编译安装，本仓库不含这两套消息的定义。

## 编译

```bash
mkdir -p ~/go2_ws/src
cd ~/go2_ws/src
git clone https://github.com/fallenwater/unitree_go2_code_01.git
cd ..
colcon build
source install/setup.bash
```

仓库里带了 `build/`、`install/`、`log/` 三个目录，是本机编译残留，先删掉再 build，否则路径对不上会报错。

## 包结构

| 包                         | 语言       | 作用                                                |
| -------------------------- | ---------- | --------------------------------------------------- |
| `go2_description`          | urdf / dae | Go2 模型与 `display.launch.py` 可视化               |
| `go2_driver`               | C++        | 订阅狗的状态话题，转成 `odom`、`joint_states` 和 TF |
| `go2_driver_py`            | Python     | 同上，Python 实现                                   |
| `go2_twist_bridge`         | C++        | `cmd_vel` → `unitree_api/Request`                   |
| `go2_twist_bridge_py`      | Python     | 同上，Python 实现                                   |
| `go2_teleop_ctrl_keyboard` | Python     | 键盘遥控，支持全向移动与调速                        |
| `go2_tutorial_inter`       | msg        | 自定义 `Cruising.srv`、`Nav.action`                 |
| `go2_tutorial`             | C++        | 巡航 client / service、控制与状态读取示例           |

`src/helloworld`、`src/test` 是 ROS 2 建包时的脚手架，可以忽略。

## 话题接口

| 方向 | 话题                 | 类型                        | 说明                                 |
| ---- | -------------------- | --------------------------- | ------------------------------------ |
| 订阅 | `cmd_vel`            | `geometry_msgs/Twist`       | 线速度 x/y，角速度 z                 |
| 发布 | `/api/sport/request` | `unitree_api/Request`       | 运动指令，`parameter` 为 JSON 字符串 |
| 订阅 | `lf/sportmodestate`  | `unitree_go/SportModeState` | 位置、姿态、速度                     |
| 订阅 | `lf/lowstate`        | `unitree_go/LowState`       | 12 个关节的角度等低层状态            |
| 发布 | `odom`               | `nav_msgs/Odometry`         | 由 `sportmodestate` 转换             |
| 发布 | `joint_states`       | `sensor_msgs/JointState`    | 由 `lowstate` 转换                   |
| 发布 | TF `odom → base`     | `tf2`                       | 由参数 `publish_tf` 控制             |

```
cmd_vel ──► twist_bridge ──► /api/sport/request ──► Go2

Go2 ──► lf/sportmodestate ──► driver ──► odom + TF(odom→base)
Go2 ──► lf/lowstate ────────► driver ──► joint_states
```

## 使用

**1. 模型与键盘遥控**

```bash
ros2 launch go2_teleop_ctrl_keyboard go2_teleop_ctrl_keyboard.launch.py
```

`w/s` 前后，`a/d` 左右转；按住 Shift 进全向模式，可横移（`q/e/z/c`）。`r/t` 同时调线速度与角速度，`f/g` 只调线速度，`v/b` 只调角速度。遥控节点直接发 `unitree_api/Request`，不经 `cmd_vel`。

**2. 里程计、关节状态与 TF**

```bash
ros2 launch go2_driver driver.launch.py
ros2 topic echo /odom --no-arr
```

参数：`odom_frame`（默认 `odom`）、`base_frame`（默认 `base`）、`publish_tf`（默认 `true`）。接外部定位时把 `publish_tf` 置 `false`，避免两处抢同一个 TF。

**3. 用 cmd_vel 驱动**

```bash
ros2 run go2_twist_bridge twist_bridge
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.3}}"
```

收到全零速度时下发 `BALANCESTAND`（站立），非零时下发 `MOVE`，`x/y/z` 用 `nlohmann::json` 序列化进 `Request.parameter`。

**4. 巡航接口**

`Cruising.srv`：请求 `int32 flag`，响应 `geometry_msgs/Point`。
`Nav.action`：目标 `float32`（前进距离），结果 `geometry_msgs/Point`，反馈 `float32`（剩余距离）。

用 client / service 的示例在 `src/tutorial/go2_tutorial`，对应四个 launch：`go2_all_start`、`go2_cruising`、`go2_ctrl`、`go2_state`。

## 已知限制

- 只封装到运动接口层，没有接 Nav2 和 SLAM。`Nav.action` 目前是接口定义加示例，不是完整的导航实现。
- `odom` 直接转发机器狗内部里程计，没有融合外部定位，长时间运行会累积漂移。
- 角速度只透传了 `yaw_speed`，roll / pitch 方向未填，做机体姿态控制时要另外取 `imu_state`。
- 没有写 QoS 配置，全部用默认值。

## 参考

- [Unitree SDK2](https://github.com/unitreerobotics/unitree_sdk2)
- [unitree_ros2](https://github.com/unitreerobotics/unitree_ros2)
