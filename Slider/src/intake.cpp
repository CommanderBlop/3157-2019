#include "vex.h"
Intake::Intake() {}

Intake* Intake::getInstance() {
  static Intake instance;
  return &instance;
}

void Intake::updateState() {
  switch(position) {
    case 1:
      intakeL.spin(directionType::fwd, 75, velocityUnits::pct);
      intakeR.spin(directionType::rev, 75, velocityUnits::pct);
      break;
    case -1:
      intakeL.spin(directionType::rev, 75, velocityUnits::pct);
      intakeR.spin(directionType::fwd, 75, velocityUnits::pct);
      break;
    case 0:
      intakeL.stop(brake);
      intakeR.stop(brake);
      break;
  }
}

void Intake::nextPos() {
  if(position < 1) position++;
  else position = 1;
  updateState();
}

void Intake::prevPos() {
  if(position > -1) position--;
  else position = -1;
  updateState();
}

void Intake::setPos(int pos) {
  position = pos;
  updateState();
}