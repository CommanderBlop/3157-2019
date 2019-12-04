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

void DriveTrain::turnLeft(int deg){ //turn left with an integer degree
    int turn = deg * ROTATE_1_DEG;
    BackL.rotateFor(-1*turn,vex::rotationUnits::deg,false);
    FrontL.rotateFor(-1*turn, vex::rotationUnits::deg,false);
    BackR.rotateFor(turn,vex::rotationUnits::deg,false);
    FrontR.rotateFor(turn,vex::rotationUnits::deg,true);
}

void DriveTrain::turnRight(int deg){//turn right with an integer degree
    int turn = deg * ROTATE_1_DEG;
    BackL.rotateFor(turn,vex::rotationUnits::deg,false);
    FrontL.rotateFor(turn, vex::rotationUnits::deg,false);
    BackR.rotateFor(-1*turn,vex::rotationUnits::deg,false);
    FrontR.rotateFor(-1*turn,vex::rotationUnits::deg,true);
}

void DriveTrain::stop(){ //stop all motors
    FrontL.stop();
    FrontR.stop();
    BackL.stop();
    BackR.stop();
}

void DriveTrain::moveForward(int degree, int power) {
  Brain.resetTimer();
  BackL.resetRotation();
  BackR.resetRotation();
  FrontL.resetRotation();
  FrontR.resetRotation();
  for(int i = 0; i < 20; i++) {
    BackL.setVelocity(power * i / 20, velocityUnits::pct);
    BackR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontL.setVelocity(power * i / 20, velocityUnits::pct);
    task::sleep(10);
  }
  int angleMove = degree - 2 * BackL.rotation(rotationUnits::deg);
  BackL.rotateFor(angleMove,vex::rotationUnits::deg,false);
  FrontL.rotateFor(angleMove, vex::rotationUnits::deg,false);
  BackR.rotateFor(angleMove,vex::rotationUnits::deg,false);
  FrontR.rotateFor(angleMove,vex::rotationUnits::deg,true);

  for(int i = 20; i > 0; i--) {
    BackL.setVelocity(power * i / 20, velocityUnits::pct);
    BackR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontR.setVelocity(power * i / 20, velocityUnits::pct);
    FrontL.setVelocity(power * i / 20, velocityUnits::pct);
    task::sleep(10);
  }

  DriveTrain::getInstance() -> stop();
}