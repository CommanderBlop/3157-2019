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


 
int main() {
  pre_auton();

  Competition.autonomous(autonomous);
  // Competition.drivercontrol(usercontrol);
    while(1) {

        // BackL.spin(vex::directionType::fwd, con.Axis3.position(pct), vex::velocityUnits::pct);
        // BackR.spin(vex::directionType::fwd, con.Axis1.position(pct), vex::velocityUnits::pct);
        // FrontR.spin(vex::directionType::fwd, con.Axis1.position(pct), vex::velocityUnits::pct);
        // FrontL.spin(vex::directionType::fwd, con.Axis3.position(pct), vex::velocityUnits::pct);
        
        // if(con.ButtonL1.pressing() && mode <= 1) {
        //   mode++;
        // } else if(con.ButtonL2.pressing() && mode >= -1) {
        //   mode--;
        // }

        // if(mode == 1) {
        //   intakeL.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
        //   intakeR.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
        // } else if(mode == -1) {
        //   intakeL.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
        //   intakeR.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
        // } else if(mode == 0) {
        //   intakeL.stop(brakeType::hold);
        //   intakeR.stop(brakeType::hold);
        // }

        // if(con.Axis2.position(pct) < -7 || con.Axis2.position(pct) > 7) {
        //   armL.spin(vex::directionType::fwd, con.Axis2.position(pct) * 0.25, vex::velocityUnits::pct);
        //   armR.spin(vex::directionType::rev, con.Axis2.position(pct) * 0.25, vex::velocityUnits::pct);
        // } else {
        //   armL.stop(brakeType::hold);
        //   armR.stop(brakeType::hold);
        // }
      }
}
