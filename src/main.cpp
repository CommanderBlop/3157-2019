/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\LongJiakai                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

vex::motor      BackR(vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor      FrontR(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor      BackL(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor      FrontL(vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor      intakeL(vex::PORT9, vex::gearSetting::ratio18_1, false);
vex::motor      intakeR(vex::PORT8, vex::gearSetting::ratio18_1, false);
vex::motor      angler(vex::PORT5, vex::gearSetting::ratio18_1, false);
vex::motor      bar(vex::PORT6, vex::gearSetting::ratio6_1, true);

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::controller con(vex::controllerType::primary);
// define your global instances of motors and other devices here

void raiseBar() {
  bar.rotateTo(90, rotationUnits::deg, 75, vex::velocityUnits::pct);
}

void dropBar() {
  bar.rotateTo(20, rotationUnits::deg, 75, vex::velocityUnits::pct);
}

void raiseAngler() {
  angler.rotateTo(90, rotationUnits::deg, 23, vex::velocityUnits::pct);
}

void dropAngler() {
  angler.rotateTo(20, rotationUnits::deg, 23, vex::velocityUnits::pct);
}
 
int main() {
    while(1) {
        BackL.spin(vex::directionType::fwd, con.Axis3.position(pct), vex::velocityUnits::pct);
        BackR.spin(vex::directionType::fwd, con.Axis2.position(pct), vex::velocityUnits::pct);
        FrontR.spin(vex::directionType::fwd, con.Axis2.position(pct), vex::velocityUnits::pct);
        FrontL.spin(vex::directionType::fwd, con.Axis3.position(pct), vex::velocityUnits::pct);
        
        if(con.ButtonL1.pressing()) {
          intakeL.spin(vex::directionType::fwd, 25, vex::velocityUnits::pct);
          intakeR.spin(vex::directionType::rev, 25, vex::velocityUnits::pct);
        } else if(con.ButtonL2.pressing()) {
          intakeL.spin(vex::directionType::rev, 25, vex::velocityUnits::pct);
          intakeR.spin(vex::directionType::fwd, 25, vex::velocityUnits::pct);
        } else {
          intakeL.stop(brakeType::hold);
          intakeR.stop(brakeType::hold);
        }

        if(con.ButtonR1.pressing()) {
          angler.spin(vex::directionType::fwd, 20, vex::velocityUnits::pct);
        } else if(con.ButtonR2.pressing()) {
          angler.spin(directionType::rev, 20, velocityUnits::pct);
        } else {
          angler.stop(brakeType::brake);
        }

        if(con.ButtonUp.pressing()) {
          bar.spin(directionType::fwd, 100, velocityUnits::pct);
        } else if(con.ButtonDown.pressing()) {
          bar.spin(directionType::rev, 100, velocityUnits::pct);
        } else {
          bar.stop(brakeType::brake);
        }

        if(con.ButtonA.pressing()) {
          raiseBar();
          task::sleep(30);
        }

        if(con.ButtonB.pressing()) {
          dropBar();
          task::sleep(30);
        }

        if(con.ButtonX.pressing()) {
          raiseAngler();
          task::sleep(30);
        }

        if(con.ButtonY.pressing()) {
          dropAngler();
          task::sleep(30);
        }
      }
}
