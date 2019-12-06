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
/*
   Start between R1-5 and R1-6, expand while moving forward, storing the preload, and suck up four cubes in R2-5 to R3-5. Turn around and put cubes in R1-6. 
	 5 pts.
  */
void autonRedFront() {
  //expand while moving forward
  bar.resetRotation();
  bar.rotateTo(200, rotationUnits::deg, false);
  //Intake::getInstance() -> setPos(-1);
  Intake::getInstance() -> setPos(1);
  bar.rotateTo(0, rotationUnits::deg, false);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.9, 60, true);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  task::sleep(300);

  DriveTrain::getInstance() -> turnLeft(27, 35, false);
  // Intake::getInstance() -> setPos(1);
  task::sleep(300);
  DriveTrain::getInstance() -> moveForward(-1.78 * ONE_TILE, 65, true);
  
  task::sleep(350);
  // Intake::getInstance() -> setPos(0);

  DriveTrain::getInstance() -> turnRight(38, 35, false);
  task::sleep(150);
  // Intake::getInstance() -> setPos(1);
  intakeL.spin(directionType::fwd, 100, velocityUnits::pct);
  intakeR.spin(directionType::rev, 100, velocityUnits::pct);
  DriveTrain::getInstance() -> moveForward(ONE_TILE * 1.7, 60, true);
  task::sleep(300);
  // Intake::getInstance()->setPos(0);
  intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  intakeR.spin(directionType::rev, 25, velocityUnits::pct);

  //DriveTrain::getInstance() -> moveForward(ONE_TILE * -0.3, 35, false);

  FrontR.rotateFor(-150, rotationUnits::deg, 45, velocityUnits::pct, false);
  BackR.rotateFor(-150, rotationUnits::deg, 45, velocityUnits::pct, true);
  
  task::sleep(300);
  BackL.rotateFor(625, rotationUnits::deg, 45, velocityUnits::pct, false);
  FrontL.rotateFor(625, rotationUnits::deg, 45, velocityUnits::pct, true);
  task::sleep(450);
  //DriveTrain::getInstance() -> moveForward(75, 25, false);
  
  BackL.rotateFor(210, rotationUnits::deg, 45, velocityUnits::pct, false);
  FrontL.rotateFor(210, rotationUnits::deg, 45, velocityUnits::pct, true);
  task::sleep(450);

  //DriveTrain::getInstance() -> turnRight(120, 45, true);
  
  //DriveTrain::getInstance() -> moveForward(-2*ONE_TILE, 60, false);

  // DriveTrain::getInstance()->setDrivePower(-20);
  // task::sleep(500);
  DriveTrain::getInstance() -> moveForward(1.43*ONE_TILE, 45, true);

  // task::sleep(200);
  // DriveTrain::getInstance() -> turnRight(90, 35);

  // // Intake::getInstance() -> setPos(1);
  // task::sleep(100);
  // DriveTrain::getInstance() -> moveForward(1*ONE_TILE, 55);

  // DriveTrain::getInstance() -> setDrivePower(10);

  Intake::getInstance() -> setPos(0);

  // task::sleep(500);


  // DriveTrain::getInstance()-> setDrivePower(15);
  //task::sleep(50);


  stack();



    
  // //storing preload
  

  //suck up four cubes in R2-5 to R3-5
  //DriveTrain::getInstance() -> stop(); //can use encoder degree during tests

  //nudge stack and back
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*1/25,5);
  // task::sleep(300);

  // DriveTrain::getInstance() -> moveBackward(ONE_TILE*1/4, 50);
  // task::sleep(500);

  // //Turn around and move forward

  // DriveTrain::getInstance() -> stop();
  // task::sleep(300);
  // DriveTrain::getInstance() -> turnRight(80);

  // //drive to R1-6
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*1/4, 50);
  // task::sleep(700);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*1/4, 25);
  // task::sleep(500);
  // DriveTrain::getInstance() -> stop();
  // task::sleep(300);

  // //stack
  // angler.rotateTo(-550, rotationUnits::deg, 30, velocityUnits::pct, true);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*1/10, 15);
  // task::sleep(100);
  // DriveTrain::getInstance() -> moveBackward(ONE_TILE*1/4, 15);
  // task::sleep(500);
}

/*
  Start between R1-2 and R1-3, expand, suck preload, suck R2-2, suck 2 of the R3-2 stack, turn around R1-1, score.
    6 pts.
 */
void autonRedBack() {
//  // Arm::getInstance() -> lowTower();
//   Intake::getInstance() -> setPos(1);
//   task::sleep(300);
//   DriveTrain::getInstance() -> moveForward(ONE_TILE*1.50, 50);
//   //task::sleep(200);
    
//   //storing preload
//   Arm::getInstance() -> toZero();
//   //Intake::getInstance() -> setPos(0);

//   //suck up four cubes in R2-5 to R3-5
//  // task::sleep(1000); //can use encoder degree during tests

//   //nudge stack and back
//  // DriveTrain::getInstance() -> moveForward(-1*ONE_TILE*.5, 50);
//   //task::sleep(500);

//   //DriveTrain::getInstance() -> setDrivePower(-25);
//   //task::sleep(500);

//  // Intake::getInstance() -> setPos(1);

//   //Turn around and move forward

//  // DriveTrain::getInstance() -> stop();
//   //task::sleep(100);
//   DriveTrain::getInstance() -> moveForward(ONE_TILE*.5, 30);
//   //task::sleep(200);
//   intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
//   intakeR.spin(directionType::rev, 25, velocityUnits::pct);
//   DriveTrain::getInstance() -> turnRight(25, 35);

//   DriveTrain::getInstance() -> moveForward(-1*ONE_TILE*2, 75);
//   Intake::getInstance() -> setPos(1);
//   DriveTrain::getInstance() -> setDrivePower(-20);
//   task::sleep(1000);
//   DriveTrain::getInstance() -> moveForward(ONE_TILE*.30, 25);
//   DriveTrain::getInstance() -> turnLeft(90, 35);

//   DriveTrain::getInstance() -> setDrivePower(15);
//   intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
//   intakeR.spin(directionType::rev, 25, velocityUnits::pct);
//   task::sleep(1000);
//   stack();
//   DriveTrain::getInstance()-> stop();

}


void autonBlueFront() {}

void autonBlueBack() {}