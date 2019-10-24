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
competition Competition1;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;
vex::controller con(vex::controllerType::primary);
// define your global instances of motors and other devices here
vex::motor BackR(vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor FrontR(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor BackL(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor FrontL(vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor intakeL(vex::PORT9, vex::gearSetting::ratio18_1, false);
vex::motor intakeR(vex::PORT8, vex::gearSetting::ratio18_1, false);
vex::motor angler(vex::PORT5, vex::gearSetting::ratio36_1, false);
vex::motor bar(vex::PORT6, vex::gearSetting::ratio36_1, true);

vex::gyro Gyro = vex::gyro(Brain.ThreeWirePort.C);

double buffer = 1.0;
bool lastMovedFwd;

bool autonBlue1 = false;
bool autonRed1 = false;
bool autonBlue2 = false;
bool autonRed2 = false;
bool autonSkills = false;

bool disableAuton = true;
bool disableUC = true;

// Operating System

void initOS() {
  Brain.Screen.clearScreen();

  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);

  Brain.Screen.drawRectangle(5, 60, 153, 86);
  Brain.Screen.drawRectangle(5, 150, 153, 86);
  Brain.Screen.drawRectangle(163, 60, 153, 86);
  Brain.Screen.drawRectangle(163, 150, 153, 86);
  Brain.Screen.drawRectangle(321, 60, 153, 86);
  Brain.Screen.drawRectangle(321, 150, 153, 86);

  Brain.Screen.setFillColor(blue);
  Brain.Screen.setFont(fontType::prop40);
  Brain.Screen.setCursor(1, 0);
  if (autonRed1) {
    Brain.Screen.print("Current Auton: Red Route 1");
  } else if (autonRed2) {
    Brain.Screen.print("Current Auton: Red Route 2");
  } else if (autonBlue1) {
    Brain.Screen.print("Current Auton: Blue Route 1");
  } else if (autonBlue2) {
    Brain.Screen.print("Current Auton: Blue Route 2");
  } else {
    Brain.Screen.setFillColor(transparent);
    Brain.Screen.printAt(10, 37, "Current Auton: EMPTY");
    Brain.Screen.setFillColor(blue);
  }
  Brain.Screen.setFont(fontType::mono30);
  Brain.Screen.printAt(15, 112, "VOID");
  Brain.Screen.printAt(193, 98, "Select");
  Brain.Screen.printAt(201, 128, "Auton");
  Brain.Screen.printAt(357, 112, "Skills");
  Brain.Screen.printAt(38, 200, "Driver");
  Brain.Screen.printAt(210, 200, "Auton");
  Brain.Screen.setFont(fontType::mono20);
  Brain.Screen.printAt(340, 197, "Competition");

  // Brain.Screen.render();
}
void initOS(char msg[20]) {
  Brain.Screen.clearScreen();

  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);

  Brain.Screen.drawRectangle(5, 60, 153, 86);
  Brain.Screen.drawRectangle(5, 150, 153, 86);
  Brain.Screen.drawRectangle(163, 60, 153, 86);
  Brain.Screen.drawRectangle(163, 150, 153, 86);
  Brain.Screen.drawRectangle(321, 60, 153, 86);
  Brain.Screen.drawRectangle(321, 150, 153, 86);

  Brain.Screen.setFillColor(blue);
  Brain.Screen.setFont(fontType::prop40);
  Brain.Screen.setCursor(1, 0);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setPenColor(red);
  Brain.Screen.printAt(10, 37, msg);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setFont(fontType::mono30);
  Brain.Screen.printAt(15, 112, "VOID");
  Brain.Screen.printAt(193, 98, "Select");
  Brain.Screen.printAt(201, 128, "Auton");
  Brain.Screen.printAt(357, 112, "Skills");
  Brain.Screen.printAt(38, 200, "Driver");
  Brain.Screen.printAt(210, 200, "Auton");
  Brain.Screen.setFont(fontType::mono20);
  Brain.Screen.printAt(340, 197, "Competition");
  Brain.Screen.render();
  task::sleep(300);
}

void select() {
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFont(fontType::mono20);
  Brain.Screen.drawRectangle(5, 122, 232, 112);
  Brain.Screen.drawRectangle(5, 5, 232, 112);
  Brain.Screen.printAt(85, 60, "Red");
  Brain.Screen.printAt(95, 80, "Route 1");
  Brain.Screen.printAt(85, 177, "Red");
  Brain.Screen.printAt(105, 197, "Route 2");
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(242, 5, 232, 112);
  Brain.Screen.drawRectangle(242, 122, 232, 112);
  Brain.Screen.printAt(312, 60, "Blue");
  Brain.Screen.printAt(327, 80, "Route 1");
  Brain.Screen.printAt(312, 177, "Blue");
  Brain.Screen.printAt(334, 197, "Route 2");

  while (!Brain.Screen.pressing()) {
  }
  if (Brain.Screen.xPosition() < 240 && Brain.Screen.yPosition() < 120) {
    autonRed1 = true;
    autonBlue1 = false;
    autonRed2 = false;
    autonBlue2 = false;
  }

  else if (Brain.Screen.xPosition() < 240 && Brain.Screen.yPosition() > 120) {
    autonRed1 = false;
    autonBlue1 = false;
    autonRed2 = true;
    autonBlue2 = false;
  }

  else if (Brain.Screen.xPosition() > 240 && Brain.Screen.yPosition() < 120) {
    autonRed1 = false;
    autonBlue1 = true;
    autonRed2 = false;
    autonBlue2 = false;
  }

  else if (Brain.Screen.xPosition() > 240 && Brain.Screen.yPosition() > 120) {
    autonRed1 = false;
    autonBlue1 = false;
    autonRed2 = false;
    autonBlue2 = true;
  }
}

// Autonomous Functions

void intakeIn() {
  intakeR.spin(directionType::rev, 75, velocityUnits::pct);
  intakeL.spin(directionType::rev, 75, velocityUnits::pct);
}
void intakeOut() {
  intakeR.spin(directionType::fwd, 75, velocityUnits::pct);
  intakeL.spin(directionType::fwd, 75, velocityUnits::pct);
}

void moveForward(double power, double angle, double time, double shawnMendes,
                 bool ramp) {
  if (power < 0 || angle < 0 || time < 0) {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(0, 0, 2000, 2000);
    Brain.Screen.setCursor(3, 2);
    Brain.Screen.print("No negative numbers!");
    vex::task::sleep(3000);
  }

  double angleMoved;
  BackR.resetRotation();
  BackL.resetRotation();
  FrontR.resetRotation();
  FrontL.resetRotation();
  Brain.resetTimer();

  for (double i = 0; i < 100; i++) {
    BackR.spin(vex::directionType::fwd, power * (i / 100), pct);
    BackL.spin(vex::directionType::fwd, shawnMendes * (power * (i / 100)), pct);
    FrontR.spin(vex::directionType::fwd, power * (i / 100), pct);
    FrontL.spin(vex::directionType::fwd, shawnMendes * (power * (i / 100)),
                pct);
    vex::task::sleep(time / 100);
    Brain.Screen.setFont(fontType::mono20);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Timer: %3.1f", Brain.timer(timeUnits::msec));
  }

  angleMoved =
      (BackR.rotation(rotationUnits::deg) + BackL.rotation(rotationUnits::deg) +
       FrontR.rotation(rotationUnits::deg) +
       FrontL.rotation(rotationUnits::deg)) /
      4;
  if (ramp) {
    angleMoved = angleMoved / 2;
  }
  Brain.Screen.setCursor(2, 1);
  Brain.Screen.print(
      "BR: %3.1f/BL: %3.1f/FR: %3.1f/FL: %3.1f",
      BackR.rotation(rotationUnits::deg), BackL.rotation(rotationUnits::deg),
      FrontR.rotation(rotationUnits::deg), FrontL.rotation(rotationUnits::deg));
  Brain.Screen.setCursor(3, 1);
  Brain.Screen.print("Rampup Angle: %3.1f", angleMoved);
  Brain.Screen.setCursor(4, 1);
  Brain.Screen.print("MoveFor: %3.1f", (angle - (2 * angleMoved)));

  if ((angle - (2 * angleMoved)) < 0) {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(0, 0, 2000, 2000);
    Brain.Screen.setCursor(3, 2);
    Brain.Screen.print("Error duration is: %3.1f", (angle - (2 * angleMoved)));
    vex::task::sleep(3000);
  }

  BackR.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
  BackL.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
  FrontR.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
  FrontL.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);

  while (((BackR.rotation(rotationUnits::deg) +
           BackL.rotation(rotationUnits::deg) +
           FrontR.rotation(rotationUnits::deg) +
           FrontL.rotation(rotationUnits::deg)) /
          4) < (angle - (2 * angleMoved))) {
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("Currently: %3.1f",
                       ((BackR.rotation(rotationUnits::deg) +
                         BackL.rotation(rotationUnits::deg) +
                         FrontR.rotation(rotationUnits::deg) +
                         FrontL.rotation(rotationUnits::deg)) /
                        4));
  }

  if (ramp) {
    for (double i = 0; i < 100; i++) {
      BackR.spin(vex::directionType::fwd,
                 shawnMendes * (power * (1 - (i / 100))),
                 vex::velocityUnits::pct);
      BackL.spin(vex::directionType::fwd, power * (1 - (i / 100)),
                 vex::velocityUnits::pct);
      FrontR.spin(vex::directionType::fwd,
                  shawnMendes * (power * (1 - (i / 100))),
                  vex::velocityUnits::pct);
      FrontL.spin(vex::directionType::fwd, power * (1 - (i / 100)),
                  vex::velocityUnits::pct);
      vex::task::sleep(time / 100);
      Brain.Screen.setCursor(6, 1);
      Brain.Screen.print("FLSpeed: %3.1f", power * (1 - (i / 100)));
    }
  }

  Brain.Screen.setCursor(7, 1);
  Brain.Screen.print(
      "BR: %3.1f/BL: %3.1f/FR: %3.1f/FL: %3.1f",
      BackR.rotation(rotationUnits::deg), BackL.rotation(rotationUnits::deg),
      FrontR.rotation(rotationUnits::deg), FrontL.rotation(rotationUnits::deg));
  Brain.Screen.setCursor(8, 1);
  Brain.Screen.print("Complete fwd(%3.1f,%3.1f,%3.1f)", power, angle, time);

  FrontR.stop(brakeType::hold);
  FrontL.stop(brakeType::hold);
  BackR.stop(brakeType::hold);
  BackL.stop(brakeType::hold);
}

void moveBackward(double power, double angle, double time, double shawnMendes) {
  if (power < 0 || angle < 0 || time < 0) {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(0, 0, 2000, 2000);
    Brain.Screen.setCursor(3, 2);
    Brain.Screen.print("No negative numbers!");
    vex::task::sleep(3000);
  }

  angle = angle * -1;
  power = power * -1;
  double angleMoved;
  BackR.resetRotation();
  BackL.resetRotation();
  FrontR.resetRotation();
  FrontL.resetRotation();
  Brain.resetTimer();

  for (double i = 0; i < 100; i++) {
    BackR.spin(vex::directionType::fwd, power * (i / 100), pct);
    BackL.spin(vex::directionType::fwd, shawnMendes * (power * (i / 100)), pct);
    FrontR.spin(vex::directionType::fwd, power * (i / 100), pct);
    FrontL.spin(vex::directionType::fwd, shawnMendes * (power * (i / 100)),
                pct);
    vex::task::sleep(time / 100);
    Brain.Screen.setFont(fontType::mono20);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Timer: %3.1f", Brain.timer(timeUnits::msec));
  }

  angleMoved =
      (BackR.rotation(rotationUnits::deg) + BackL.rotation(rotationUnits::deg) +
       FrontR.rotation(rotationUnits::deg) +
       FrontL.rotation(rotationUnits::deg)) /
      4;

  Brain.Screen.setCursor(2, 1);
  Brain.Screen.print(
      "BR: %3.1f/BL: %3.1f/FR: %3.1f/FL: %3.1f",
      BackR.rotation(rotationUnits::deg), BackL.rotation(rotationUnits::deg),
      FrontR.rotation(rotationUnits::deg), FrontL.rotation(rotationUnits::deg));
  Brain.Screen.setCursor(3, 1);
  Brain.Screen.print("Rampup Angle: %3.1f", angleMoved);
  Brain.Screen.setCursor(4, 1);
  Brain.Screen.print("MoveFor: %3.1f", (angle - (2 * angleMoved)));

  if ((angle - (2 * angleMoved)) > 0) {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(0, 0, 2000, 2000);
    Brain.Screen.setCursor(3, 2);
    Brain.Screen.print("Error duration is: %3.1f", (angle - (2 * angleMoved)));
    vex::task::sleep(3000);
  }

  BackR.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
  BackL.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
  FrontR.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
  FrontL.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);

  Brain.Screen.setCursor(5, 1);
  Brain.Screen.print("Main did NOT run");

  while (((BackR.rotation(rotationUnits::deg) +
           BackL.rotation(rotationUnits::deg) +
           FrontR.rotation(rotationUnits::deg) +
           FrontL.rotation(rotationUnits::deg)) /
          4) > (angle - (2 * angleMoved))) {
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("Currently: %3.1f",
                       ((BackR.rotation(rotationUnits::deg) +
                         BackL.rotation(rotationUnits::deg) +
                         FrontR.rotation(rotationUnits::deg) +
                         FrontL.rotation(rotationUnits::deg)) /
                        4));
  }

  for (double i = 0; i < 100; i++) {
    BackR.spin(vex::directionType::fwd, shawnMendes * (power * (1 - (i / 100))),
               vex::velocityUnits::pct);
    BackL.spin(vex::directionType::fwd, power * (1 - (i / 100)),
               vex::velocityUnits::pct);
    FrontR.spin(vex::directionType::fwd,
                shawnMendes * (power * (1 - (i / 100))),
                vex::velocityUnits::pct);
    FrontL.spin(vex::directionType::fwd, power * (1 - (i / 100)),
                vex::velocityUnits::pct);
    vex::task::sleep(time / 100);
    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print("FLSpeed: %3.1f", power * (1 - (i / 100)));
  }

  Brain.Screen.setCursor(7, 1);
  Brain.Screen.print(
      "BR: %3.1f/BL: %3.1f/FR: %3.1f/FL: %3.1f",
      BackR.rotation(rotationUnits::deg), BackL.rotation(rotationUnits::deg),
      FrontR.rotation(rotationUnits::deg), FrontL.rotation(rotationUnits::deg));
  Brain.Screen.setCursor(8, 1);
  Brain.Screen.print("Complete rev(%3.1f,%3.1f,%3.1f)", power, angle, time);

  FrontL.stop();
  FrontR.stop();
  BackL.stop();
  BackR.stop();
}

