#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/float64_multi_array.hpp"
#include <chrono>

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node {
public:
    PublisherNode() : Node("publisher_node"), count_(0) {
        publisher_ = this->create_publisher<example_interfaces::msg::Float64MultiArray>("length_top", 10);
        timer_ = this->create_wall_timer(1s, std::bind(&PublisherNode::timer_callback, this));
    }
private:
    void timer_callback() {
        auto message = example_interfaces::msg::Float64MultiArray();
       
        if (count_ % 3 == 0) {
            message.data = {10.0, 20.0, 30.0};
            RCLCPP_INFO(this->get_logger(), "发送数据: 10.0, 20.0, 30.0");
        } else if (count_ % 3 == 1) {
            message.data = {}; 
            RCLCPP_INFO(this->get_logger(), "发送空数组");
        } else {
            message.data = {5.0, 15.0, 25.0, 35.0};
            RCLCPP_INFO(this->get_logger(), "发送数据: 5.0, 15.0, 25.0, 35.0");
        }
        publisher_->publish(message);
        count_++;
    }
    rclcpp::Publisher<example_interfaces::msg::Float64MultiArray>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;
}
