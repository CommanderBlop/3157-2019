#include "vex.h"

void btnL1() {
    static bool lastPressed = con.ButtonL1.pressing();
    while (true) {
        if (con.ButtonL1.pressing()) lastPressed = true;
        else if (!con.ButtonL1.pressing() && lastPressed) {
            Intake::getInstance() -> nextPos();
        }
        this_thread::yield();
    }
}

void btnL2() {
    static bool lastPressed = con.ButtonL2.pressing();
    while (true) {
        if (con.ButtonR2.pressing()) lastPressed = true;
        else if (!con.ButtonR2.pressing() && lastPressed) {
            lastPressed = false;
            Intake::getInstance()->prevPos();
        }
        this_thread::yield();
    }
}

void joyStick() {
    while (true) {
        BackL.spin(vex::directionType::fwd, con.Axis1.position(pct) + con.Axis3.position(pct) * 0.75, vex::velocityUnits::pct);
        BackR.spin(vex::directionType::fwd, con.Axis1.position(pct) + con.Axis3.position(pct) * 0.75, vex::velocityUnits::pct);
        FrontR.spin(vex::directionType::fwd, con.Axis1.position(pct) - con.Axis3.position(pct) * 0.75, vex::velocityUnits::pct);
        FrontL.spin(vex::directionType::fwd, con.Axis1.position(pct) - con.Axis3.position(pct) * 0.75, vex::velocityUnits::pct);
        this_thread::yield();
    }
}

void arm() {
  while(true) {
    if(con.Axis2.position(pct) < -7 || con.Axis2.position(pct) > 7) {
          armL.spin(vex::directionType::fwd, con.Axis2.position(pct) * 0.25, vex::velocityUnits::pct);
          armR.spin(vex::directionType::rev, con.Axis2.position(pct) * 0.25, vex::velocityUnits::pct);
    } else {
          armL.stop(brakeType::hold);
          armR.stop(brakeType::hold);
    }
    this_thread::yield();
  }
}


void startThreads(){
    thread L1 = thread(btnL1);
    thread L2 = thread(btnL2);
    thread joy = thread(joyStick);
    thread lift = thread(arm);
}

void userControl(void) {
  startThreads();
  while(1);
}

