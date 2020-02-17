#include "vex.h"

enum AutonMode{RedFront, RedBack, BlueFront, BlueBack, NONE};
AutonMode autonMode; //choose auton mode

SetUpScreen::SetUpScreen() {
  autonMode = NONE;
}

void SetUpScreen::displayMain() { //display main 
  Brain.Screen.clearScreen();

  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(white);

  //draw all the boxes
  Brain.Screen.drawRectangle(5, 60, 153, 86);
  Brain.Screen.drawRectangle(5, 150, 153, 86);
  Brain.Screen.drawRectangle(163, 60, 153, 86);
  Brain.Screen.drawRectangle(163, 150, 153, 86);
  Brain.Screen.drawRectangle(321, 60, 153, 86);
  Brain.Screen.drawRectangle(321, 150, 153, 86);

  Brain.Screen.setFillColor(blue);
  Brain.Screen.setFont(fontType::prop40);
  Brain.Screen.setCursor(1, 0);

  //display auton text line
  switch(autonMode) { 
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

  //display text in the box
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setFont(fontType::prop40);
  Brain.Screen.printAt(30, 117, "Cute");
  Brain.Screen.setFont(fontType::mono30);
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

//parameter: screen state
//0: home screen
//1: auton selection
void SetUpScreen::waitForInput(int Screen) {
  while(!Brain.Screen.pressing()){} //wait for the screen to be pressed
  task::sleep(250);
  int x = Brain.Screen.xPosition();
  int y = Brain.Screen.yPosition();
  if(Screen == 0) { //if at main screen
    if ((x > 160 && x < 320 && y > 55 && y < 148)) { //if pressed select auton
        //display auton route
        task::sleep(500);
        Brain.Screen.clearScreen();
        Brain.Screen.setFillColor(red);
        Brain.Screen.setPenColor(white);
        Brain.Screen.setFont(fontType::mono20);
        Brain.Screen.drawRectangle(5, 122, 232, 112);
        Brain.Screen.drawRectangle(5, 5, 232, 112);
        Brain.Screen.printAt(85, 60, "Red");
        Brain.Screen.printAt(95, 80, "Small");
        Brain.Screen.printAt(85, 177, "Red");
        Brain.Screen.printAt(105, 197, "Big");
        Brain.Screen.setFillColor(blue);
        Brain.Screen.drawRectangle(242, 5, 232, 112);
        Brain.Screen.drawRectangle(242, 122, 232, 112);
        Brain.Screen.printAt(312, 60, "Blue");
        Brain.Screen.printAt(327, 80, "Small");
        Brain.Screen.printAt(312, 177, "Blue");
        Brain.Screen.printAt(334, 197, "Big");
        Brain.Screen.render();
        waitForInput(1);
    } else if(x > 320 && x < 480 && y > 55 && y < 148) { //display skills
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
      userControl();
    } else if(x > 160 && x < 320 && y > 148 && y < 240) { //independent auton run
      if(autonMode != AutonMode::NONE) { //if auton is selected, run auton
        Brain.Screen.clearScreen(green);
        Brain.Screen.setFont(fontType::mono60);
        Brain.Screen.setCursor(3, 0);
        Brain.Screen.print("Running Auton");
        Brain.Screen.render();
        task::sleep(1000);
        autonomous(); //auton run
      } else { //if no auton is selected, display error message
        Brain.Screen.clearScreen(red);
        Brain.Screen.setFont(fontType::mono40);
        Brain.Screen.setCursor(3, 0);
        Brain.Screen.print("No Auton Selected");
        Brain.Screen.render();
        task::sleep(1000);
      }
      displayMain(); //return to main screen
    } else if(x > 320 && x < 480 && y > 148 && y < 240) { //competition selected!
        Brain.Screen.clearScreen(green);
        Brain.Screen.setFont(fontType::mono60);
        Brain.Screen.setCursor(3, 0);
        Brain.Screen.print("Competition");
        Brain.Screen.render();
        Competition.autonomous(autonomous);
        Competition.drivercontrol(userControl);
    } else if(x > 0 && x < 160 && y > 55 && y < 148) { //kawaiiiiiiiiiiiiii
      task::sleep(500);
      bool lastPressed = Brain.Screen.pressing();
      while(lastPressed) {}
      vex::thread t = thread(displayFinalScreen);
      while(!Brain.Screen.pressing()) {vex::this_thread::sleep_for(25);}
      t.interrupt();
      task::sleep(500);
      displayMain();
    } else {
      displayMain();
    }
  } else if(Screen == 1) {
    selectAuton(x, y);
    displayMain();
  }
}

//parameter: user's last click coordinate
void SetUpScreen::selectAuton(int x, int y) { //auton selection
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

void displayFinalScreen() { //恥ずかしい >o<
  while(true) {
    Brain.Screen.clearScreen();
    Brain.Screen.drawImageFromBuffer(uwu_map, 0, 0, sizeof(uwu_map));
    Brain.Screen.render();
    task::sleep(rand() % 200 + 100);
    Brain.Screen.drawImageFromBuffer(owo_map, 0, 0, sizeof(owo_map));
    Brain.Screen.render();
    task::sleep(rand() % 1000 + 500);
    vex::this_thread::sleep_for(25);
  }
}

void autonomous(void) { //run auton based on auton selected
  if(autonMode != NONE) {
    switch(autonMode) {
      case RedFront:
        autonRedFront();
        // oneCubeRed();
        break;
      case RedBack:
        // autonRedBack();
        oneCubeRed();
        break;
      case BlueFront:
        // autonBlueFront();
        oneCubeBlue();
        break;
      case BlueBack:
        // autonBlueBack();
        oneCubeBlue();
        break;
      default:
        Brain.Screen.clearScreen();
        Brain.Screen.setFont(fontType::mono40);
        Brain.Screen.print("Something is wrong.\nNo Auton");
    }
  }
}

void pre_auton() { //run value calibration and enter os
  Arm::getInstance() -> calcValue();
  angler.resetRotation();
  SetUpScreen setUp = SetUpScreen();
  setUp.displayMain();
}