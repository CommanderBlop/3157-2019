#include "vex.h"

void stack() {
  DriveTrain::getInstance()->setDrivePower(12);
  angler.rotateTo(645, rotationUnits::deg, 45, velocityUnits::pct, true);
  DriveTrain::getInstance()->setDrivePower(15);
  task::sleep(250);
  //DriveTrain::getInstance()->stop();
  
  DriveTrain::getInstance()->setDrivePower(-25);
  task::sleep(500);
  //angler.rotateTo(0, rotationUnits::deg, 45, velocityUnits::pct, false);
}
/*
   Start between R1-5 and R1-6, expand while moving forward, storing the preload, and suck up four cubes in R2-5 to R3-5. Turn around and put cubes in R1-6. 
	 5 pts.
  */
void autonRedFront() {
  // //expand while moving forward
  // bar.resetRotation();
  // bar.rotateTo(200, rotationUnits::deg, false);
  // //Intake::getInstance() -> setPos(-1);
  // Intake::getInstance() -> setPos(1);
  // bar.rotateTo(0, rotationUnits::deg, false);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*1.6, 50);

  // DriveTrain::getInstance() -> turnRight(40, 35);

  // DriveTrain::getInstance() -> moveForward(-1.6 * ONE_TILE, 75);
  
  // task::sleep(200);

  // DriveTrain::getInstance() -> turnLeft(30, 35);
  // task::sleep(200);

  // DriveTrain::getInstance() -> moveForward(0.9 * ONE_TILE, 50);

  // Intake::getInstance()->setPos(0);

  // // DriveTrain::getInstance() -> turnRight(135, 35);

  // // DriveTrain::getInstance() -> moveForward(3.5*ONE_TILE, 55);



  // // DriveTrain::getInstance()-> setDrivePower(15);
  // // task::sleep(50);


  // // stack();



    
  // //storing preload
  

  // //suck up four cubes in R2-5 to R3-5
  // task::sleep(1000); //can use encoder degree during tests

  // //nudge stack and back
  // // DriveTrain::getInstance() -> moveForward(ONE_TILE*1/25,5);
  // // task::sleep(300);

  // // DriveTrain::getInstance() -> moveBackward(ONE_TILE*1/4, 50);
  // // task::sleep(500);

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
 // Arm::getInstance() -> lowTower();
  Intake::getInstance() -> setPos(1);
  task::sleep(300);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.50, 50);
  //task::sleep(200);
    
  //storing preload
  Arm::getInstance() -> toZero();
  //Intake::getInstance() -> setPos(0);

  //suck up four cubes in R2-5 to R3-5
 // task::sleep(1000); //can use encoder degree during tests

  //nudge stack and back
 // DriveTrain::getInstance() -> moveForward(-1*ONE_TILE*.5, 50);
  //task::sleep(500);

  //DriveTrain::getInstance() -> setDrivePower(-25);
  //task::sleep(500);

 // Intake::getInstance() -> setPos(1);

  //Turn around and move forward

 // DriveTrain::getInstance() -> stop();
  //task::sleep(100);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*.5, 50);
  DriveTrain::getInstance() -> turnRight(20, 20);
  DriveTrain::getInstance() -> moveForward(-1*ONE_TILE*2, 50);
  DriveTrain::getInstance() -> setDrivePower(-20);
  task::sleep(1000);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*.20, 25);
  DriveTrain::getInstance() -> turnLeft(90, 35);

  DriveTrain::getInstance() -> setDrivePower(15);
  task::sleep(500);
  stack();
  DriveTrain::getInstance()-> stop();

  //drive to R1-1
  // DriveTrain::getInstance() ->moveForward(ONE_TILE, 50);
  // task::sleep(700);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*.5, 25);
  // task::sleep(500);
  // DriveTrain::getInstance() -> stop();
  // task::sleep(300);

  // //stack
  // angler.rotateTo(-550, rotationUnits::deg, 30, velocityUnits::pct, true);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*.10, 15);
  // task::sleep(100);
  // DriveTrain::getInstance() -> moveBackward(ONE_TILE*.25, -15);
  // task::sleep(500);
}


void autonBlueFront() {}

void autonBlueBack() {}