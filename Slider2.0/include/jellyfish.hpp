#pragma once
#include "main.h"
#include "drive.hpp"

class Jellyfish{
private:
  Jellyfish();
public:
  //okapi::ChassisController& jelly;
  std::shared_ptr<Drive> drive;
  std::shared_ptr<okapi::Motor> armMotor;
  std::shared_ptr<okapi::Motor> anglerMotor;
  std::shared_ptr<MotorGroup> intakeMotors;
  int ANGLER_MID = 2000;
  int ANGLER_MAX = 3000;
  int ANGLER_MIN = 50;

  static Jellyfish* getInstance();
  void opControl(pros::Controller& joystick);
  void intake(pros::Controller& joystick);
  void arm(pros::Controller& joystick);
  void angler(pros::Controller& joystick);
  void starter(pros::Controller& joystick);
};