void turnRight(double degree) {
  double curr = Gyro.value(rotationUnits::deg);
  BackR.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  BackL.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  FrontR.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  FrontL.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  while (curr - Gyro.value(rotationUnits::deg) < degree - 28) {
    task::sleep(5);
  }
  FrontL.stop(brakeType::hold);
  FrontR.stop(brakeType::hold);
  BackL.stop(brakeType::hold);
  BackR.stop(brakeType::hold);
}

void turnLeft(double degree) {
  double curr = Gyro.value(rotationUnits::deg);
  BackR.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  BackL.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  FrontR.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
  FrontL.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
  while (Gyro.value(rotationUnits::deg) - curr < degree - 28) {
    task::sleep(5);
  }
  FrontL.stop(brakeType::hold);
  FrontR.stop(brakeType::hold);
  BackL.stop(brakeType::hold);
  BackR.stop(brakeType::hold);
}

// Drive Functions

int drive() {
  while (true) {

    double y = con.Axis3.position(pct) * buffer;
    double x = con.Axis1.position(pct) * buffer * 0.73;

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
  }
}

void barD() {
  if (con.ButtonUp.pressing()) {
    bar.spin(directionType::rev, 100, velocityUnits::pct);
  } else if (con.ButtonDown.pressing()) {
    bar.spin(directionType::fwd, 100, velocityUnits::pct);
  } else {
    bar.stop(brakeType::brake);
  }
}

