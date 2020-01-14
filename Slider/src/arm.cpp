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
  armCommand = false;
  angler.stop(brake);
  bar.stop();
}

void Arm::highTower() { //raise/lower arm to reach high tower height
  //angler rises
  armCommand = true;
  angler.rotateTo(1000, rotationUnits::deg, 90, velocityUnits::pct, false);
  task::sleep(300);
    bar.rotateTo(HIGH_TOWER, rotationUnits::deg, 90, velocityUnits::pct, true);
  // angler.rotateTo(1000, rotationUnits::deg, 90, velocityUnits::pct, true);
  
  //arm rotate to high max

  armCommand = false;
}

void Arm::toZero() { //arm rotate to original position
  //arm rotate to low max
  armCommand = true;
  bar.rotateTo(1300, rotationUnits::deg, -90, velocityUnits::pct, true);
  //task::sleep(300);
  angler.rotateTo(50, rotationUnits::deg, -45, velocityUnits::pct, false);
  bar.rotateTo(50, rotationUnits::deg, -90, velocityUnits::pct, true);

  
  //arm rotate to high max
  armCommand = false;
}