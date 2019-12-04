#include "vex.h"

/* 

 */
void autonRedFront() {
  //open the hugger and drive up
  Hugger::getInstance() -> setPos(1);
  DriveTrain::getInstance() -> moveForward(1000, 30);
  task::sleep(100);

  Hugger::getInstance() -> setPos(0);

  armL.rotateTo(100, rotationUnits::deg, false);
  armR.rotateTo(100, rotationUnits::deg, false);

  DriveTrain::getInstance() -> turnLeft(180, 35);
  
  DriveTrain::getInstance() -> moveForward(1500, 40);

  DriveTrain::getInstance() -> setDrivePower(25);

  DriveTrain::getInstance()  -> stop();

  armL.rotateTo(0, rotationUnits::deg, false);
  armR.rotateTo(0, rotationUnits::deg, true);

  Hugger::getInstance() -> setPos(1);

  DriveTrain::getInstance() -> setDrivePower(-25);

  armL.rotateTo(100, rotationUnits::deg, false);
  armR.rotateTo(100, rotationUnits::deg, true);

  task::sleep(200);

  DriveTrain::getInstance() -> stop();
}

void autonRedBack() {}

void autonBlueFront() {}

void autonBlueBack() {}