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
  //double turn = deg * ROTATE_360_DEG/360;
  double turn = deg;
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
    FrontL.stop(brakeType::brake);
    FrontR.stop(brakeType::brake);
    BackL.stop(brakeType::brake);
    BackR.stop(brakeType::brake);
}

void DriveTrain::hold() {
  FrontL.stop(brakeType::hold);
  FrontR.stop(brakeType::hold);
  BackL.stop(brakeType::hold);
  BackR.stop(brakeType::hold);
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

void DriveTrain::gyroTurnLeft(int deg) {
  BackL.spin(directionType::rev,30,velocityUnits::pct);
  BackR.spin(directionType::fwd,30,velocityUnits::pct);
  FrontL.spin(directionType::rev,30,velocityUnits::pct);
  FrontR.spin(directionType::fwd,30,velocityUnits::pct);
  while(fmax(Gyro.value(rotationUnits::deg), -1*Gyro.value(rotationUnits::deg)) < deg ) {}
  DriveTrain::getInstance()->stop();
}

void DriveTrain::gyroTurnRight(int degree) {
  //200 motor degree is 90.9 degree
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(fontType::mono60);
  Brain.Screen.setCursor(1,0);
  double start = Gyro.value(rotationUnits::deg);
  Brain.Screen.print(start);
  double deg = degree/0.43;
  double pwr = 30;
  // int deg = degree * 0.96;
  // int stage_1 = 30;
  // int stage_2 = 20;
  // int stage_3 = 8;
  BackL.rotateFor(deg,vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
  FrontL.rotateFor(deg, vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
  BackR.rotateFor(-1*deg,vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
  FrontR.rotateFor(-1*deg,vex::rotationUnits::deg,pwr, velocityUnits::pct,true);
  while(BackL.isSpinning() || FrontL.isSpinning() || BackR.isSpinning() || FrontR.isSpinning()) {}
  DriveTrain::getInstance()->stop();
  task::sleep(300);
  double delta = Gyro.value(rotationUnits::deg) - start;
  Brain.Screen.setCursor(2,0);
  Brain.Screen.print("moved for: %f",delta);
  delta = Gyro.value(rotationUnits::deg) - (start - degree);
  Brain.Screen.setCursor(3,0);
  Brain.Screen.print(delta);
//  if(fmax(delta, delta*-1) > 1.0) {
      //delta= -1*degree - Gyro.value(rotationUnits::deg);
      double move = delta/0.43;
      pwr = 13;
      BackL.rotateFor(move,vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
      FrontL.rotateFor(move, vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
      BackR.rotateFor(-1*move,vex::rotationUnits::deg,pwr, velocityUnits::pct,false);
      FrontR.rotateFor(-1*move,vex::rotationUnits::deg,pwr, velocityUnits::pct,true);
 //   }
    while(BackL.isSpinning() || FrontL.isSpinning() || BackR.isSpinning() || FrontR.isSpinning()) {}


  // while(start - Gyro.value(rotationUnits::deg) < deg * 0.7) {
  //   BackL.spin(directionType::fwd,stage_1,velocityUnits::pct);
  //   BackR.spin(directionType::rev,stage_1,velocityUnits::pct);
  //   FrontL.spin(directionType::fwd,stage_1,velocityUnits::pct);
  //   FrontR.spin(directionType::rev,stage_1,velocityUnits::pct);
  // }
  // while(start - Gyro.value(rotationUnits::deg) < deg * 0.85) {
  //   BackL.spin(directionType::fwd,stage_2,velocityUnits::pct);
  //   BackR.spin(directionType::rev,stage_2,velocityUnits::pct);
  //   FrontL.spin(directionType::fwd,stage_2,velocityUnits::pct);
  //   FrontR.spin(directionType::rev,stage_2,velocityUnits::pct);
  //   //if(pwr > 10) pwr--;
  // }
  // while(start - Gyro.value(rotationUnits::deg) < deg * 1.0001) {
  //   BackL.spin(directionType::fwd,stage_3,velocityUnits::pct);
  //   BackR.spin(directionType::rev,stage_3,velocityUnits::pct);
  //   FrontL.spin(directionType::fwd,stage_3,velocityUnits::pct);
  //   FrontR.spin(directionType::rev,stage_3,velocityUnits::pct);
  //   //if(pwr > 10) pwr--;
  // }
  // task::sleep(200);
  // DriveTrain::getInstance()->stop();
  // while(fmax(degree - Gyro.value(rotationUnits::deg), -1*degree - Gyro.value(rotationUnits::deg)) > 1.5 ) {
  //   if(start - Gyro.value(rotationUnits::deg) > deg) {
  //     BackL.spin(directionType::rev,6,velocityUnits::pct);
  //     BackR.spin(directionType::fwd,6,velocityUnits::pct);
  //     FrontL.spin(directionType::rev,6,velocityUnits::pct);
  //     FrontR.spin(directionType::fwd,6,velocityUnits::pct);
  //   } else if(start - Gyro.value(rotationUnits::deg) < deg) {
  //     BackL.spin(directionType::fwd,6,velocityUnits::pct);
  //     BackR.spin(directionType::rev,6,velocityUnits::pct);
  //     FrontL.spin(directionType::fwd,6,velocityUnits::pct);
  //     FrontR.spin(directionType::rev,6,velocityUnits::pct);
  //   }
  // }
  DriveTrain::getInstance()->stop();
  task::sleep(100);
  Brain.Screen.setCursor(5,0);
  Brain.Screen.print(Gyro.value(rotationUnits::deg) - start);
}