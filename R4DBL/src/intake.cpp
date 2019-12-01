#include "vex.h"
Intake::Intake() {}

Intake* Intake::getInstance() {
  static Intake instance;
  return &instance;
}

void Intake::updateState() { //intake state update 
  switch(position) {
    case 1: //intake
      intakeL.spin(directionType::fwd, 75, velocityUnits::pct);
      intakeR.spin(directionType::rev, 75, velocityUnits::pct);
    case -1: //outtake
      intakeL.spin(directionType::rev, 75, velocityUnits::pct);
      intakeR.spin(directionType::fwd, 75, velocityUnits::pct);
    case 0: //stop
      intakeL.stop(hold);
      intakeR.stop(hold);
  }
}

void Intake::nextPos() { //change to next position
  if(position < 1) position++;
  updateState();
}

void Intake::prevPos() { //change to previous position
  if(position > -1) position--;
  updateState();
}
