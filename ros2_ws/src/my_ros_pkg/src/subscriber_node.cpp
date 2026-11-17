#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/float64_multi_array.hpp"
#include "example_interfaces/msg/float64.hpp"
#include "my_ros_pkg/func.h" 

class SubscriberNode : public rclcpp::Node {
public:
    SubscriberNode() : Node("subscriber_node") {
       
        publisher_ = this->create_publisher<example_interfaces::msg::Float64>("mean_topic", 10);
        subscription_ = this->create_subscription<example_interfaces::msg::Float64MultiArray>(
            "length_top", 10, std::bind(&SubscriberNode::topic_callback, this, std::placeholders::_1));
    }
private:
    void topic_callback(const example_interfaces::msg::Float64MultiArray::SharedPtr msg) {
        
        std::vector<double> lengths(msg->data.begin(), msg->data.end());
        
        
        auto result = meanlength(lengths);
        
        if (!result.has_value()) {
            RCLCPP_INFO(this->get_logger(), "收到空数组，不发布均值。");
            return;
        }
        
        auto mean_msg = example_interfaces::msg::Float64();
        mean_msg.data = result.value();
        publisher_->publish(mean_msg);
        RCLCPP_INFO(this->get_logger(), "计算并发布均值: %f", mean_msg.data);
    }
    rclcpp::Publisher<example_interfaces::msg::Float64>::SharedPtr publisher_;
    rclcpp::Subscription<example_interfaces::msg::Float64MultiArray>::SharedPtr subscription_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubscriberNode>());
    rclcpp::shutdown();
    return 0;
}
