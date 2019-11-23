#include "vex.h"

Arm::Arm() {}

Arm* Arm::getInstance() {
  static Arm instance;
  return &instance;
}

void Arm::calcValue() {
  bar.resetRotation();
  LOW_TOWER = bar.rotation(rotationUnits::deg) + 150; //arbitrary number, needs checking
  HIGH_TOWER = bar.rotation(rotationUnits::deg) + 300;
  ARM_SPEED_BUFFER = 0.25;
}

void Arm::move() {
  bar.spin(vex::directionType::fwd, con.Axis2.position(pct) * ARM_SPEED_BUFFER, vex::velocityUnits::pct);
}

void Arm::lowTower() {
  bar.rotateTo(LOW_TOWER, rotationUnits::deg, 50, velocityUnits::pct, false);
}

void Arm::highTower() {
  bar.rotateTo(HIGH_TOWER, rotationUnits::deg, 50, velocityUnits::pct, false);
}