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
      Brain.Screen.setFillColor(red);
      Brain.Screen.print("Current Auton: Red Front");
      break;
    case RedBack:
      Brain.Screen.setFillColor(red);
      Brain.Screen.print("Current Auton: Red Back");
      break;
    case BlueFront:
      Brain.Screen.setFillColor(blue);
      Brain.Screen.print("Current Auton: Blue Front");
      break;
    case BlueBack:
      Brain.Screen.setFillColor(blue);
      Brain.Screen.print("Current Auton: Blue Back");
      break;
    case NONE:
      Brain.Screen.setFillColor(transparent);
      Brain.Screen.print("Current Auton: EMPTY");
      Brain.Screen.setFillColor(blue);
  }
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

  waitForInput(0);
}

void SetUpScreen::waitForInput(int Screen) {
  while(!Brain.Screen.pressing()){}
  task::sleep(250);
  int x = Brain.Screen.xPosition();
  int y = Brain.Screen.yPosition();
  if(Screen == 0) {
    if ((x > 160 && x < 320 && y > 55 && y < 148)) {
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
        Brain.Screen.render();
        waitForInput(1);
    } else if(x > 320 && x < 480 && y > 55 && y < 148) {
      Brain.Screen.clearScreen(red);
      Brain.Screen.setFont(fontType::mono20);
      Brain.Screen.setCursor(3, 0);
      Brain.Screen.print("Haven't Made Skills Yet:(");
      Brain.Screen.render();
      task::sleep(2000); 
      displayMain();
      //skills
    } else if(x > 0 && x < 160 && y > 148 && y < 240) { //usercontrol
      Brain.Screen.clearScreen(green);
      Brain.Screen.setFont(fontType::mono60);
      Brain.Screen.setCursor(3, 0);
      Brain.Screen.print("usercontrol");
      Brain.Screen.render();
      
      vex::thread t = thread(displayFinalScreen);
      userControl();
    } else if(x > 160 && x < 320 && y > 148 && y < 240) { //auton Run
      if(autonMode != AutonMode::NONE) {
        Brain.Screen.clearScreen(green);
        Brain.Screen.setFont(fontType::mono60);
        Brain.Screen.setCursor(3, 0);
        Brain.Screen.print("Running Auton");
        Brain.Screen.render();
        task::sleep(1000);
        autonomous();
      } else {
        Brain.Screen.clearScreen(red);
        Brain.Screen.setFont(fontType::mono40);
        Brain.Screen.setCursor(3, 0);
        Brain.Screen.print("No Auton Selected");
        Brain.Screen.render();
        task::sleep(1000);
      }
      displayMain();
    } else if(x > 320 && x < 480 && y > 148 && y < 240) {
        Brain.Screen.clearScreen(green);
        Brain.Screen.setFont(fontType::mono60);
        Brain.Screen.setCursor(3, 0);
        Brain.Screen.print("Competition");
        Brain.Screen.render();
        vex::thread t = thread(displayFinalScreen);
        while(true) {vex::this_thread::sleep_for(25);}
        // Competition1.autonomous(autonomous);
        // Competition1.drivercontrol(usercontrol);
    } else {
      displayMain();
    }
  } else if(Screen == 1) {
    selectAuton(x, y);
    displayMain();
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

 int displayFinalScreen() {
  while(true) {
    Brain.Screen.clearScreen(ClrPink);
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setCursor(3,6);
    Brain.Screen.setPenColor(white);
    Brain.Screen.setFillColor(ClrPink);
    Brain.Screen.print("UwU");
    Brain.Screen.render();
    task::sleep(2000);
    Brain.Screen.setPenColor(ClrMistyRose);
    Brain.Screen.clearScreen(white);
    Brain.Screen.setFont(fontType::mono60);
    Brain.Screen.setCursor(3,6);
    Brain.Screen.setFillColor(white);
    Brain.Screen.print("OwO");
    Brain.Screen.render();
    task::sleep(2000);
    vex::this_thread::sleep_for(25);
  }
}

void autonomous(void) {
  if(autonMode != NONE) {
          switch(autonMode) {
            case RedFront:
              autonRedFront();
              break;
            case RedBack:
              autonRedBack();
              break;
            case BlueFront:
              autonBlueFront();
              break;
            case BlueBack:
              autonBlueBack();
              break;
            default:
              Brain.Screen.clearScreen();
              Brain.Screen.setFont(fontType::mono40);
              Brain.Screen.print("Something is wrong.\nNo Auton");
          }
  }
}

void pre_auton() {
  SetUpScreen setUp = SetUpScreen();
  setUp.displayMain();
}