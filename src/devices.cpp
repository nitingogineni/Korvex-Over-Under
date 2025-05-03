#include "main.h"

pros::Motor wallstake(9, pros::E_MOTOR_GEARSET_36, false);
pros::Motor intake1(20, pros::E_MOTOR_GEARSET_06, false);

pros::ADIDigitalOut mogo('H', true);
pros::ADIDigitalOut doinker('F', false);
pros::ADIDigitalOut intakelift('G', false);
pros::ADIDigitalOut Goalrush('E', false);

pros::Motor lF(-18, pros::E_MOTOR_GEARSET_06); // left front motor. port 9, reversed
pros::Motor lB(-17, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed
pros::Motor lB2(-19, pros::E_MOTOR_GEARSET_06); // left back motor. port 21, reversed

pros::Motor rF(16, pros::E_MOTOR_GEARSET_06); // right front motor. port 12
pros::Motor rB(14, pros::E_MOTOR_GEARSET_06); // right back motor. port 16
pros::Motor rB2(12, pros::E_MOTOR_GEARSET_06); // right back motor. port 16
 

// motor groups
pros::MotorGroup leftMotors({lF, lB2, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rB2, rB}); // right motor group
pros::Imu imu(8);
pros::Rotation rotation_sensor(10);
pros::Optical colorsort(7);
