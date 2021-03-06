#include "main.h"
#include "okapi/api.hpp"
#include "jellyfish.hpp"
using namespace okapi;
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);

	okapi::MotorGroup RightMotors({19, 20});
	okapi::MotorGroup LeftMotors({-11,-12});


}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	auto robot = Jellyfish::getInstance();
	robot->drive->chassis->turnAngle(20_deg);
	// auto chassis = ChassisControllerBuilder()
	// 	.withMotors(LeftMotors, RightMotors)
	// 	.withGains(
	// 			{0.001, 0, 0.0001}, // Distance controller gains
	// 			{0.001, 0, 0.0001}, // Turn controller gains
	// 			{0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
	// 	)
	// 	.withDimensions(AbstractMotor::gearset::green, {{4_in, 14_in}, imev5GreenTPR})
	// 	.withOdometry() // Use the same scales as the chassis (above)
	// 	.buildOdometry();
	//
	// chassis->setMaxVelocity(100);
	// chassis->setState({0_in, 0_in, 0_deg});
	// chassis->driveToPoint({2_ft, 2_ft});
	// chassis->turnToAngle(-45_deg);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// okapi::MotorGroup RightMotors({19, -20});
	// okapi::MotorGroup LeftMotors({-11,12});
	auto robot = Jellyfish::getInstance();
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	while(true) {
		robot->opControl(master);
	}
	// pros::ADIEncoder leftEncoder = pros::ADIEncoder('a', 'b');
	// pros::ADIEncoder rightEncoder = pros::ADIEncoder('c','d',true);
	// auto chassis = ChassisControllerBuilder()
	//     .withMotors(LeftMotors, RightMotors)
	// 		// .withGains(
	// 		// 		{0.005, 0, 0.0001}, // Distance controller gains
	// 		// 		{0.0027, 0, 0.0000001}, // Turn controller gains
	// 		// 		{0.005, 0, 0.0001}  // Angle controller gains (helps drive straight)
	// 		// )
	//     // Green gearset, 4 in wheel diam, 11.5 in wheel track
	//     .withDimensions(AbstractMotor::gearset::green, {{4_in, 10_in}, imev5GreenTPR})
	//     .build();
	// double distKP = 0.001;
	// double distKI = 0;
	// double distKD = 0.001;
	// auto chassis = ChassisControllerBuilder()
	// 	.withMotors(LeftMotors, RightMotors)
	// 	.withSensors(ADIEncoder('A', 'B'), ADIEncoder('C', 'D', true))
	// 	.withLogger(
  //       std::make_shared<Logger>(
  //           TimeUtilFactory::createDefault().getTimer(), // It needs a Timer
  //           "/ser/sout", // Output to the PROS terminal
  //           Logger::LogLevel::debug // Most verbose log level
  //       )
  //   )
	// 	.withGains(
	// 			{0.005, 0, 0.0001}, // Distance controller gains
	// 			{0.0027, 0, 0.0000001}, // Turn controller gains
	// 			{0.005, 0, 0.0001}  // Angle controller gains (helps drive straight)
	// 	)
	// 	.withDimensions(AbstractMotor::gearset::green, {{3_in, 14.5_in}, imev5GreenTPR})
	// 	.withOdometry() // Use the same scales as the chassis (above)
	// 	.buildOdometry();
	while(true) {
	// 	// if(master.get_digital(DIGITAL_RIGHT)) {
	// 	// 	distKP += 0.001;
	// 	// }
	// 	// if(master.get_digital(DIGITAL_LEFT)) {
	// 	// 	distKP -= 0.001;
	// 	// }
	// 	// if(master.get_digital(DIGITAL_R1)) {
	// 	// 	distKP += 0.001;
	// 	// }
	// 	// if(master.get_digital(DIGITAL_R2)) {
	// 	// 	distKP -= 0.001;
	// 	// }
	// 	// if(master.get_digital(DIGITAL_L1)) {
	// 	// 	distKP += 0.001;
	// 	// }
	// 	// if(master.get_digital(DIGITAL_L2)) {
	// 	// 	distKP -= 0.001;
	// 	// }
	// 	if(master.get_digital(DIGITAL_B)) {
	// 		//chassis->setMaxVelocity(80);
	// 		//chassis->setMaxVelocity(50);
	// 		chassis->turnAngle(90_deg);
	// 	}
	// 	//
	// 	if(master.get_digital(DIGITAL_A)) {
	// 		chassis->setMaxVelocity(100);
	// 		chassis->setState({0_in, 0_in, 0_deg});
	// 		chassis->driveToPoint({2_ft, 0_ft});
	// 		chassis->turnAngle(90_deg);
	// 		// chassis->moveDistance(2_ft);
	// 		// pros::delay(1000);
	// 		// chassis->moveDistance(-2_ft);
	// 	// 	while(!chassis->isSettled()) {}
	// 	}
	// 	//
	// 	pros::lcd::print(0, "%f, %f, %f", distKP, distKI, distKP);


		// chassis->setMaxVelocity(100);
		// chassis->setState({0_in, 0_in, 0_deg});
		// chassis->driveToPoint({0_ft, 2_ft});

		// Arcade drive with the left stick.
		// LeftMotors.moveVelocity((master.get_analog(ANALOG_RIGHT_X) + master.get_analog(ANALOG_LEFT_Y)));
		// RightMotors.moveVelocity((master.get_analog(ANALOG_RIGHT_X) - master.get_analog(ANALOG_LEFT_Y)));
		double arcadeY = (double) master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	  double arcadeX = (double) master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		// if(arcadeY < 5) arcadeY = 0;
		// if(arcadeX < 10) arcadeX = 0;
		LeftMotors.moveVelocity((arcadeY + arcadeX * 1.0)*2);
	  RightMotors.moveVelocity((arcadeY - arcadeX * 1.0)*2);
		pros::delay(25);
		//chassis->getModel()->arcade((arcadeY^2)/100,arcadeX*0.6);


    // Wait and give up the time we don't need to other tasks.
    // Additionally, joystick values, motor telemetry, etc. all updates every 10 ms.
  //   pros::delay(10);
	}
}
