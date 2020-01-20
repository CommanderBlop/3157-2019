#include "main.h"
#include "okapi/api.hpp"
#include "jellyfish.hpp"

Jellyfish::Jellyfish(){
  armMotor = std::make_shared<okapi::Motor> (okapi::Motor(10, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees));
  anglerMotor = std::make_shared<okapi::Motor> (okapi::Motor(9, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees));
  intakeMotors = std::make_shared<okapi::MotorGroup> (okapi::MotorGroup({okapi::Motor(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
					 okapi::Motor(2, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)}));
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
  if(L1 && armMotor->getPosition() > 50) {
    armMotor->moveVelocity(90);
  } else if(L2 && armMotor->getPosition() > 50) {
    armMotor->moveVelocity(-90);
  } else {
    armMotor->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  }
}

void Jellyfish::angler(pros::Controller &joystick) {
  int anglerPower = joystick.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if(anglerPower > -10 && anglerPower < 10 ) anglerPower = 0;
  if(anglerMotor->getPosition() > 50 && anglerMotor->getPosition() < ANGLER_MID) anglerMotor->moveVelocity(anglerPower * 0.7);
  else if(anglerMotor->getPosition() > ANGLER_MID && anglerMotor->getPosition() < ANGLER_MAX) anglerMotor->moveVelocity(anglerPower * 0.3);
  else if(anglerMotor->getPosition() >= ANGLER_MAX && anglerPower < 0) anglerMotor->moveVelocity(anglerPower * 0.3);
  else if(anglerMotor->getPosition() <= ANGLER_MIN && anglerPower > 0) anglerMotor->moveVelocity(anglerPower * 0.7);
  else anglerMotor->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
}

void Jellyfish::intake(pros::Controller &joystick) {

}

void Jellyfish::starter(pros::Controller &joystick) {

}
