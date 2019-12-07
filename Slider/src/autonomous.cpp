#include "vex.h"

void stack() {
  //DriveTrain::getInstance()->setDrivePower(10);
  angler.rotateTo(655, rotationUnits::deg, 45, velocityUnits::pct, true);
  //DriveTrain::getInstance()->setDrivePower(15);
  task::sleep(250);
  //DriveTrain::getInstance()->stop();
  
  DriveTrain::getInstance()->setDrivePower(-45);
  task::sleep(500);
  DriveTrain::getInstance()-> stop();
  //angler.rotateTo(0, rotationUnits::deg, 45, velocityUnits::pct, false);
}

void backUp() {
  bar.resetRotation();
  bar.rotateTo(200, rotationUnits::deg, false);
  Intake::getInstance() -> setPos(1);
  bar.rotateTo(0, rotationUnits::deg, false);

  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.9, 60, true);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  task::sleep(500);

  DriveTrain::getInstance() -> moveForward(ONE_TILE*-1.75, 60, true);
  DriveTrain::getInstance() -> setDrivePower(-15);
  task::sleep(1000);
  
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.30, 30, true);
  task::sleep(300);

  DriveTrain::getInstance() -> turnRight(90, 35, true);
  task::sleep(300);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.50, 30, true);

  stack();
}
/*
   Start between R1-5 and R1-6, expand while moving forward, storing the preload, and suck up four cubes in R2-5 to R3-5. Turn around and put cubes in R1-6. 
	 5 pts.
  */
void autonRedFront() {
  bar.resetRotation();
  bar.rotateTo(200, rotationUnits::deg, false);
  Intake::getInstance() -> setPos(1);
  bar.rotateTo(0, rotationUnits::deg, false);

  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.9, 60, true);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  task::sleep(300);

  DriveTrain::getInstance() -> turnLeft(27, 35, false);
  task::sleep(300);

  DriveTrain::getInstance() -> moveForward(-1.78 * ONE_TILE, 65, true);
  task::sleep(350);


  DriveTrain::getInstance() -> turnRight(50, 35, false);
  task::sleep(150);

  intakeL.spin(directionType::fwd, 100, velocityUnits::pct);
  intakeR.spin(directionType::rev, 100, velocityUnits::pct);
  DriveTrain::getInstance() -> moveForward(ONE_TILE * 1.7, 60, true);
  task::sleep(300);

  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);



  FrontR.rotateFor(-275, rotationUnits::deg, 45, velocityUnits::pct, false);
  BackR.rotateFor(-275, rotationUnits::deg, 45, velocityUnits::pct, true);
  
  task::sleep(300);
  BackL.rotateFor(625, rotationUnits::deg, 45, velocityUnits::pct, false);
  FrontL.rotateFor(625, rotationUnits::deg, 45, velocityUnits::pct, true);
  task::sleep(450);

  
  BackL.rotateFor(180, rotationUnits::deg, 45, velocityUnits::pct, false);
  FrontL.rotateFor(180, rotationUnits::deg, 45, velocityUnits::pct, true);
  task::sleep(450);

  DriveTrain::getInstance() -> moveForward(1.50*ONE_TILE, 45, true);

  Intake::getInstance() -> setPos(0);

  stack();
}

/*
  Start between R1-2 and R1-3, expand, suck preload, suck R2-2, suck 2 of the R3-2 stack, turn around R1-1, score.
    6 pts.
 */
void autonRedBack() {
  bar.resetRotation();
  bar.rotateTo(200, rotationUnits::deg, false);
  Intake::getInstance() -> setPos(1);

  bar.rotateTo(0, rotationUnits::deg, false);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.50, 50, true);

  DriveTrain::getInstance() -> moveForward(ONE_TILE*.5, 30, true);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  DriveTrain::getInstance() -> turnRight(25, 35, true);

  DriveTrain::getInstance() -> moveForward(-1*ONE_TILE*2, 75, true);
  Intake::getInstance() -> setPos(1);
  DriveTrain::getInstance() -> setDrivePower(-20);
  task::sleep(1000);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*.30, 25, true);
  DriveTrain::getInstance() -> turnLeft(90, 35, true);

  DriveTrain::getInstance() -> setDrivePower(15);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  task::sleep(1000);
  stack();
  DriveTrain::getInstance()-> stop();

}


void autonBlueFront() {
  bar.resetRotation();
  bar.rotateTo(200, rotationUnits::deg, false);
  Intake::getInstance() -> setPos(1);
  bar.rotateTo(0, rotationUnits::deg, false);

  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.9, 60, true);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  task::sleep(300);

  DriveTrain::getInstance() -> turnRight(27, 35, false);

  task::sleep(300);
  DriveTrain::getInstance() -> moveForward(-1.78 * ONE_TILE, 65, true);
  
  task::sleep(350);

  DriveTrain::getInstance() -> turnLeft(50, 35, false);
  task::sleep(150);

  intakeL.spin(directionType::fwd, 100, velocityUnits::pct);
  intakeR.spin(directionType::rev, 100, velocityUnits::pct);
  DriveTrain::getInstance() -> moveForward(ONE_TILE * 1.7, 60, true);

  task::sleep(300);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);

  FrontR.rotateFor(-275, rotationUnits::deg, 45, velocityUnits::pct, false);
  BackR.rotateFor(-275, rotationUnits::deg, 45, velocityUnits::pct, true);
  task::sleep(300);

  BackL.rotateFor(625, rotationUnits::deg, 45, velocityUnits::pct, false);
  FrontL.rotateFor(625, rotationUnits::deg, 45, velocityUnits::pct, true);
  task::sleep(450);
  
  BackL.rotateFor(180, rotationUnits::deg, 45, velocityUnits::pct, false);
  FrontL.rotateFor(180, rotationUnits::deg, 45, velocityUnits::pct, true);
  task::sleep(450);

  DriveTrain::getInstance() -> moveForward(1.50*ONE_TILE, 45, true);


  Intake::getInstance() -> setPos(0);

  stack();

}

void autonBlueBack() {
bar.resetRotation();
  bar.rotateTo(200, rotationUnits::deg, false);
  Intake::getInstance() -> setPos(1);

  bar.rotateTo(0, rotationUnits::deg, false);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.50, 50, true);


  DriveTrain::getInstance() -> moveForward(ONE_TILE*.5, 30, true);
  //task::sleep(200);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  DriveTrain::getInstance() -> turnLeft(25, 35, true);

  DriveTrain::getInstance() -> moveForward(-1*ONE_TILE*2, 75, true);
  Intake::getInstance() -> setPos(1);
  DriveTrain::getInstance() -> setDrivePower(-20);
  task::sleep(1000);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*.30, 25, true);
  DriveTrain::getInstance() -> turnRight(90, 35, true);

  DriveTrain::getInstance() -> setDrivePower(15);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  task::sleep(1000);
  DriveTrain::getInstance()-> stop();
  stack();

}