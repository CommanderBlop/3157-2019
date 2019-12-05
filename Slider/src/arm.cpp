#include "vex.h"

Arm::Arm() {}

Arm* Arm::getInstance() {
  static Arm instance;
  return &instance;
}

void Arm::calcValue() { //set up values 
  bar.resetRotation();
  LOW_TOWER = bar.rotation(rotationUnits::deg) + 150; //arbitrary number, needs checking
  HIGH_TOWER = bar.rotation(rotationUnits::deg) + 300;
  ARM_SPEED_BUFFER = 0.25;
}

void Arm::move() { //move arm based on right joystick vertical axis
  bar.spin(vex::directionType::fwd, con.Axis2.position(pct) * ARM_SPEED_BUFFER, vex::velocityUnits::pct);
}

void Arm::moveUp() {
  bar.spin(vex::directionType::fwd, 35, vex::velocityUnits::pct);
}

void Arm::moveDown() {
  bar.spin(vex::directionType::fwd, -35, vex::velocityUnits::pct);
}


void Arm::lowTower() { //raise/lower arm to reach low tower height
  bar.rotateTo(LOW_TOWER, rotationUnits::deg, 50, velocityUnits::pct, false);
}

void Arm::highTower() { //raise/lower arm to reach high tower height
  bar.rotateTo(HIGH_TOWER, rotationUnits::deg, 50, velocityUnits::pct, false);
}

void Arm::toZero() { //arm rotate to original position
  bar.rotateTo(0, rotationUnits::deg, 50, velocityUnits::pct, false);
}