



// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\LongJiakai                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  1 block = 1.8 rev                                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"             

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen


// Main

int main() {
  Gyro.calibrate();
  while(Gyro.isCalibrating()) {}
  //angler.rotateTo(655, rotationUnits::deg, 45, velocityUnits::pct, true);
  // Brain.Screen.drawImageFromBuffer(rose_map, 0, 0, sizeof(rose_map));
  // while(!Brain.Screen.pressing()){}
  // task::sleep(250);
  //autonomous();
  //oneCubeRed();
  //pre_auton();
  //autonRedBack();
  //backUp();//DriveTrain::getInstance() -> moveForward(ONE_TILE, 35);
  
  //autonRedBack();
  //autonRedFront();
  //userControl();
  //vex::thread gygy = thread(GyroDisplay);
  // for(int i = 0; i < 4; i++) {
    
  //   task::sleep(500);
  // }
  //DriveTrain::getInstance()->turnLeft(200, 30, false);
  DriveTrain::getInstance()->gyroTurnRight(360);
  task::sleep(1000);
  
}
