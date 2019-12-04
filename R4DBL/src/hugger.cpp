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
      Hug.rotateFor(OPEN_STATE, rotationUnits::deg, 50, velocityUnits::pct, true);
      Hug.setBrake(brakeType::hold);
      break;
    case 0: //outtake
      Hug.rotateFor(-1 * OPEN_STATE, rotationUnits::deg, 50, velocityUnits::pct, true);
      Hug.setBrake(brakeType::hold);
      break;
  }
}

void Hugger::nextPos() { //Hugger state +1
  if(position == 0) {
    position = 1; 
    updateState();
  }
}

void Hugger::prevPos() { //Hugger state -1
  if(position == 1) {
    position = 0; 
    updateState();
  }
}

void Hugger::setPos(int pos) { //manually set Hugger state for auton
  position = pos;
  updateState();
}