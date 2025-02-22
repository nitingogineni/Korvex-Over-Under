#include "main.h"

pros::Motor wallstake(11,pros::E_MOTOR_GEARSET_18, false);
pros::Motor intake1(2, pros::E_MOTOR_GEARSET_06, false);

pros::ADIDigitalOut mogo('H', false);
pros::ADIDigitalOut doinker('G', false);

pros::Motor lF(12, pros::E_MOTOR_GEARSET_06); // left front motor. port 9, reversed
pros::Motor lB(-14, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed
pros::Motor lB2(-3, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed

pros::Motor rF(-9, pros::E_MOTOR_GEARSET_06); // right front motor. port 12
pros::Motor rB(-20, pros::E_MOTOR_GEARSET_06); // right back motor. port 16
pros::Motor rB2(19, pros::E_MOTOR_GEARSET_06); // right back motor. port 16
 

// motor groups
pros::MotorGroup leftMotors({lF, lB2, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rB2, rB}); // right motor group
pros::Imu imu(17);
pros::Rotation rotation_sensor(16);
pros::Optical colorsort(4);
