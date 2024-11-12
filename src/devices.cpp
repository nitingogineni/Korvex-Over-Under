#include "main.h"

pros::Motor hang(8,pros::E_MOTOR_GEARSET_36, false);
pros::Motor intake(13, pros::E_MOTOR_GEARSET_06, false);
pros::Motor intake1(19, pros::E_MOTOR_GEARSET_06, false);

pros::ADIDigitalOut wing1('H', false);
pros::ADIDigitalOut wing2('G', false);
pros::ADIDigitalOut Vwing('C', false);
pros::ADIDigitalOut Rachet('D', false);
pros::ADIDigitalOut Hang1('A', false);
pros::ADIDigitalOut Hang2('B', false);

pros::Motor lF(-19, pros::E_MOTOR_GEARSET_06); // left front motor. port 9, reversed
pros::Motor lB(-14, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed
pros::Motor lB2(4, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed

pros::Motor rF(9, pros::E_MOTOR_GEARSET_06); // right front motor. port 12
pros::Motor rB(12, pros::E_MOTOR_GEARSET_06); // right back motor. port 16
pros::Motor rB2(-11, pros::E_MOTOR_GEARSET_06); // right back motor. port 16
 

// motor groups
pros::MotorGroup leftMotors({lF, lB2, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rB2, rB}); // right motor group
pros::Imu imu(8);