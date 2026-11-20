#构建运行的命令
```bash
cd work1
mkdir build
cd build
cmake ..
make
./main_app
```
#ROS2部分
##发布节点
### 节点名
publisher_node
### 话题名
length_top
### 消息类型
example_interfaces/msg/Float64MultiArray
### 输出内容
* 发送数据: 10.0, 20.0, 30.0
* 发送空数组
* 发送数据: 5.0, 15.0, 25.0, 35.0
##订阅者
###节点名
subscriber_node
###话题名
length_top
###发布话题名
mean_topic
###消息类型
example_interfaces/msg/Float64
###输出内容
* 计算并发布均值: 20.000000
* 收到空数组，不发布均值
* 计算并发布均值: 20.000000
#为什么空数组的均值不能返回 0？
返回数值0也有意义  空数组返回的0不能确定结果确实为0还是空数组 为了避免出现这种歧义 所以会使用nullopt来表示空数组
#遇到的问题以及解决方案
**ROS 2 编译时找不到自定义头文件 (`my_ros_pkg/func.h: No such file or directory`)**
 *   **原因**：在套用 ROS 2 官方发布订阅模板时，没有在 `CMakeLists.txt` 中配置包含路径，导致编译器找不到本地的 `.h` 文件
 *   **解决**：在 `CMakeLists.txt` 中添加了 `include_directories(include)`，告诉编译器去 `include` 目录下找头文件
**移植代码时，ROS 消息类型与原生 C++ 数据类型不匹配**
 *   **原因**：ROS 2 发来的数据是 `Float64MultiArray` 消息对象，不能直接传给 C++ 的 `vector`
 *   **解决**：在订阅者的回调函数中，使用 `std::vector<double> lengths(msg->data.begin(), msg->data.end());