void intakeD() {
  if (con.ButtonL1.pressing()) {
    intakeL.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
    intakeR.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
  } else if (con.ButtonL2.pressing()) {
    intakeL.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
    intakeR.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
  } else {
    intakeL.stop(brakeType::hold);
    intakeR.stop(brakeType::hold);
  }
}

void anglerD() {

  if (con.ButtonR1.pressing()) {
    angler.spin(vex::directionType::fwd, 20, vex::velocityUnits::pct);
  } else if (con.ButtonR2.pressing()) {
    angler.spin(directionType::rev, 20, velocityUnits::pct);
  } else {
    angler.stop(brakeType::brake);
  }
}

void autonomous( void )
{
  while(disableAuton){
        Brain.Screen.clearScreen();
        Brain.Screen.setFillColor(blue);
        Brain.Screen.setPenColor(white);
        Brain.Screen.printAt(5,38,"Auton Disabled");
        task::sleep(200);
  }
  
  if(autonSkills)
    {

    }

    //Route 1 - 5 Points

    else if(autonRed1)
    {
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(fontType::mono60);
      Brain.Screen.setCursor(1,0);
      Brain.Screen.print(" Red Route 1");

      //Start Between R1-5 R1-6

      //move forward + flip out

      //suck preload

      //suck four cubes R2-5 to R3-5

      //Score
    }

    //Route 2 - 6 Points

    else if(autonRed2)
    {
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(fontType::mono60);
      Brain.Screen.setCursor(1,0);
      Brain.Screen.print("Red Route 2");

      //Start Between R1-2

      //expand

      //suck preload

      //suck R2-2

      //suck 2 of R3-2

      //turn around R2-1

      //Score
    }

    else if(autonBlue1)
    {
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(fontType::mono60);
      Brain.Screen.setCursor(1,0);
      Brain.Screen.print("Blue Route 1");
    }

    else if(autonBlue2)
    {
      Brain.Screen.clearScreen();
      Brain.Screen.setFont(fontType::mono60);
      Brain.Screen.setCursor(1,0);
      Brain.Screen.print("Blue Route 2");
    }
}

