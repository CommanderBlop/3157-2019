#pragma once
#include "main.h"
#include "drive.hpp"

class Jellyfish{
private:

  Jellyfish(); //singleton setup
public:
  //there's no point setting pointer for these devices, but don't change. too much work
  static Jellyfish* robot;
  std::shared_ptr<Drive> drive;
  // std::shared_ptr<okapi::Motor> armMotor;
  std::shared_ptr<okapi::Motor> anglerMotor;
  // std::shared_ptr<MotorGroup> intakeMotors;

  //angler preset values
  int ANGLER_MID = 450;
  int ANGLER_MAX = 710;
  int ANGLER_MIN = 50;
  int ARM_MIN = 50;
  int ARM_MAX = 2000;

  //Jellyfish functions
  static Jellyfish* getInstance();
  void opControl(pros::Controller& joystick);
  void intake(pros::Controller& joystick);
  void arm(pros::Controller& joystick);
  void angler(pros::Controller& joystick);
};
