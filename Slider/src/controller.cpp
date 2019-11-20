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
          con.rumble("*-*-*");
      }
      //this_thread::yield();
      vex::task::sleep(50);
  }
}

void joyStick() {
  while (true) {
      BackL.spin(vex::directionType::fwd, con.Axis3.position(pct) * 0.75 + con.Axis1.position(pct), vex::velocityUnits::pct);
      BackR.spin(vex::directionType::fwd, con.Axis3.position(pct) * 0.75 - con.Axis1.position(pct), vex::velocityUnits::pct);
      FrontR.spin(vex::directionType::fwd, con.Axis3.position(pct) * 0.75 - con.Axis1.position(pct), vex::velocityUnits::pct);
      FrontL.spin(vex::directionType::fwd, con.Axis3.position(pct) * 0.75 + con.Axis1.position(pct), vex::velocityUnits::pct);
      vex::task::sleep(50);
      //this_thread::yield();
  }
}

void arm() {
while(true) {
  if(con.Axis2.position(pct) < -7 || con.Axis2.position(pct) > 7) {
        bar.spin(vex::directionType::fwd, con.Axis2.position(pct) * 0.25, vex::velocityUnits::pct);
  } else {
        bar.stop(brakeType::hold);
  }
  vex::task::sleep(50);
  this_thread::yield();
}
}


void startThreads(){
  vex::thread L1 = thread(btnL1);
  vex::thread L2 = thread(btnL2);
  vex::thread joy = thread(joyStick);
  vex::thread lift = thread(arm);
}

void userControl(void) {
  //startThreads();
  bool lastMovedFwd = false;
  while(1) {
    double y = con.Axis3.position(pct);
    double x = con.Axis1.position(pct) *  0.73;

    if (fmax(x, x * -1) > 3) {
      lastMovedFwd = false;
    } else if (fmax(y, y * -1) > 3) {
      lastMovedFwd = true;
    }
    if (fmax(y, y * -1) < 3 && fmax(x, x * -1) < 3) { // no input
      if (lastMovedFwd == false) {
        BackR.stop(brakeType::hold);
        BackL.stop(brakeType::hold);
        FrontR.stop(brakeType::hold);
        FrontL.stop(brakeType::hold);
      } else {
        BackR.stop(brakeType::brake);
        BackL.stop(brakeType::brake);
        FrontR.stop(brakeType::brake);
        FrontL.stop(brakeType::brake);
      }
    } else {
      BackR.spin(vex::directionType::fwd, y - x, vex::velocityUnits::pct);
      FrontR.spin(vex::directionType::fwd, y - x, vex::velocityUnits::pct);
      BackL.spin(vex::directionType::fwd, y + x, vex::velocityUnits::pct);
      FrontL.spin(vex::directionType::fwd, y + x, vex::velocityUnits::pct);
    }
    task::sleep(30);
    vex::this_thread::sleep_for(25);
  }
  // BackL.spin(vex::directionType::fwd, con.Axis3.position(pct) * 0.75 + con.Axis1.position(pct), vex::velocityUnits::pct);
  // BackR.spin(vex::directionType::fwd, con.Axis3.position(pct) * 0.75 - con.Axis1.position(pct), vex::velocityUnits::pct);
  // FrontR.spin(vex::directionType::fwd, con.Axis3.position(pct) * 0.75 - con.Axis1.position(pct), vex::velocityUnits::pct);
  // FrontL.spin(vex::directionType::fwd, con.Axis3.position(pct) * 0.75 + con.Axis1.position(pct), vex::velocityUnits::pct);
  
  // if(con.ButtonL1.pressing() && mode <= 1) {
  //   while(con.ButtonL1.pressing());
  //   mode++;
  // } else if(con.ButtonL2.pressing() && mode >= -1) {
  //   while(con.ButtonL2.pressing());
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

