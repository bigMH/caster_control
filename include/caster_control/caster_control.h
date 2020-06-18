#ifndef CASTER_CONTROL_H
#define CASTER_CONTROL_H

#include <ros/ros.h>
#include <ros/duration.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <move_base_msgs/MoveBaseAction.h>

namespace caster_control {
  class CasterControl {

  private:
    std::string flag_;
    move_base_msgs::MoveBaseGoal goal_;
    // actionlib::SimpleClientGoalState state_;
    actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> caster_client_;

  public:
    CasterControl(ros::NodeHandle& nh_);
    ~CasterControl();
    int getCasterGoal();
    int waitCasterArrived();
  };
}
#endif