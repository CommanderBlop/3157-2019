#pragma once
#include "main.h"


using namespace okapi;

class Drive {
	public:
		Drive();
		std::shared_ptr<okapi::ChassisController> chassis;
		void opControlDrive(pros::Controller& joystick);
	private:
		std::shared_ptr<okapi::MotorGroup> leftMotors;
		std::shared_ptr<okapi::MotorGroup> rightMotors;
};
