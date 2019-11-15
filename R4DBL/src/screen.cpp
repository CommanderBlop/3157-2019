#include "vex.h"
enum AutonMode{RedFront, RedBack, BlueFront, BlueBack, NONE};
AutonMode autonMode;
SetUpScreen::SetUpScreen() {
  autonMode = NONE;
}

void SetUpScreen::displayMain() {
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

  switch(autonMode) { //display auton
    case RedFront:
      Brain.Screen.print("Current Auton: Red Front");
    case RedBack:
      Brain.Screen.print("Current Auton: Red Back");
    case BlueFront:
      Brain.Screen.print("Current Auton: Blue Front");
    case BlueBack:
      Brain.Screen.print("Current Auton: Blue Back");
    case NONE:
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

  Brain.Screen.render();

  waitForInput(0);
}

void SetUpScreen::waitForInput(int Screen) {
  while(!Brain.Screen.pressing()){}
  int x = Brain.Screen.xPosition();
  int y = Brain.Screen.yPosition();
  if(Screen == 0) {
    if ((x > 160 && x < 320 && y > 55 && y < 148)) {
      selectAuton(x, y);
      displayMain();
    } else if(x > 320 && x < 480 && y > 55 && y < 148) {
      //skills
    } else if(x > 0 && x < 160 && y > 148 && y < 240) {
      Brain.Screen.clearScreen(green);
      Brain.Screen.setFont(fontType::mono60);
      Brain.Screen.setCursor(3, 0);
      Brain.Screen.print("usercontrol");
      thread scr = thread(SetUpScreen::displayFinalScreen);
      //usercontrol();
    } else if(x > 160 && x < 320 && y > 148 && y < 240) {
      if(autonMode != NONE) {
          switch(autonMode) {
            case RedFront:
              autonRedFront();
            case RedBack:
              autonRedBack();
            case BlueFront:
              autonBlueFront();
            case BlueBack:
              autonBlueBack();
            default:;
          }
      } else {
        Brain.Screen.clearScreen(green);
        Brain.Screen.setFont(fontType::mono60);
        Brain.Screen.setCursor(3, 0);
        Brain.Screen.print("No Auton Selected");
        task::sleep(3000);
        displayMain();
      }
    } else if(x > 320 && x < 480 && y > 148 && y < 240) {
        Brain.Screen.clearScreen(green);
        Brain.Screen.setFont(fontType::mono60);
        Brain.Screen.setCursor(3, 0);
        Brain.Screen.print("Competition");
        thread scr = thread(SetUpScreen::displayFinalScreen);
        // Competition1.autonomous(autonomous);
        // Competition1.drivercontrol(usercontrol);
    }
  }
}

void SetUpScreen::selectAuton(int x, int y) {
  if (x < 240 && y < 120) {
    autonMode = RedFront;
  } else if (x < 240 && y > 120) {
    autonMode = RedBack;
  } else if (x > 240 && y < 120) {
    autonMode = BlueFront;
  } else if (x > 240 && y > 120) {
    autonMode = BlueBack;
  }
}

 void SetUpScreen::displayFinalScreen(void) {
  while(true) {
    Brain.Screen.clearScreen(ClrLightPink);
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setCursor(4,0);
    Brain.Screen.print("UwU");
    task::sleep(2000);
    Brain.Screen.clearScreen(ClrWhite);
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setCursor(4,0);
    Brain.Screen.print("OwO");
    task::sleep(2000);
    this_thread::yield();
  }
}

void autonomous(void) {
  if(autonMode != NONE) {
          switch(autonMode) {
            case RedFront:
              autonRedFront();
            case RedBack:
              autonRedBack();
            case BlueFront:
              autonBlueFront();
            case BlueBack:
              autonBlueBack();
            default:;
          }
  }
}

void pre_auton() {
  SetUpScreen setUp = SetUpScreen();
  setUp.displayMain();
}