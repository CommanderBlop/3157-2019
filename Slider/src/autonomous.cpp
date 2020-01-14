#include "vex.h"

void oneCubeRed() {
  bar.resetRotation();
  task::sleep(100);
  DriveTrain::getInstance() -> setDrivePower(-20);
  task::sleep(3000);
  DriveTrain::getInstance() -> setDrivePower(20);
  task::sleep(3000);
  DriveTrain::getInstance() -> stop();
}


void oneCubeBlue() {
  // bar.resetRotation();
  // bar.rotateTo(200, rotationUnits::deg, false);
  // Intake::getInstance() -> setPos(1);
  // bar.rotateTo(0, rotationUnits::deg, false);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*.5, 50, true);
  // Intake::getInstance()->setPos(0);
  // DriveTrain::getInstance() -> moveForward(-0.4*ONE_TILE, 50, true);
  // DriveTrain::getInstance() -> setDrivePower(-20);
  // task::sleep(500);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*.1, 25, false);
  // task::sleep(300);
  // DriveTrain::getInstance() -> turnLeft(90, 25, true);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*0.9, 60, true);
  // Intake::getInstance() -> setPos(0);
  // stack();
  bar.resetRotation();
  task::sleep(100);
  DriveTrain::getInstance() -> setDrivePower(-20);
  task::sleep(3000);
  DriveTrain::getInstance() -> setDrivePower(20);
  task::sleep(3000);
  DriveTrain::getInstance() -> stop();
}

void stack() {
  // intakeL.spin(directionType::rev, 8, velocityUnits::pct);
  // intakeR.spin(directionType::fwd, 8, velocityUnits::pct);
  // task::sleep(250);
  intakeL.stop(brakeType::coast);
  intakeR.stop(brakeType::coast);
  DriveTrain::getInstance()->setDrivePower(4);
  angler.rotateFor(3000, rotationUnits::deg, 40, velocityUnits::pct, true);
  angler.rotateFor(1000, rotationUnits::deg, 25, velocityUnits::pct, true);
  //con.rumble("*-*");
  task::sleep(300);
  //DriveTrain::getInstance()->stop();
  
  DriveTrain::getInstance()->setDrivePower(-35);
  task::sleep(1000);
  DriveTrain::getInstance()-> stop();
  //angler.rotateTo(0, rotationUnits::deg, 45, velocityUnits::pct, false);
}

void backUp() {
  bar.resetRotation();
  angler.resetRotation();
  bar.rotateTo(200, rotationUnits::deg, false);
  Intake::getInstance() -> setPos(1);
  bar.rotateTo(0, rotationUnits::deg, false);

  DriveTrain::getInstance() -> moveForward(ONE_TILE*-1.9, 60, true);
  // DriveTrain::getInstance() -> setDrivePower(-15);
  // task::sleep(500);
  
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.2, 20, false);
  task::sleep(100);

  DriveTrain::getInstance() -> turnRight(90, 25, true);
  task::sleep(100);
  Intake::getInstance() -> setPos(0);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.38, 20, false);

  stack();
}
/*
   Start between R1-5 and R1-6, expand while moving forward, storing the preload, and suck up four cubes in R2-5 to R3-5. Turn around and put cubes in R1-6. 
	 5 pts.
  */
void autonRedFront() {
  // vex::thread dis = thread(displayVal);
    bar.resetRotation();
  double start = Gyro.value(rotationUnits::deg);
  angler.rotateTo(700, rotationUnits::deg, 90, velocityUnits::pct, false);
  bar.rotateTo(700, rotationUnits::deg, 90, velocityUnits::pct, true);
  bar.rotateTo(40, rotationUnits::deg, 90, velocityUnits::pct, true);
  angler.rotateTo(40, rotationUnits::deg, 90, velocityUnits::pct, false);
  Intake::getInstance() -> setPos(1);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*0.5, 35, false);
  task::sleep(500);
  // double delta = Gyro.value(rotationUnits::deg) - start;
  // double move = delta/0.43;
  // int pwr = 13;
  // BackL.rotateFor(move,vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
  // FrontL.rotateFor(move, vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
  // BackR.rotateFor(-1*move,vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
  // FrontR.rotateFor(-1*move,vex::rotationUnits::deg,pwr, velocityUnits::pct,true);
  
  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.9, 50, true);
  task::sleep(300);

  DriveTrain::getInstance() -> gyroTurnRight(-30, true);
  task::sleep(350);

  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.5, 35, false);
  task::sleep(350);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*-0.5, 35, false);
  Intake::getInstance() -> setPos(0);
  task::sleep(350);

  DriveTrain::getInstance() -> gyroTurnRight(-160, true);
  task::sleep(350);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.87, 65, true);
  task::sleep(350);
  DriveTrain::getInstance() -> gyroTurnRight(-40, true);
  task::sleep(350);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.66, 35, false);
  // DriveTrain::getInstance()->setDrivePower(15);
  // task::sleep(700);
  DriveTrain::getInstance()->stop();
  stack();
  // dis.interrupt();


  // Brain.resetTimer();
  // bar.resetRotation();
  // bar.rotateTo(200, rotationUnits::deg, false);
  // Intake::getInstance() -> setPos(1);
  // bar.rotateTo(0, rotationUnits::deg, false);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE*1.85, 65, false);//1.95
  // task::sleep(200);
  // DriveTrain::getInstance() -> gyroTurnRight(-32, true);
  // Intake::getInstance() -> setPos(0);
  // task::sleep(100);
  // DriveTrain::getInstance() -> moveForward(-1.75 * ONE_TILE, 75, false);
  // task::sleep(450);
  // DriveTrain::getInstance() -> gyroTurnRight(28, false);
  // task::sleep(50);
  // Intake::getInstance() -> setPos(1);
  // DriveTrain::getInstance() -> moveForward(ONE_TILE * 1.65, 60, false);
  // task::sleep(200);
  // Gyro.resetRotation();
  // BackL.spin(fwd, 65, velocityUnits::pct);
  // FrontL.spin(fwd, 65, velocityUnits::pct);
  // while(Gyro.rotation(rotationUnits::deg) > - 140) {}
  // Intake::getInstance()->setPos(0);
  // DriveTrain::getInstance()->stop();
  // task::sleep(200);
  // DriveTrain::getInstance() -> moveForward(1.48*ONE_TILE, 55, true);
  // task::sleep(300);
  // intakeL.stop(hold);
  // intakeR.stop(hold);
  // stack();
}

