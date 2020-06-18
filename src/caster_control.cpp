#include <caster_control/caster_control.h>

namespace caster_control {
  
  CasterControl::CasterControl(ros::NodeHandle& nh_)
  :caster_client_(nh_, "move_base", true)
  {
    ROS_INFO("Waits for the ActionServer to connect to this client.");
    caster_client_.waitForServer();
    goal_.target_pose.pose.position.z = 0;
    goal_.target_pose.header.frame_id = "map";
  }

  CasterControl::~CasterControl() {

  }

  int CasterControl::getCasterGoal() {
    ROS_INFO("Please enter the pose.");
    ROS_INFO("Please enter the X coordinates");
    std::cin >> goal_.target_pose.pose.position.x;
    ROS_INFO("Please enter the Y coordinates");
    std::cin >> goal_.target_pose.pose.position.y;
    ROS_INFO("Please enter the orientation: X");
    std::cin >> goal_.target_pose.pose.orientation.x;
    ROS_INFO("Please enter the orientation: Y");
    std::cin >> goal_.target_pose.pose.orientation.y;
    ROS_INFO("Please enter the orientation: Z");
    std::cin >> goal_.target_pose.pose.orientation.z;
    ROS_INFO("Please enter the orientation: W");
    std::cin >> goal_.target_pose.pose.orientation.w;

    caster_client_.sendGoal(goal_);

    return 0;
  }

  int CasterControl::waitCasterArrived() {
    ROS_INFO("WAit for caster to arrive.");
    caster_client_.waitForResult(ros::Duration(60.0));
    ROS_INFO("The caster has arrived.");
    return 0;  
  }
}