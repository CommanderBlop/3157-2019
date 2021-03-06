#include "vex.h"
bool atMax = false;
bool atMin = false;
int minPos = 0;
//Button L1 - arm next position
void btnL1() {
  static bool lastPressed = con.ButtonL1.pressing();
  while (true) {
      if (con.ButtonL1.pressing()) {
        lastPressed = true;
        Hug.spin(directionType::rev, 25, velocityUnits::pct);
        double dist = fmax((Hug.rotation(rotationUnits::deg) - minPos), -1*(Hug.rotation(rotationUnits::deg) - minPos));
        if(atMin && dist > 20) atMin = false;
      }
      else if (!con.ButtonL1.pressing() && lastPressed) {
          lastPressed = false;
          Hug.stop(brakeType::coast);
      }
      this_thread::yield();
  }
}

//Button L2 - arm previous position
void btnL2() {
  static bool lastPressed = con.ButtonL2.pressing();
  while (true) {
      if (con.ButtonL2.pressing()) {
        if(Hug.torque(torqueUnits::Nm) < 0.8 && !atMin) {
          Hug.spin(directionType::fwd, 25, velocityUnits::pct);
        } else {
          Hug.spin(directionType::fwd, 5, velocityUnits::pct);
          while(Hug.torque(torqueUnits::Nm) < 0.8) {}
          Hug.stop(brakeType::hold);
          atMin = true;
        }
        lastPressed = true;
      }
      else if (!con.ButtonL2.pressing() && lastPressed) {
          lastPressed = false;
          Hug.stop(brakeType::hold);
          //Hugger::getInstance()->close();
          //con.rumble("*-*-*");
      }
      this_thread::yield();
  }
}

//Joystick - arcade drive
void joyStick() {
  bool lastMovedFwd = false;
  while (true) {
    double y = con.Axis3.position(pct);
    double x = con.Axis1.position(pct);

    if (fmax(x, x * -1) > 3 || fmax(y, y * -1) > 3) {
      lastMovedFwd = false;
    } else {
      lastMovedFwd = true;
    }
    if (fmax(y, y * -1) < 3 && fmax(x, x * -1) < 3) {
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
      BackL.spin(vex::directionType::fwd, y + x  * 0.75, vex::velocityUnits::pct);
      BackR.spin(vex::directionType::fwd, y - x  * 0.75, vex::velocityUnits::pct);
      FrontR.spin(vex::directionType::fwd, y - x  * 0.75, vex::velocityUnits::pct);
      FrontL.spin(vex::directionType::fwd, y + x * 0.75 , vex::velocityUnits::pct);
    }

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

//auto arm correction
void armCorrect() {
  while(true) {
    if(armL.isSpinning() && armR.isSpinning()) {
      int L = armL.rotation(rotationUnits::deg);
      int R = armR.rotation(rotationUnits::deg);
      if(L!= R) {
        armR.rotateFor(fwd, L-R, rotationUnits::deg);
      }
    }
    this_thread::yield();
  }
}

//start threads
void startThreads(){
  vex::thread L1 = thread(btnL1);
  vex::thread L2 = thread(btnL2);
  vex::thread joy = thread(joyStick);
  vex::thread correction = thread(armCorrect);
}

void userControl(void) {
  startThreads();
  while(1) {vex::this_thread::sleep_for(25);}
}

