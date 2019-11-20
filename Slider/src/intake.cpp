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
    case -1:
      intakeL.spin(directionType::rev, 75, velocityUnits::pct);
      intakeR.spin(directionType::fwd, 75, velocityUnits::pct);
    case 0:
      intakeL.stop(hold);
      intakeR.stop(hold);
  }
}

void Intake::nextPos() {
  if(position < 1) position++;
  updateState();
}

void Intake::prevPos() {
  if(position > -1) position--;
  updateState();
}
