#include <chrono>
#include <memory>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
      : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    timer_ = this->create_wall_timer(
        20ms, std::bind(&MinimalPublisher::timer_callback, this));
    msg_.name.push_back("Joint00");
    msg_.name.push_back("Joint01");
    msg_.position.push_back(0.0);
    msg_.position.push_back(0.0);
  }

private:
  void timer_callback()
  {
    msg_.header.stamp = ros_clock_.now();
    msg_.position[0] = std::sin(count_ * 0.01);
    msg_.position[1] = std::sin(count_ * 0.02);
    count_++;
    publisher_->publish(msg_);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_;
  rclcpp::Clock ros_clock_;
  sensor_msgs::msg::JointState msg_;
  size_t count_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
