#include "main.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void on_right_button() {
	static bool button_2_pressed = false;
	button_2_pressed = !button_2_pressed;

	if (button_2_pressed) {
		pros::lcd::set_text(4, "right button pressed");
	}
	else {
		pros::lcd::clear_line(4);
	}
}

/**
 * runs initialization code. this occurs as soon as the program is started.
 *
 * all other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "  welcome to V5 and PROS user!");

	pros::lcd::register_btn1_cb(on_center_button);
  pros::lcd::register_btn2_cb(on_right_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. this is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * this task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
