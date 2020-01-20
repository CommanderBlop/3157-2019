#include "main.h"
#include "okapi/api.hpp"
#include "jellyfish.hpp"

Jellyfish::Jellyfish(){
  okapi::MotorGroup RightMotors({19,-20});
  okapi::MotorGroup LeftMotors({-11,12});
  drive = std::make_shared<Drive>();
}

Jellyfish* Jellyfish::getInstance() {
  static Jellyfish* instance;
  return instance;
}

void Jellyfish::opControl(pros::Controller& joystick) {
  drive->opControlDrive(joystick);
  arm(joystick);
  angler(joystick);
}

void Jellyfish::arm(pros::Controller& joystick) {
  int L1 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  int L2 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  if(L1 && ArmMotor.getPosition() > 50) {
    ArmMotor.moveVelocity(90);
  } else if(L2 && ArmMotor.getPosition() > 50) {
    ArmMotor.moveVelocity(-90);
  } else {
    ArmMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  }
}

void Jellyfish::angler(pros::Controller &joystick) {
  int anglerPower = joystick.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if(anglerPower > - 10 && anglerPower < 10 ) anglerPower = 0;
  if(AnglerMotor.getPosition() > 50 && AnglerMotor.getPosition() < ANGLER_MID) AnglerMotor.moveVelocity(anglerPower * 0.7);
  else if(AnglerMotor.getPosition() > ANGLER_MID && AnglerMotor.getPosition() < ANGLER_MAX) AnglerMotor.moveVelocity(anglerPower * 0.3);
  else if(AnglerMotor.getPosition() >= ANGLER_MAX && anglerPower < 0) AnglerMotor.moveVelocity(anglerPower * 0.3);
  else if(AnglerMotor.getPosition() <= ANGLER_MIN && anglerPower > 0) AnglerMotor.moveVelocity(anglerPower * 0.7);
  else AnglerMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}

void Jellyfish::intake(pros::Controller &joystick) {

}

void Jellyfish::starter(pros::Controller &joystick) {

}
