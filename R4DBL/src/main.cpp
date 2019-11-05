/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\LongJiakai                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

vex::motor      BackR(vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor      FrontR(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor      BackL(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor      FrontL(vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor      intakeL(vex::PORT9, vex::gearSetting::ratio18_1, false);
vex::motor      intakeR(vex::PORT8, vex::gearSetting::ratio18_1, false);
vex::motor      armL(vex::PORT5, vex::gearSetting::ratio6_1, true);
vex::motor      armR(vex::PORT6, vex::gearSetting::ratio6_1, true);

// A global instance of vex::brain used for printing to the V5 brain screen

vex::controller con(vex::controllerType::primary);
// define your global instances of motors and other devices here

double mode;
 
int main() {
    while(1) {
        BackL.spin(vex::directionType::fwd, con.Axis3.position(pct), vex::velocityUnits::pct);
        BackR.spin(vex::directionType::fwd, con.Axis2.position(pct), vex::velocityUnits::pct);
        FrontR.spin(vex::directionType::fwd, con.Axis2.position(pct), vex::velocityUnits::pct);
        FrontL.spin(vex::directionType::fwd, con.Axis3.position(pct), vex::velocityUnits::pct);
        
        if(con.ButtonL1.pressing()) {
          intakeL.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
          intakeR.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
          mode = 1;
        } else if(con.ButtonL2.pressing()) {
          intakeL.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
          intakeR.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
          mode = 2;
        } else {
          intakeL.stop(brakeType::hold);
          intakeR.stop(brakeType::hold);
        }

        if(con.ButtonR1.pressing()) {
          armL.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
          armR.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
        } else if(con.ButtonR2.pressing()) {
          armL.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
          armR.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        } else {
          armR.stop(brakeType::hold);
          armR.stop(brakeType::hold);
        }
      }
}
