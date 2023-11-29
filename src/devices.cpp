#include "main.h"

pros::Motor catapult(5,pros::E_MOTOR_GEARSET_36, false);
pros::Motor intake(21, pros::E_MOTOR_GEARSET_06, false);

pros::ADIDigitalOut wing1('A', false);
pros::ADIDigitalOut wing2('B', false);
pros::ADIDigitalOut blocker1('C', false);
pros::ADIDigitalOut blocker2('D', false);
pros::ADIDigitalOut blocker2ndStage('H', false);
