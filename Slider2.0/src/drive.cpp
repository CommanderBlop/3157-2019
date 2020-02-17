#include "main.h"
#include "drive.hpp"
#include "jellyfish.hpp"

Drive::Drive() {
  //instantiate motorgroup
  okapi::MotorGroup left({okapi::Motor(19, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
					 okapi::Motor(20, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)});
  okapi::MotorGroup right({okapi::Motor(8, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                   okapi::Motor(7, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)});
  leftMotors = std::make_shared<MotorGroup> (left);
  rightMotors = std::make_shared<MotorGroup> (right);

  //setup the ChassisController and store in instance field
  chassis = ChassisControllerBuilder()
      .withMotors(leftMotors, rightMotors)
  		// .withGains(
  		// 		{0.5, 0.01, 0.0505}, // Distance controller gains
  		// 		{0, 0, 0}, // Turn controller gains
  		// 		{0, 0, 0}  // Angle con troller gains (helps drive straight)
  		// )
      // Green gearset, 4_in wheel diam, 10_in wheel track
      .withDimensions(AbstractMotor::gearset::green, {{4_in, 10_in}, imev5GreenTPR})
      // .withOdometry()
      // .buildOdometry();
      .build();
}

void Drive::opControlDrive(pros::Controller &joystick) {
  double arcadeY = (double) joystick.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)/127;
  double arcadeX = (double) joystick.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)/127;
  chassis->getModel()->arcade(arcadeY, arcadeX);
}
