#include "vex.h"

int ANGLER_LIMIT = -550; //the limit of the angler
bool raise = false;
bool raising = false;
//arm up
void btnR1() {
  static bool lastPressed = con.ButtonR1.pressing();
    while (true) {
        if (con.ButtonR1.pressing()) {
          lastPressed = true;
          // if(angler.rotation(rotationUnits::deg) > -400 && !raise) {
          //   angler.rotateTo(-450, rotationUnits::deg, -45, velocityUnits::pct, false);
          //   raising = true;
          // } else if(angler.rotation(rotationUnits::deg) < -400 && !raising){
          //   raising = false;
          //   raise = true;
          // }
          bar.spin(directionType::fwd, 90, velocityUnits::pct);
          
        } 
        else if (!con.ButtonR1.pressing() && lastPressed) {
            lastPressed = false;
            bar.stop(brakeType::hold);
            // raise = false;
        }
        this_thread::yield(); 
    }
}

//arm down
void btnR2() {
  static bool lastPressed = con.ButtonR2.pressing();
    while (true) {
        if (con.ButtonR2.pressing()) {
          lastPressed = true;
          bar.spin(directionType::rev, 90, velocityUnits::pct);
        } 
        else if (!con.ButtonR2.pressing() && lastPressed) {
            lastPressed = false;
            bar.stop(brakeType::hold);
            
        }
        this_thread::yield(); 
    }
}

//Intake in
void btnL1() {
  static bool lastPressed = con.ButtonL1.pressing();
    while (true) {
        if (con.ButtonL1.pressing()) {
          lastPressed = true;
          intakeL.spin(directionType::fwd, 75, velocityUnits::pct);
          intakeR.spin(directionType::rev, 75, velocityUnits::pct);
        }

        else if (!con.ButtonL1.pressing() && lastPressed) {
            lastPressed = false;
            intakeL.stop(brakeType::coast);
            intakeR.stop(brakeType::coast);
            //Intake::getInstance() -> nextPos();
        }
        this_thread::yield();
    }
}

//intake out
void btnL2() {
  static bool lastPressed = con.ButtonL2.pressing();
    while (true) {
        if (con.ButtonL2.pressing()) {
          lastPressed = true;
          intakeL.spin(directionType::rev, 75, velocityUnits::pct);
          intakeR.spin(directionType::fwd, 75, velocityUnits::pct);
        }
        else if (!con.ButtonL2.pressing() && lastPressed) {
            lastPressed = false;
            intakeL.stop(brakeType::coast);
            intakeR.stop(brakeType::coast);
            //Intake::getInstance() -> prevPos();
        }
        this_thread::yield(); 
    }
}

//R1 - slider down
//R2 - slider up
/*void slide() {
  while(true) {
    if(con.ButtonR1.pressing() && angler.rotation(rotationUnits::deg) >= ANGLER_LIMIT) {
      angler.spin(directionType::rev, 25, velocityUnits::pct);
    } else if(con.ButtonR2.pressing() && angler.rotation(rotationUnits::deg) <= 0) {
      angler.spin(directionType::fwd, 25, velocityUnits::pct);
    } else {
      angler.stop(brake);
    }
    this_thread::yield();
  }
}*/

//arcade drive w arm up and down
void joyStick() {
  bool lastMovedFwd = false;
  while (true) {

    double y = con.Axis3.position(pct);
    double x = con.Axis1.position(pct);

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
    } else { //mac likes 0.6 on turn
      BackR.spin(vex::directionType::fwd, y - x * 0.6, vex::velocityUnits::pct);
      FrontR.spin(vex::directionType::fwd, y - x * 0.6, vex::velocityUnits::pct);
      BackL.spin(vex::directionType::fwd, y + x * 0.6, vex::velocityUnits::pct);
      FrontL.spin(vex::directionType::fwd, y + x * 0.6, vex::velocityUnits::pct);
    }

    if(con.Axis2.position(pct) < -7 || con.Axis2.position(pct) > 7) {
          angler.spin(vex::directionType::fwd, 0.75 * con.Axis2.position(pct), vex::velocityUnits::pct);
    } else {
          angler.stop(brakeType::hold);
    }
    this_thread::yield();
  }
}

//Button Up - reach for mid tower 
void btnUp() {
  static bool lastPressed = con.ButtonUp.pressing();
    while (true) {
        if (con.ButtonUp.pressing()) lastPressed = true;
        else if (!con.ButtonUp.pressing() && lastPressed) {
            lastPressed = false;
            Arm::getInstance() -> highTower();
        }
        this_thread::yield(); 
    }
}

//Button Down - reach for low tower
void btnDown() {
  static bool lastPressed = con.ButtonRight.pressing();
    while (true) {
        if (con.ButtonDown.pressing()) lastPressed = true;
        else if (!con.ButtonDown.pressing() && lastPressed) {
            lastPressed = false;
            Arm::getInstance() -> lowTower();
        }
        this_thread::yield(); 
    }
}


void startThreads() {
  vex::thread L1 = thread(btnL1);
  vex::thread L2 = thread(btnL2);
  vex::thread R1 = thread(btnR1);
  vex::thread R2 = thread(btnR2);
  vex::thread joy = thread(joyStick);
  vex::thread Up = thread(btnUp);
  vex::thread Down = thread(btnDown);
  //vex::thread slider = thread(slide);
  vex::thread t = thread(displayFinalScreen);
}

void GyroDisplay() {
  Brain.Screen.setFont(fontType::mono60);
  while(true) {
    Brain.Screen.clearLine();
    Brain.Screen.print(Gyro.value(rotationUnits::deg));
    Brain.Screen.render();
    this_thread::yield(); 
  }
}


void userControl(void) {
  startThreads(); //start the threads for controller
  while(1) {vex::this_thread::sleep_for(25);}
}

