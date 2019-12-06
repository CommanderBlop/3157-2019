#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
competition Competition;
double ONE_TILE = 2000/3;

// VEXcode device constructors

motor      BackR(PORT1, gearSetting::ratio18_1, true);
motor      FrontR(PORT2, gearSetting::ratio18_1, true);
motor      BackL(PORT11, gearSetting::ratio18_1, false);
motor      FrontL(PORT4, gearSetting::ratio18_1, false);
motor      Hug(PORT9, gearSetting::ratio18_1, false);
motor      armL(PORT5, gearSetting::ratio6_1, true);
motor      armR(PORT6, gearSetting::ratio6_1, true);

controller con(controllerType::primary);

int mode = 0;
// VEXcode generated functions


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}