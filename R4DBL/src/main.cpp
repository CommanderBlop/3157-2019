/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\LongJiakai                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
//https://github.com/Kohmei358/RBE1001-Group1/blob/master/final.cpp

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    3, 1            
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

vex::competition Competition;

// A global instance of vex::brain used for printing to the V5 brain screen


// define your global instances of motors and other devices here


 
int main() { //calibrate values 
  armL.resetRotation();
  armR.resetRotation();

  Brain.Screen.drawImageFromBuffer(rose_map, 0, 0, sizeof(rose_map));
  while(!Brain.Screen.pressing()){}
  task::sleep(250);

  pre_auton();

  while(1) {}
}
