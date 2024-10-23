#include "navigate_to_pose_action.hpp"
#include "behaviortree_ros2/plugins.hpp"

bool NavigateToPoseActionBT::setGoal(RosActionNode::Goal & goal)
{
  // auto goal_blackboard_ = getInput<geometry_msgs::msg::PoseStamped>("goal");
  // goal.pose = *goal_blackboard_;
  goal.pose.header.frame_id = "map";
  goal.pose.pose.position.x = 0.0;
  goal.pose.pose.position.y = 0.5;
  return true;
}

NodeStatus NavigateToPoseActionBT::onResultReceived(const RosActionNode::WrappedResult & wr)
{
//   RCLCPP_INFO(logger(), "%s: onResultReceived. Done = %s", name().c_str(),
//               wr.result->done ? "true" : "false");
  switch (wr.code) {
    case rclcpp_action::ResultCode::SUCCEEDED:
      return NodeStatus::SUCCESS;
    case rclcpp_action::ResultCode::CANCELED:
      RCLCPP_ERROR(logger(), "Goal was canceled");
      return NodeStatus::SUCCESS;
    case rclcpp_action::ResultCode::ABORTED:
      RCLCPP_ERROR(logger(), "Goal was aborted");
      return NodeStatus::FAILURE;
    default:
      RCLCPP_ERROR(logger(), "Unknown result code");
      return NodeStatus::FAILURE;
  }
}

NodeStatus NavigateToPoseActionBT::onFailure(ActionNodeErrorCode error)
{
  RCLCPP_ERROR(logger(), "%s: onFailure with error: %s", name().c_str(), toStr(error));
  return NodeStatus::FAILURE;
}

void NavigateToPoseActionBT::onHalt()
{
  RCLCPP_INFO(logger(), "%s: onHalt", name().c_str());
}

// Plugin registration.
// The class NavigateToPoseActionBT will self register with name  "NavigateToPoseActionBT".
CreateRosNodePlugin(NavigateToPoseActionBT, "NavigateToPoseActionBT");
