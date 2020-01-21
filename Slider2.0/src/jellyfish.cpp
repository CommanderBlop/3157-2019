#include "main.h"
#include "okapi/api.hpp"
#include "jellyfish.hpp"

Jellyfish::Jellyfish(){
  // armMotor = std::make_shared<okapi::Motor> (okapi::Motor(10, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees));
  anglerMotor = std::make_shared<okapi::Motor> (okapi::Motor(1, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees));
  // intakeMotors = std::make_shared<okapi::MotorGroup> (okapi::MotorGroup({okapi::Motor(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
	// 				 okapi::Motor(2, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)}));
  drive = std::make_shared<Drive>();
}

Jellyfish* Jellyfish::robot = NULL;
Jellyfish* Jellyfish::getInstance() {
  if(Jellyfish::robot == NULL) {
    Jellyfish::robot = new Jellyfish();
  }
  return Jellyfish::robot;
}

void Jellyfish::opControl(pros::Controller& joystick) { //the function that starts it all
  // pros::lcd::print(0, "arm:%f, angler:%f", armMotor->getPosition(), anglerMotor->getPosition());
  // pros::lcd::print(1, "odometry coordinate:%s", drive->chassis->getState());
  // pros::lcd::print(2, "OwO UwU OwO UwU OwO UwU OwO UwU");
  drive->opControlDrive(joystick);
  // arm(joystick);
  angler(joystick);
  // intake(joystick);
}

// void Jellyfish::arm(pros::Controller& joystick) {
//   int R1 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
//   int R2 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
//   if(R1 && armMotor->getPosition() < ARM_MAX) {
//     armMotor->moveVelocity(90);
//   } else if(R2 && armMotor->getPosition() > ARM_MIN) {
//     armMotor->moveVelocity(-90);
//   } else {
//     armMotor->moveVelocity(0);
//     armMotor->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
//   }
// }
//
void Jellyfish::angler(pros::Controller &joystick) {
  double anglerPower = (double) joystick.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if(anglerPower > -10 && anglerPower < 10 ) anglerPower = 0.0;
  if(anglerMotor->getPosition() > ANGLER_MIN && anglerMotor->getPosition() < ANGLER_MID) anglerMotor->moveVelocity(anglerPower*0.7);
  else if(anglerMotor->getPosition() > ANGLER_MID && anglerMotor->getPosition() < ANGLER_MAX) anglerMotor->moveVelocity(anglerPower * 0.3);
  else if(anglerMotor->getPosition() >= ANGLER_MAX && anglerPower < 0) anglerMotor->moveVelocity(anglerPower * 0.3);
  else if(anglerMotor->getPosition() <= ANGLER_MIN && anglerPower > 0) anglerMotor->moveVelocity(anglerPower*0.7);
  else {
    anglerMotor->moveVelocity(0);
    anglerMotor->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  }

}
//
// void Jellyfish::intake(pros::Controller &joystick) {
//   int L1 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
//   int L2 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
//   if(L1) {
//     intakeMotors->moveVelocity(90);
//   } else if(L2) {
//     intakeMotors->moveVelocity(-90);
//   } else if(anglerMotor->getPosition() >= ANGLER_MID){
//     intakeMotors->moveVelocity(0);
//     intakeMotors->setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
//   } else {
//     intakeMotors->moveVelocity(0);
//     intakeMotors->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
//   }
// }
