#include "main.h"
#include "drive.hpp"
#include "jellyfish.hpp"

Drive::Drive() {
  //instantiate motorgroup
  okapi::MotorGroup left({okapi::Motor(12, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
					 okapi::Motor(11, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)});
  okapi::MotorGroup right({okapi::Motor(19, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                   okapi::Motor(20, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)});
  leftMotors = std::make_shared<MotorGroup> (left);
  rightMotors = std::make_shared<MotorGroup> (right);

  //setup the ChassisController and store in instance field
  chassis = ChassisControllerBuilder()
      .withMotors(leftMotors, rightMotors)
  		// .withGains(
  		// 		{0.005, 0, 0.0001}, // Distance controller gains
  		// 		{0.0027, 0, 0.0000001}, // Turn controller gains
  		// 		{0.005, 0, 0.0001}  // Angle controller gains (helps drive straight)
  		// )
      // Green gearset, 4_in wheel diam, 10_in wheel track
      .withDimensions(AbstractMotor::gearset::green, {{4_in, 10_in}, imev5GreenTPR})
      .withOdometry()
      .buildOdometry();
}

void Drive::opControlDrive(pros::Controller &joystick) {
  double arcadeY = (double) joystick.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)/127;
  double arcadeX = (double) joystick.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)/127;
  // if(arcadeX < 10 && arcadeX > -10) arcadeX = 0.0;
  // else arcadeX = (arcadeX * arcadeX)/100;
  // arcadeY = (arcadeY * arcadeY)/100.0;
  chassis->getModel()->arcade(arcadeY, arcadeX);
}
