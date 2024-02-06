#include "main.h"

pros::Motor catapult(13,pros::E_MOTOR_GEARSET_36, false);
pros::Motor intake(14, pros::E_MOTOR_GEARSET_06, false);

pros::ADIDigitalOut wing1('C', false);
pros::ADIDigitalOut wing2('F', false);
pros::ADIDigitalOut Hang1('G', false);
pros::ADIDigitalOut Hang2('A', false);
pros::ADIDigitalOut Vwing1('E', false);
pros::ADIDigitalOut Vwing2('B', false);
pros::ADIDigitalOut SideHang('H', true);

pros::Motor lF(-19, pros::E_MOTOR_GEARSET_06); // left front motor. port 9, reversed
pros::Motor lB(-14, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed
pros::Motor lB2(4, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed

pros::Motor rF(9, pros::E_MOTOR_GEARSET_06); // right front motor. port 12
pros::Motor rB(12, pros::E_MOTOR_GEARSET_06); // right back motor. port 16
pros::Motor rB2(-11, pros::E_MOTOR_GEARSET_06); // right back motor. port 16
 

// motor groups
pros::MotorGroup leftMotors({lF, lB2, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rB2, rB}); // right motor group
pros::Imu imu(15);