#include "vex.h"
/*
  	Start between R1-2, expand, suck preload, suck R2-2, suck 2 of the R3-2 stack, turn around R1-1, score.
    6 pts.
  */
void autonRedFront() {
  //expand while moving forward
  Arm::getInstance() -> lowTower();
  Intake::getInstance() -> setPos(-1);
  task::sleep(300);
  DriveTrain::getInstance() -> setDrivePower(50);
  task::sleep(200);
    
  //storing preload
  Arm::getInstance() -> toZero();
  Intake::getInstance() -> setPos(1);

  //suck up four cubes in R2-5 to R3-5
  task::sleep(1000); //can use encoder degree during tests

  //nudge stack and back
  DriveTrain::getInstance() -> setDrivePower(-25);
  task::sleep(300);

  DriveTrain::getInstance() -> setDrivePower(50);
  task::sleep(500);

  //Turn around and move forward

  DriveTrain::getInstance() -> stop();
  task::sleep(300);
  DriveTrain::getInstance() -> turnLeft(80);

  //drive to R1-1
  DriveTrain::getInstance() -> setDrivePower(50);
  task::sleep(700);
  DriveTrain::getInstance() -> setDrivePower(25);
  task::sleep(500);
  DriveTrain::getInstance() -> stop();
  task::sleep(300);

  //stack
  angler.rotateTo(-550, rotationUnits::deg, 30, velocityUnits::pct, true);
  DriveTrain::getInstance() -> setDrivePower(15);
  task::sleep(100);
  DriveTrain::getInstance() -> setDrivePower(-15);
  task::sleep(500);
}

/*
  Start between R1-5 and R1-6, expand while moving forward, storing the preload, and suck up four cubes in R2-5 to R3-5. Turn around and put cubes in R1-6. 
	5 pts.
 */
void autonRedBack() {
  //expand while moving forward
  Arm::getInstance() -> lowTower();
  Intake::getInstance() -> setPos(-1);
  task::sleep(300);
  DriveTrain::getInstance() -> setDrivePower(50);
  task::sleep(200);

  //storing preload
  Arm::getInstance() -> toZero();
  Intake::getInstance() -> setPos(1);

  //suck up four cubes in R2-5 to R3-5
  task::sleep(1000); //can use encoder degree during tests

  //Turn around and move forward

  DriveTrain::getInstance() -> stop();
  task::sleep(300);
  DriveTrain::getInstance() -> turnRight(80);

  //drive to R1-6
  DriveTrain::getInstance() -> setDrivePower(50);
  task::sleep(700);
  DriveTrain::getInstance() -> setDrivePower(25);
  task::sleep(500);
  DriveTrain::getInstance() -> stop();
  task::sleep(300);

  //stack
  angler.rotateTo(-550, rotationUnits::deg, 30, velocityUnits::pct, true);
  DriveTrain::getInstance() -> setDrivePower(15);
  task::sleep(100);
  DriveTrain::getInstance() -> setDrivePower(-15);
  task::sleep(500);
}

void autonBlueFront() {}

void autonBlueBack() {}