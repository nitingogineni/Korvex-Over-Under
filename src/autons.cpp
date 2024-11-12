#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void one_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}



///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}

///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}

	void RedDescore(){
    Vwing.set_value(true);
    pros::delay(500);
    Vwing.set_value(false);
    wing2.set_value(true);
    pros::delay(100);
    wing2.set_value(false);
    intake.move_voltage(-12000);
    intake1.move_voltage(-12000);
    pros::delay(1);
    chassis.set_drive_pid(38.5, DRIVE_SPEED, true);
    chassis.wait_until(38);
    intake.move_voltage(0);
    intake1.move_voltage(0);
    pros::delay(1);
    chassis.set_turn_pid(10, TURN_SPEED);
    chassis.wait_until(9);
    chassis.set_drive_pid(-39, DRIVE_SPEED, true);
    chassis.wait_until(-38);
    chassis.set_turn_pid(-170, TURN_SPEED);
    chassis.wait_until(-169);
    chassis.set_turn_pid(-60, TURN_SPEED);
    chassis.wait_until(-59);
    chassis.set_drive_pid(15, DRIVE_SPEED, true);
    chassis.wait_until(14);
    Vwing.set_value(true);
    pros::delay(500);
    chassis.set_drive_pid(-12, DRIVE_SPEED, true);
    chassis.wait_until(-21);
    chassis.set_turn_pid(-265, TURN_SPEED);
    chassis.wait_until(-264);
    Vwing.set_value(false);
    pros::delay(200);
    chassis.set_drive_pid(18, DRIVE_SPEED, true);
    chassis.wait_until(17);
    chassis.set_turn_pid(-280, TURN_SPEED);
    chassis.wait_until(-279);
    intake.move_voltage(12000);
    intake1.move_voltage(12000);
    chassis.set_drive_pid(15, DRIVE_SPEED, true);
    chassis.wait_until(14);
  }
  void BlueDescore(){

  }
  
	void RedGoalSide(){
    Vwing.set_value(true);
    pros::delay(200);
    chassis.set_drive_pid(-7, 127);
    chassis.wait_until(-6);
    chassis.set_turn_pid(-45, 90);
    chassis.wait_until(-44);
    Vwing.set_value(false);
    chassis.set_turn_pid(0, 90);
    chassis.wait_until(-1);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_until(-9);
    chassis.set_turn_pid(-45, 90);
    chassis.wait_until(-44);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_until(-12);
    chassis.set_drive_pid(15, 127);
    chassis.wait_until(14);
    chassis.set_turn_pid(70, 90);
    chassis.wait_until(69);
    chassis.set_drive_pid(41, 127);
    chassis.wait_until(40);
    intake.move_voltage(-12000);
    intake1.move_voltage(-12000);
    pros::delay(200);
    intake.move_voltage(0);
    intake1.move_voltage(0);
    pros::delay(1);
    chassis.set_turn_pid(195, 90);
    chassis.wait_until(179);
    chassis.set_drive_pid(7, 127);
    chassis.wait_until(6);
    intake.move_voltage(12000);
    intake1.move_voltage(12000);
    pros::delay(500);
    chassis.set_turn_pid(95, 90);
    chassis.wait_until(89);
    intake.move_voltage(0);
    intake1.move_voltage(0);
    pros::delay(1);
    chassis.set_drive_pid(16.5, 127);
    chassis.wait_until(16);
    intake.move_voltage(-12000);
    intake1.move_voltage(-12000);
    pros::delay(300);
    intake.move_voltage(0);
    intake1.move_voltage(0);
    pros::delay(1);
    chassis.set_turn_pid(225, 90);
    chassis.wait_until(-134);
    intake.move_voltage(12000);
    intake1.move_voltage(12000);
    pros::delay(200);
    wing1.set_value(true);
    wing2.set_value(true);
    pros::delay(300);
    chassis.set_drive_pid(28, 127);
    chassis.wait_until(26);
    chassis.set_drive_pid(-15, 127);
    chassis.wait_until(-14);
  }
	void BlueGoalSide(){
    

  }
	void RedElims(){
    intake.move_voltage(-12000);
    intake1.move_voltage(-12000);
    pros::delay(1);
    chassis.set_drive_pid(8, 127);
    chassis.wait_until(7);
    Vwing.set_value(true);
    pros::delay(500);
    chassis.set_drive_pid(-7, 127);
    chassis.wait_until(-4);
    intake.move_voltage(0);
    intake1.move_voltage(0);
    pros::delay(1);
    chassis.set_turn_pid(-45, 90);
    chassis.wait_until(-44);
    Vwing.set_value(false);
    pros::delay(100);
    chassis.set_turn_pid(0, 90);
    chassis.wait_until(-1);
    chassis.set_drive_pid(-14, 127);
    chassis.wait_until(-13);
    chassis.set_turn_pid(-220, 90);
    chassis.wait_until(-224);
    chassis.set_drive_pid(20, 127);
    chassis.wait_until(19);
    intake.move_voltage(12000);
    intake1.move_voltage(12000);
  }
  void BlueElims(){
  }
	void Skills(){    
    
  }
	void test(){
    
  }


///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .