#include "main.h"
#include "drive.hpp"
#include "jellyfish.hpp"

Drive::Drive() {
  okapi::MotorGroup left({okapi::Motor(12, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
					 okapi::Motor(11, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)});
  okapi::MotorGroup right({okapi::Motor(19, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                   okapi::Motor(20, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)});
  leftMotors = std::shared_ptr<MotorGroup> (left);
  rightMotors = std::shared_ptr<MotorGroup> (right);
  chassis = ChassisControllerBuilder()
      .withMotors(LeftMotors, RightMotors)
  		// .withGains(
  		// 		{0.005, 0, 0.0001}, // Distance controller gains
  		// 		{0.0027, 0, 0.0000001}, // Turn controller gains
  		// 		{0.005, 0, 0.0001}  // Angle controller gains (helps drive straight)
  		// )
      // Green gearset, 4 in wheel diam, 11.5 in wheel track
      .withDimensions(AbstractMotor::gearset::green, {{4_in, 10_in}, imev5GreenTPR})
      .withOdometry()
      .buildOdometry();
}

void Drive::opControlDrive(pros::Controller &joystick) {
  double arcadeY = (double) joystick.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  double arcadeX = (double) joystick.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
  // if(arcadeY < 5) arcadeY = 0;
  // if(arcadeX < 10) arcadeX = 0;
  // LeftMotors.moveVelocity((arcadeY + arcadeX * 1.0)*2);
  // RightMotors.moveVelocity((arcadeY - arcadeX * 1.0)*2);
  chassis->getModel()->arcade(arcadeY, arcadeX);
  pros::delay(25);
}
