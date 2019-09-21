#include "main.h"

#define ANALOG_SENSOR_PORT 1
#define DIGITAL_SENSOR_PORT 2
#define ACCELEROMETER_X 1
#define ACCELEROMETER_Y 2
#define ACCELEROMETER_Z 3
#define QUAD_TOP_PORT 1
#define QUAD_BOTTOM_PORT 2

void initializeAnalogSensor()
{
	pros::ADIAnalogIn sensor (ANALOG_SENSOR_PORT);
	sensor.calibrate();
}

void initializeDigitalSensor()
{
	pros::ADIDigitalIn sensor (DIGITAL_SENSOR_PORT);
}

void initializeAccelerometer()
{
	pros::ADIAnalogIn acc_x (ACCELEROMETER_X);
	pros::ADIAnalogIn acc_y (ACCELEROMETER_Y);
	pros::ADIAnalogIn acc_z (ACCELEROMETER_Z);

	acc_x.calibrate();
	acc_y.calibrate();
	acc_z.calibrate();

	int x_acc = acc_x.get_value_calibrated_HR();
  int y_acc = acc_y.get_value_calibrated_HR();
  int z_acc = acc_z.get_value_calibrated_HR();

	std::cout << "X: " << x_acc << "Y: " << y_acc << "Z: " << z_acc;
}

void initializeEncoder()
{
	pros::ADIEncoder encoder (QUAD_TOP_PORT, QUAD_BOTTOM_PORT, false);
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