/*
  Start between R1-2 and R1-3, expand, suck preload, suck R2-2, suck 2 of the R3-2 stack, turn around R1-1, score.
    6 pts.
 */
void autonRedBack() {
  
  bar.resetRotation();
  // bar.rotateTo(200, rotationUnits::deg, false);
  Intake::getInstance() -> setPos(1);
  //bar.rotateTo(0, rotationUnits::deg, false);
  angler.rotateFor(500, rotationUnits::deg, 35, velocityUnits::pct, false);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.45, 55, false);
  task::sleep(1000);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.4, 40, false);
  angler.rotateFor(-500, rotationUnits::deg, 35, velocityUnits::pct, false);
  DriveTrain::getInstance() -> gyroTurnRight(-30, true);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.4, 40, false);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*-0.4, 40, false);
  DriveTrain::getInstance() -> gyroTurnRight(30, true);
  task::sleep(1000);
  // intakeL.spin(directionType::fwd, 25, velocityUnits::pct);
  // intakeR.spin(directionType::rev, 25, velocityUnits::pct);
  // DriveTrain::getInstance() -> turnRight(15, 35, true);

  DriveTrain::getInstance() -> moveForward(-0.8*ONE_TILE, 55, true);
  Intake::getInstance() -> setPos(0);
  task::sleep(500);
  //Intake::getInstance() -> setPos(1);
  // DriveTrain::getInstance() -> setDrivePower(-20);
  DriveTrain::getInstance() -> gyroTurnRight(-120, true);
  task::sleep(200);
  Intake::getInstance() -> setPos(1);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*1.0, 50, true);
  // angler.rotateFor(3000, rotationUnits::deg, 55, velocityUnits::pct, false);
  intakeL.stop(brake);
  intakeR.stop(brake);
  task::sleep(300);
  DriveTrain::getInstance() -> gyroTurnRight(-30, true);
  task::sleep(300);
  DriveTrain::getInstance() -> moveForward(ONE_TILE*0.5, 25, false);

    stack();
  // while(angler.isSpinning()) {
    
  // }

  // intakeL.stop(coast);
  // intakeR.stop(coast);
  // angler.rotateFor(1000, rotationUnits::deg, 25, velocityUnits::pct, true);
  //DriveTrain::getInstance() -> setDrivePower(15);

  // DriveTrain::getInstance() -> setDrivePower(-15);
  // task::sleep(1000);
  // DriveTrain::getInstance()-> stop();

}


void autonBlueFront() {
  DriveTrain::getInstance() -> moveForward(-1.4 * ONE_TILE, 50, true);
  DriveTrain::getInstance() -> moveForward(1.4 * ONE_TILE, 50, true);
  task::sleep(1000);
  DriveTrain::getInstance() -> gyroTurnRight(90, true);
  task::sleep(500);
  Intake::getInstance()-> setPos(1);
  DriveTrain::getInstance() -> moveForward(1.9 * ONE_TILE, 50, true);
}
void autonBlueBack() {
  DriveTrain::getInstance() -> moveForward(-1.4 * ONE_TILE, 50, true);
  DriveTrain::getInstance() -> moveForward(1.4 * ONE_TILE, 50, true);
  task::sleep(1000);
  DriveTrain::getInstance() -> gyroTurnRight(90, true);
  task::sleep(500);
  Intake::getInstance()-> setPos(1);
  DriveTrain::getInstance() -> moveForward(1.9 * ONE_TILE, 50, true);
}