#include "vex.h"
//Hugger State:
//-1: outtake
// 0: stop
// 1: Hugger

Hugger::Hugger() {}

Hugger* Hugger::getInstance() {
  static Hugger instance;
  return &instance;
}


void Hugger::updateState() { //Hugger state change
  switch(position) {
    case 1: //Hugger
      Hug.rotateFor(-1* OPEN_STATE, rotationUnits::deg, 25, velocityUnits::pct, true);
      Hug.setBrake(brakeType::hold);
      break;
    case 0: //outtake
      Hug.rotateFor(OPEN_STATE, rotationUnits::deg, 25, velocityUnits::pct, true);
      Hug.spin(directionType::fwd, 5, velocityUnits::pct);
      while(Hug.torque(torqueUnits::Nm) < 0.8) {}
      Hug.stop(brakeType::hold);
      break;
  }
}

void Hugger::open() { //Hugger state +1
  if(!atMax ) {
    Hug.spin(directionType::rev, 25, velocityUnits::pct);
    if(Hug.torque(torqueUnits::Nm) > 0.8) {
      atMax = true;
      Hug.stop(brakeType::hold);
    }
  }
}

void Hugger::close() { //Hugger state -1
  Hug.spin(directionType::fwd, 25, velocityUnits::pct);
  if(Hug.torque(torqueUnits::Nm) > 0.8) {
    Hug.stop(brakeType::coast);
  }
  if(con.ButtonL2.pressing()) {
    Hug.rotateFor(OPEN_STATE, rotationUnits::deg, 25, velocityUnits::pct, true);
    Hug.spin(directionType::fwd, 5, velocityUnits::pct);
    while(Hug.torque(torqueUnits::Nm) < 0.8) {}
    Hug.stop(brakeType::hold);
  }
}

void Hugger::setPos(int pos) { //manually set Hugger state for auton
  position = pos;
  updateState();
}