#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors

// VEXcode generated functions

vex::controller con(vex::controllerType::primary);

vex::motor BackR(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::motor FrontR(vex::PORT12, vex::gearSetting::ratio18_1, true);
vex::motor BackL(vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor FrontL(vex::PORT19, vex::gearSetting::ratio18_1, false);

vex::motor intakeL(vex::PORT9, vex::gearSetting::ratio18_1, false);
vex::motor intakeR(vex::PORT8, vex::gearSetting::ratio18_1, false);

vex::motor angler(vex::PORT15, vex::gearSetting::ratio36_1, true);

vex::motor bar(vex::PORT5, vex::gearSetting::ratio36_1, false);

competition Competition;
double ONE_TILE = 2000/3;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}