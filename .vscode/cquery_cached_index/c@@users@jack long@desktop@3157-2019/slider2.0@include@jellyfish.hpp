#pragma once
#include "main.h"
#include "drive.hpp"

class Jellyfish{
private:
  Jellyfish();
public:
  //okapi::ChassisController& jelly;
  std::shared_ptr<Drive> drive;
  static Jellyfish* getInstance();
  void opControl(pros::Controller& joystick);
  void intake(pros::Controller& joystick);
  void arm(pros::Controller& joystick);
  void angler(pros::Controller& joystick);
  void starter(pros::Controller& joystick);
};
