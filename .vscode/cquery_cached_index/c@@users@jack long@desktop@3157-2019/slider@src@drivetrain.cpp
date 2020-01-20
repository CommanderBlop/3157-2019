#include "vex.h"

//**important** measure the rotation motor degree for each actual degree/
//and log it in the header file

DriveTrain::DriveTrain(){} 

DriveTrain* DriveTrain::getInstance(){                                                                                
    static DriveTrain instance;
    return &instance; //returns a pointer to the single instance                                                            
}       

void DriveTrain::setDrivePower(int power){ //set drive power
    BackL.spin(directionType::fwd,power,velocityUnits::pct);
    BackR.spin(directionType::fwd,power,velocityUnits::pct);
    FrontL.spin(directionType::fwd,power,velocityUnits::pct);
    FrontR.spin(directionType::fwd,power,velocityUnits::pct);
}

void DriveTrain::turnLeft(int deg, int power, bool ramp){ //turn left with an integer degree
    double turn = deg * ROTATE_360_DEG/360;

  Brain.resetTimer();
  BackL.resetRotation();
  BackR.resetRotation();
  FrontL.resetRotation();
  FrontR.resetRotation();
  for(int i = 0; i < 20 && ramp; i++) {
    BackL.setVelocity(-1*power * i / 20, velocityUnits::pct);
    BackR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontL.setVelocity(-1*power * i / 20, velocityUnits::pct);
    task::sleep(10);
  }
  int angleMove = turn - 2 * BackL.rotation(rotationUnits::deg);
  BackL.rotateFor(-1*angleMove,vex::rotationUnits::deg,-1*power, velocityUnits::pct,false);
  FrontL.rotateFor(-1*angleMove, vex::rotationUnits::deg,-1*power, velocityUnits::pct,false);
  BackR.rotateFor(angleMove,vex::rotationUnits::deg,power, velocityUnits::pct,false);
  FrontR.rotateFor(angleMove,vex::rotationUnits::deg,power, velocityUnits::pct,true);

  for(int i = 20; i > 0 && ramp; i--) {
    BackL.setVelocity(-1*power * i / 20, velocityUnits::pct);
    BackR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontL.setVelocity(-1*power * i / 20, velocityUnits::pct);
    task::sleep(10);
  }

    stop();
}

void DriveTrain::turnRight(int deg, int power, bool ramp){//turn right with an integer degree
    double turn = deg * ROTATE_360_DEG/360;

    Brain.resetTimer();
  BackL.resetRotation();
  BackR.resetRotation();
  FrontL.resetRotation();
  FrontR.resetRotation();
  for(int i = 0; i < 20 && ramp; i++) {
    BackL.setVelocity(power * i / 20, velocityUnits::pct);
    BackR.setVelocity(-1*power * i / 20, velocityUnits::pct);
    FrontR.setVelocity(-1*power * i / 20, velocityUnits::pct);
    FrontL.setVelocity(power * i / 20, velocityUnits::pct);
    task::sleep(10);
  }
  int angleMove = turn - 2 * BackL.rotation(rotationUnits::deg);
  BackL.rotateFor(angleMove,vex::rotationUnits::deg,-1*power, velocityUnits::pct,false);
  FrontL.rotateFor(angleMove, vex::rotationUnits::deg,-1*power, velocityUnits::pct,false);
  BackR.rotateFor(-1*angleMove,vex::rotationUnits::deg,power, velocityUnits::pct,false);
  FrontR.rotateFor(-1*angleMove,vex::rotationUnits::deg,power, velocityUnits::pct,true);

  for(int i = 20; i > 0 && ramp; i--) {
    BackL.setVelocity(power * i / 20, velocityUnits::pct);
    BackR.setVelocity(-1*power * i / 20, velocityUnits::pct);
    FrontR.setVelocity(-1*power * i / 20, velocityUnits::pct);
    FrontL.setVelocity(power * i / 20, velocityUnits::pct);
    task::sleep(10);
  }

    stop();
}

void DriveTrain::stop(){ //stop all motors
    FrontL.stop();
    FrontR.stop();
    BackL.stop();
    BackR.stop();
}

void DriveTrain::moveForward(int degree, int power, bool ramp) {
  Brain.resetTimer();
  BackL.resetRotation();
  BackR.resetRotation();
  FrontL.resetRotation();
  FrontR.resetRotation();
  for(int i = 0; i < 20 && ramp; i++) {
    BackL.setVelocity(power * i / 20, velocityUnits::pct);
    BackR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontL.setVelocity(power * i / 20, velocityUnits::pct);
    task::sleep(10);
  }
  int angleMove = degree - 2 * BackL.rotation(rotationUnits::deg);
  BackL.rotateFor(angleMove,vex::rotationUnits::deg,power, velocityUnits::pct, false);
  FrontL.rotateFor(angleMove, vex::rotationUnits::deg,power, velocityUnits::pct,false);
  BackR.rotateFor(angleMove,vex::rotationUnits::deg,power, velocityUnits::pct,false);
  FrontR.rotateFor(angleMove,vex::rotationUnits::deg,power, velocityUnits::pct,true);

  for(int i = 20; i > 0 && ramp; i--) {
    BackL.setVelocity(power * i / 20, velocityUnits::pct);
    BackR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontL.setVelocity(power * i / 20, velocityUnits::pct);
    task::sleep(10);
  }

  DriveTrain::getInstance() -> stop();
}

void DriveTrain::moveBackward(int degree, int power, bool ramp) {
  Brain.resetTimer();
  BackL.resetRotation();
  BackR.resetRotation();
  FrontL.resetRotation();
  FrontR.resetRotation();
  for(int i = 0; i < 20 && ramp; i++) {
    BackL.setVelocity(-1*(power * i / 20), velocityUnits::pct);
    BackR.setVelocity(-1*(power * i / 20), velocityUnits::pct);
    FrontR.setVelocity(-1*(power * i / 20), velocityUnits::pct);
    FrontL.setVelocity(-1*(power * i / 20), velocityUnits::pct);
    task::sleep(10);
  }
  int angleMove = degree - 2 * BackL.rotation(rotationUnits::deg);
  BackL.rotateFor(angleMove,vex::rotationUnits::deg,false);
  FrontL.rotateFor(angleMove, vex::rotationUnits::deg,false);
  BackR.rotateFor(angleMove,vex::rotationUnits::deg,false);
  FrontR.rotateFor(angleMove,vex::rotationUnits::deg,true);

  for(int i = 20; i > 0 && ramp; i--) {
    BackL.setVelocity(-1*(power * i / 20), velocityUnits::pct);
    BackR.setVelocity(-1*(power * i / 20), velocityUnits::pct);
    FrontR.setVelocity(-1*(power * i / 20), velocityUnits::pct);
    FrontL.setVelocity(-1*(power * i / 20), velocityUnits::pct);
    task::sleep(10);
  }

  DriveTrain::getInstance() -> stop();
}