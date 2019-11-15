using namespace vex;

//declare motors
extern brain Brain;
extern motor BackL;
extern motor BackR;
extern motor FrontL;
extern motor FrontR;
extern motor intakeL;
extern motor intakeR;
extern motor armL;
extern motor armR;
extern controller con;

//decalre global variable
extern double mode;




// VEXcode devices

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );