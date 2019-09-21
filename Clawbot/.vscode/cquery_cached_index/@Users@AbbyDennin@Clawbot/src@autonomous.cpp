#include "main.h"

#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT 10
#define MOTOR_MAX_SPEED 100

#define POTENTIOMETER_PORT 2
#define MOTOR_PORT 3
#define LINE_TRACKER_PORT 4

#define DIGITAL_SENSOR_PORT 5

#define QUAD_TOP_PORT 6
#define QUAD_BOTTOM_PORT 7

#define ULTRA_PING_PORT 8
#define ULTRA_ECHO_PORT 9

void autonomousMovement()
{
  pros::Motor left_wheels (LEFT_WHEELS_PORT);
  pros::Motor right_wheels (RIGHT_WHEELS_PORT, true);

  right_wheels.move_relative(1000, MOTOR_MAX_SPEED);
  left_wheels.move_relative(1000, MOTOR_MAX_SPEED);
}

void autonomousPotentiometer()
{
  pros::ADIPotentiometer sensor (POTENTIOMETER_PORT);
  pros::Motor motor (MOTOR_PORT);

  while (sensor.get_value() < 4095)
  {
    motor = 127;
    pros::delay(50);
  }
}

void autonomousLineTracker()
{
  pros::ADILineSensor sensor (LINE_TRACKER_PORT);
  pros::Motor motor (MOTOR_PORT);

  while(sensor.get_value() < 2000)
  {
    motor = 127;
    pros::delay(50);
  }
}

void autonomousButton()
{
  pros::ADIDigitalIn button (DIGITAL_SENSOR_PORT);
  pros::Motor drive (MOTOR_PORT);

  while (!button.get_value())
  {
    drive = 127;
    pros::delay(50);
  }
  drive = 0;
}

void autonomousEncoder()
{
  pros::ADIEncoder encoder (QUAD_TOP_PORT, QUAD_BOTTOM_PORT);
  pros::Motor drive (MOTOR_PORT);

  while (encoder.get_value() < 1000)
  {
    drive = 127;
    pros::delay(50);
  }
  drive = 0;
}

void autonomousUltrasonicSensor()
{
  pros::ADIUltrasonic ultrasonic (ULTRA_PING_PORT, ULTRA_ECHO_PORT);
  pros::Motor drive (MOTOR_PORT);

  while (ultrasonic.get_value() > 100)
  {
    drive = 127;
    pros::delay(50);
  }
  drive = 0;
}

void autonomousProfileMovements()
{
  pros::Motor drive_left (MOTOR_PORT);
  drive_left.move_relative(1000, MOTOR_MAX_SPEED);
  drive_left.move_relative(1000, MOTOR_MAX_SPEED);
  drive_left.move_absolute(1000, MOTOR_MAX_SPEED);
}

void autonomousVelocityController()
{
  pros::Motor drive_left (MOTOR_PORT);
  drive_left.move_velocity(MOTOR_MAX_SPEED);
  pros::delay(1000);
}
