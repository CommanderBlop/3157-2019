// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
// 
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
// 
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window. 
// 
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Brain.Screen.drawImageFromBuffer(rose_map, 0, 0, sizeof(rose_map));
  // while(!Brain.Screen.pressing()){}
  // task::sleep(250);
  //pre_auton();
  //DriveTrain::getInstance() -> moveForward(ONE_TILE, 35);
  //stack();
  //autonRedFront();
  autonRedBack();
  //userControl();
}

// 
// 
// // ---- START VEXCODE CONFIGURED DEVICES ----
// // Robot Configuration:
// // [Name]               [Type]        [Port(s)]
// // ---- END VEXCODE CONFIGURED DEVICES ----
// /*----------------------------------------------------------------------------*/
// /*                                                                            */
// /*    Module:       main.cpp                                                  */
// /*    Author:       C:\Users\LongJiakai                                       */
// /*    Created:      Tue Oct 01 2019                                           */
// /*    Description:  1 block = 1.8 rev                                              */
// /*                                                                            */
// /*----------------------------------------------------------------------------*/
// #include "vex.h"             
// 
// using namespace vex;
// 
// // A global instance of vex::brain used for printing to the V5 brain screen
// 
// 
// // Main
// 
// int main() {
//   // Brain.Screen.drawImageFromBuffer(rose_map, 0, 0, sizeof(rose_map));
//   // while(!Brain.Screen.pressing()){}
//   // task::sleep(250);
//   //pre_auton();
//   //DriveTrain::getInstance() -> moveForward(ONE_TILE, 35);
//   //userControl();
//   autonRedFront();
// }
// 