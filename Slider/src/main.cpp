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
competition Competition;

// A global instance of vex::brain used for printing to the V5 brain screen


// Main

int main() {
  Brain.Screen.drawImageFromBuffer(rose_map, 0, 0, sizeof(rose_map));
  while(!Brain.Screen.pressing()){}
  task::sleep(250);
  pre_auton();
}