void usercontrol()
{
    while(disableUC){
        Brain.Screen.clearScreen();
        Brain.Screen.setFillColor(blue);
        Brain.Screen.setPenColor(white);
        Brain.Screen.printAt(5,38,"UC Disabled. Why is controller");
        Brain.Screen.printAt(5,58,"Connected? Right mode?");
        task::sleep(200);
    }
}

void OSPressed() {
  while (!Brain.Screen.pressing()) {
  }
  task::sleep(500);
  if ((Brain.Screen.xPosition() > 160 &&
              Brain.Screen.xPosition() < 320 && Brain.Screen.yPosition() > 55 &&
              Brain.Screen.yPosition() < 148)) {
    select();
  } else if ((Brain.Screen.xPosition() > 320 &&
              Brain.Screen.xPosition() < 480 && Brain.Screen.yPosition() > 55 &&
              Brain.Screen.yPosition() < 148)) {
    Brain.Screen.clearScreen(green);
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setCursor(3, 0);
    Brain.Screen.print("Click Skills");
    autonSkills = true;
    disableUC = true;
    disableAuton = false;
    autonomous();
    // autonSkills = false;
  } else if ((Brain.Screen.xPosition() > 0 && Brain.Screen.xPosition() < 160 &&
              Brain.Screen.yPosition() > 148 &&
              Brain.Screen.yPosition() < 240)) {
    Brain.Screen.clearScreen(green);
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setCursor(3, 0);
    Brain.Screen.print("Click UC");
    disableUC = false;
    disableAuton = true;
    usercontrol();
  } else if ((Brain.Screen.xPosition() > 160 &&
              Brain.Screen.xPosition() < 320 &&
              Brain.Screen.yPosition() > 148 &&
              Brain.Screen.yPosition() < 240)) {
    if (!autonRed1 && !autonBlue1 && !autonRed2 && !autonBlue2 &&
        !autonSkills) {
      initOS("No Auton Selected");
    } else {
      Brain.Screen.clearScreen(green);
      Brain.Screen.setFont(fontType::mono60);
      Brain.Screen.setCursor(3, 0);
      Brain.Screen.print("Click Auton");
      disableUC = true;
      disableAuton = false;
      autonomous();
    }

  } else if ((Brain.Screen.xPosition() > 320 &&
              Brain.Screen.xPosition() < 480 &&
              Brain.Screen.yPosition() > 148 &&
              Brain.Screen.yPosition() < 240)) {
    if (!autonRed1 && !autonBlue1 && !autonRed2 && !autonBlue2 &&
        !autonSkills) {
      initOS("No Auton Selected");
    } else {
      Brain.Screen.clearScreen(green);
      Brain.Screen.setFont(fontType::mono60);
      Brain.Screen.setCursor(3, 0);
      Brain.Screen.print("Click Comp");
      disableUC = false;
      disableAuton = false;
      Competition1.autonomous(autonomous);
      Competition1.drivercontrol(usercontrol);
    }
  }
  task::sleep(1000);
}

