#include "main.h"

#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT 10
#define ARM_PORT 8
#define CLAW_PORT 3
#define LEFT_BUMPER_PORT 'a'
#define RIGHT_BUMPER_PORT 'b'
#define ARM_LIMIT_SWITCH_PROT 'h'
#define MOTOR_PORT 2

void tankControl()
{
	pros::Motor left_wheels (LEFT_WHEELS_PORT);
	pros::Motor right_wheels (RIGHT_WHEELS_PORT, true);
	pros::Controller master (CONTROLLER_MASTER);

	while (true)
	{
		left_wheels.move(master.get_analog(ANALOG_LEFT_Y));
		right_wheels.move(master.get_analog(ANALOG_RIGHT_Y));

		pros::delay(2);
	}
}

void arcadeControl()
{
	pros::Motor left_wheels (LEFT_WHEELS_PORT);
	pros::Motor right_wheels (RIGHT_WHEELS_PORT, true);
	pros::Controller master (CONTROLLER_MASTER);

	while(true)
	{
		int power = master.get_analog(ANALOG_LEFT_Y);
		int turn = master.get_analog(ANALOG_LEFT_Y);
		int left = power + turn;
		int right = power - turn;

		left_wheels.move(left);
		right_wheels.move(right);

		pros::delay(2);
	}
}

void armControl()
{
	pros::Motor arm (ARM_PORT, MOTOR_GEARSET_36);
	pros::Controller master (CONTROLLER_MASTER);

	while (true)
	{
		if (master.get_digital(DIGITAL_R1))
		{
			arm.move_velocity(100);
		}
		else if (master.get_digital(DIGITAL_R2))
		{
			arm.move_velocity(-100);
		}
		else
		{
			arm.move_velocity(0);
		}

		pros::delay(2);
	}
}

void clawControl()
{
	pros::Motor claw (CLAW_PORT, MOTOR_GEARSET_36);
	pros::Controller master (CONTROLLER_MASTER);

	while (true)
	{
		if (master.get_digital(DIGITAL_L1))
		{
			claw.move_velocity(100);
		}
		else if (master.get_digital(DIGITAL_L2))
		{
			claw.move_velocity(-100);
		}
		else
		{
			claw.move_velocity(0);
		}

		pros::delay(2);
	}
}

void bumperControl()
{
	pros::Motor left_wheels (LEFT_WHEELS_PORT);
  pros::Motor right_wheels (RIGHT_WHEELS_PORT, true);
	pros::ADIDigitalIn left_bumper (LEFT_BUMPER_PORT);
	pros::ADIDigitalIn right_bumper (RIGHT_BUMPER_PORT);
	pros::Controller master (CONTROLLER_MASTER);

	while (true)
	{
		int power = master.get_analog(ANALOG_LEFT_Y);
	  int turn = master.get_analog(ANALOG_RIGHT_X);
	  int left = power + turn;
	  int right = power - turn;

		if (left_bumper.get_value() || right_bumper.get_value())
		{
			if (left < 0)
			{
				left = 0;
			}
			if (right < 0)
			{
				right = 0;
			}
		}
	}

	pros::delay(2);
}

void limitSwitchControl()
{
  pros::Motor arm (ARM_PORT, MOTOR_GEARSET_36);

	pros::ADIDigitalIn arm_limit (ARM_LIMIT_SWITCH_PROT);

	pros::Controller master (CONTROLLER_MASTER);

	while (true)
	{
		int power = master.get_analog(ANALOG_LEFT_Y);
	  int turn = master.get_analog(ANALOG_RIGHT_X);
	  int left = power + turn;
	  int right = power - turn;

		if (master.get_digital(DIGITAL_R1))
		{
			arm.move_velocity(100);
		}
		else if (master.get_digital(DIGITAL_R2) && !arm_limit.get_value())
		{
			arm.move_velocity(-100);
		}
		else
		{
			arm.move_velocity(0);
		}
	}

	pros::delay(2);
}

void analogDataController()
{
	pros::Controller master (pros::E_CONTROLLER_MASTER);
	pros::Motor example_motor (MOTOR_PORT);

	while (true)
	{
		example_motor = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		pros::delay(2);
	}
}

void digitalDataController()
{
	pros::Controller master (pros::E_CONTROLLER_MASTER);
	pros::Motor example_motor (MOTOR_PORT);

	while (true)
	{
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			example_motor = 127;
		}
		else
		{
			example_motor = 0;
		}
		pros::delay(2);
	}
}

void motorControl()
{
	pros::Motor drive_left (MOTOR_PORT);
}

void motorMoveControl()
{
	pros::Motor drive_left (MOTOR_PORT);
	pros::Controller master (pros::E_CONTROLLER_MASTER);

	while (true)
	{
		drive_left.move(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
		pros::delay(2);
	}
}
