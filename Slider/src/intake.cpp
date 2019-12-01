#include "vex.h"
//Intake State:
//-1: outtake
// 0: stop
// 1: intake

Intake::Intake() {}

Intake* Intake::getInstance() {
  static Intake instance;
  return &instance;
}

void Intake::updateState() { //intake state change
  switch(position) {
    case 1: //intake
      intakeL.spin(directionType::fwd, 75, velocityUnits::pct);
      intakeR.spin(directionType::rev, 75, velocityUnits::pct);
      break;
    case -1: //outtake
      intakeL.spin(directionType::rev, 75, velocityUnits::pct);
      intakeR.spin(directionType::fwd, 75, velocityUnits::pct);
      break;
    case 0: //stop
      intakeL.stop(brake);
      intakeR.stop(brake);
      break;
  }
}

void Intake::nextPos() { //intake state +1
  if(position < 1) position++;
  else position = 1;
  updateState();
}

void Intake::prevPos() { //intake state -1
  if(position > -1) position--;
  else position = -1;
  updateState();
}

void Intake::setPos(int pos) { //manually set intake state for auton
  position = pos;
  updateState();
}