void OS() {
  while (disableUC && disableAuton) {
    initOS();
    OSPressed();
    task::sleep(50);
  }
  if (!disableUC && !disableAuton) {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setFillColor(red);
    Brain.Screen.setPenColor(white);
    Brain.Screen.setCursor(3, 0);
    Brain.Screen.print("Comp Loaded");
  } else if (!disableUC) {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setFillColor(red);
    Brain.Screen.setPenColor(white);
    Brain.Screen.setCursor(3, 0);
    Brain.Screen.print("UC Loaded");
  } else if (!disableAuton) {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setFillColor(red);
    Brain.Screen.setPenColor(white);
    Brain.Screen.setCursor(3, 0);
    Brain.Screen.print("Auton Loaded");
  }
}

// Main

int main() {
/*
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(fontType::mono40);
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setCursor(3, 0);
  Brain.Screen.print("Gyro Calibration");
  task::sleep(500);
  Brain.Screen.clearLine();
  Brain.Screen.print("Gyro Calibration Started");
  Gyro.startCalibration();

  OS();*/

  while (1) {
    drive();

    float angleA = angler.rotation(rotationUnits::deg);
    float angleB = bar.rotation(rotationUnits::deg);

    Brain.Screen.setFont(fontType::mono20);
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Angler Angle: %3.1f", angleA);
    Brain.Screen.newLine();
    Brain.Screen.print("Bar Angle: %3.1f", angleB);
  }
}
