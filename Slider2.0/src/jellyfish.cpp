#include "main.h"
#include "okapi/api.hpp"
#include "jellyfish.hpp"

Jellyfish::Jellyfish(){
  // armMotor = std::make_shared<okapi::Motor> (okapi::Motor(5, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees));
  anglerMotor = std::make_shared<okapi::Motor> (okapi::Motor(17, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees));
  intakeMotors = std::make_shared<okapi::MotorGroup> (okapi::MotorGroup({okapi::Motor(1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
					 okapi::Motor(2, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)}));
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
  drive->opControlDrive(joystick);
  // arm(joystick);
  angler(joystick);
  intake(joystick);
}

// void Jellyfish::arm(pros::Controller& joystick) {
//   int R1 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
//   int R2 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
//   if(R1 && armMotor->getPosition() < ARM_MAX) {
//     // armMotor->moveVelocity(70);
//   } else if(R2 && armMotor->getPosition() > ARM_MIN) {
//     // armMotor->moveVelocity(-70);
//   } else {
//     armMotor->moveVelocity(0);
//     armMotor->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
//   }
// }

void Jellyfish::angler(pros::Controller &joystick) {
  double anglerPower = (double) joystick.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if(anglerPower > -10 && anglerPower < 10 ) anglerPower = 0.0;
  int pos = (int) anglerMotor->getPosition();
  if(pos < ANGLER_MIN) {
    if(anglerPower > 0) {
      anglerMotor->moveVelocity(anglerPower);
    } else {
       anglerMotor->moveVelocity(0);
    }
  } else if(pos >= ANGLER_MIN && pos <= ANGLER_MID) {
    anglerMotor->moveVelocity(anglerPower*0.7);
  } else if(pos > ANGLER_MID && pos < ANGLER_MAX) {
    if(anglerPower > 0) {
      anglerMotor -> moveVelocity(anglerPower*((820-anglerMotor->getPosition())/760));
    } else {
      anglerMotor -> moveVelocity(anglerPower * 0.7);
    }
  } else if(pos >= ANGLER_MAX){
    if(anglerPower < 0) {
      anglerMotor -> moveVelocity(anglerPower * 0.7);
    }  else {
       anglerMotor->moveVelocity(0);
    }
  } else {
    anglerMotor->moveVelocity(0);
    anglerMotor->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  }

  // if(anglerMotor->getPosition() > ANGLER_MIN && anglerMotor->getPosition() < ANGLER_MID && anglerMotor->getPosition()>0) anglerMotor->moveVelocity(anglerPower*((800-anglerMotor->getPosition())/760));
  // else if(anglerMotor->getPosition() > ANGLER_MID && anglerMotor->getPosition() < ANGLER_MAX && anglerMotor->getPosition()>0) anglerMotor->moveVelocity(anglerPower*((800-anglerMotor->getPosition())/760));
  // else if(anglerMotor->getPosition() > ANGLER_MID && anglerMotor->getPosition() < ANGLER_MAX && anglerMotor->getPosition()>0) anglerMotor->moveVelocity(anglerPower*((800-anglerMotor->getPosition())/760));
  // else if(anglerMotor->getPosition() > ANGLER_MID && anglerMotor->getPosition() < ANGLER_MAX && anglerMotor->getPosition()<0) anglerMotor->moveVelocity(anglerPower*0.7);
  // else if(anglerMotor->getPosition() >= ANGLER_MAX && anglerPower < 0) anglerMotor->moveVelocity(anglerPower*0.7);
  // else if(anglerMotor->getPosition() <= ANGLER_MIN && anglerPower > 0) anglerMotor->moveVelocity(anglerPower*((800-anglerMotor->getPosition())/760));
  // else {
  //   anglerMotor->moveVelocity(0);
  //   anglerMotor->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  // }
}

void Jellyfish::intake(pros::Controller &joystick) {
  int L1 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
  int L2 = joystick.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
  if(L1) {
    intakeMotors->moveVelocity(210);
  } else if(L2) {
    intakeMotors->moveVelocity(-210);
  }else {
    intakeMotors->moveVelocity(0);
    intakeMotors->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  }
}

void Jellyfish::autonRed() {
  drive->chassis->setMaxVelocity(60);
  intakeMotors->moveVelocity(190);
  drive->chassis->moveDistance(40.5_in);
  pros::delay(200);
  intakeMotors->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  intakeMotors->moveVelocity(0);
  drive->chassis->setMaxVelocity(80);
  drive->chassis->moveDistance(-24_in);
  pros::delay(200);
  drive->chassis->setMaxVelocity(50);
  drive->chassis->turnAngle(130_deg);
  pros::delay(200);
  drive->chassis->moveDistance(12_in);

  //stacking
  while(anglerMotor->getPosition() < ANGLER_MAX) {
    anglerMotor->moveVelocity(100*((820-anglerMotor->getPosition())/760));

  }
  anglerMotor->moveVelocity(0);
  drive->chassis->moveDistance(-5_in);
  drive->chassis->setMaxVelocity(200);
}

void Jellyfish::autonBlue() {
  drive->chassis->setMaxVelocity(60);
  intakeMotors->moveVelocity(190);
  drive->chassis->moveDistance(34_in);
  pros::delay(200);
  intakeMotors->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  intakeMotors->moveVelocity(0);
  drive->chassis->setMaxVelocity(80);
  drive->chassis->moveDistance(-18_in);
  pros::delay(200);
  drive->chassis->setMaxVelocity(50);
  drive->chassis->turnAngle(-130_deg);
  pros::delay(200);
  drive->chassis->moveDistance(12_in);
  //
  // drive->chassis->setMaxVelocity(80);
  // intakeMotors->moveVelocity(180);
  // drive->chassis->moveDistance(40.5_in);
  // pros::delay(200);
  // drive->chassis->turnAngle(30_deg);
  // drive->chassis->setMaxVelocity(55);
  // drive->chassis->moveDistance(4.5_in);
  // drive->chassis->moveDistance(-4.5_in);
  // intakeMotors->setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
  // intakeMotors->moveVelocity(0);
  // drive->chassis->turnAngle(-177_deg);
  // pros::delay(200);
  // drive->chassis->setMaxVelocity(120);
  // drive->chassis->moveDistance(45_in);
  // pros::delay(200);

  //stacking
  while(anglerMotor->getPosition() < ANGLER_MAX) {
    anglerMotor->moveVelocity(100*((820-anglerMotor->getPosition())/760));

  }
  anglerMotor->moveVelocity(0);
  drive->chassis->moveDistance(-5_in);
  drive->chassis->setMaxVelocity(200);
}
