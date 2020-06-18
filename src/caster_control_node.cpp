#include <caster_control/caster_control.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "caster_controller");
  ros::NodeHandle node;

  caster_control::CasterControl controller(node);
  ROS_INFO("May be right.");
  while(ros::ok()){
    controller.getCasterGoal();
    controller.waitCasterArrived();
  }
  return 0;
}