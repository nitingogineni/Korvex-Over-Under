#include "main.h"
/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 127; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;
//make sure these are in centidegrees (1 degree = 100 centidegrees)
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


  void solowp(){
    nextState();
    pros::delay(500);
    intake_speed = -127;
    pros::delay(1000);
    intake_speed = 0;
    pros::delay(1);
    intake_speed = -127;
    pros::delay(200);
    intake_speed = 0;
    target = states[5];
    pros::delay(700);
    nextState();
    chassis.set_drive_pid(-5, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(50, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-32, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-8, DRIVE_SPEED, true);
    chassis.wait_drive();
    mogo.set_value(true);
    pros::delay(300);
    nextState();
    chassis.set_turn_pid(180, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = -127;
    chassis.set_drive_pid(22.75, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(145, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(10, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(40, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(40, DRIVE_SPEED, true);
    chassis.wait_drive();
    //nextState();
    //nextState();
    //chassis.set_drive_pid(35, DRIVE_SPEED, true);
    //chassis.wait_drive();
    intake_speed = 127;
    pros::delay(300);
    intake_speed = -127;
  }


  void safewp(){

    nextState();
    pros::delay(500);
    intake_speed = -127;
    pros::delay(1000);
    intake_speed = 0;
    pros::delay(1);
    intake_speed = -127;
    pros::delay(200);
    intake_speed = 0;
    target = states[5];
    pros::delay(700);
    nextState();
    chassis.set_drive_pid(-5, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(-45, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-26, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-14, 60, true);
    chassis.wait_drive();
    mogo.set_value(true);
    pros::delay(300);
    nextState();
    chassis.set_turn_pid(160, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = -127;
    chassis.set_drive_pid(17.5, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(215, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(6, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(170, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(2, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(215, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(5, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(320, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(100);
    intake_speed = -127;
    chassis.set_drive_pid(25, DRIVE_SPEED, true);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(100);
    intake_speed = -127;
    chassis.set_turn_pid(80, TURN_SPEED);
    chassis.wait_drive();
    nextState();
    nextState();
    chassis.set_drive_pid(45, DRIVE_SPEED, true);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(300);
    intake_speed = -127;
  }
  
  void Elims(){
    nextState();
    pros::delay(300);
    intake_speed = -127;
    pros::delay(300);
    intake_speed = 0;
    target = states[5];
    pros::delay(600);
    nextState();
    chassis.set_drive_pid(-5, DRIVE_SPEED, true);
    chassis.wait_until(-4);
    chassis.set_turn_pid(-45, TURN_SPEED);
    chassis.wait_until(-44);
    chassis.set_drive_pid(-26, DRIVE_SPEED, true);
    chassis.wait_until(-25);
    chassis.set_drive_pid(-14, DRIVE_SPEED, true);
    chassis.wait_until(-13);
    mogo.set_value(true);
    pros::delay(300);
    nextState();
    chassis.set_turn_pid(-145, TURN_SPEED);
    chassis.wait_until(-144);
    intake_speed = -127;
    chassis.set_drive_pid(18, DRIVE_SPEED, true);
    chassis.wait_until(15);
    chassis.set_turn_pid(-35, TURN_SPEED);
    chassis.wait_until(-32);
    chassis.set_drive_pid(30, DRIVE_SPEED, true);
    chassis.wait_until(27);
    pros::delay(200);
    chassis.set_turn_pid(35, TURN_SPEED);
    chassis.wait_until(32); 
    intake_speed = 0;
    chassis.set_drive_pid(58, DRIVE_SPEED, true);
    chassis.wait_until(39);
    mogo.set_value(false);
    chassis.set_turn_pid(-62, TURN_SPEED);
    chassis.wait_until(-61);
    chassis.set_drive_pid(-24, DRIVE_SPEED, true);
    chassis.wait_until(-23);
    chassis.set_drive_pid(-13, DRIVE_SPEED, true);
    chassis.wait_until(-12);
    intake_speed = 0;
    mogo.set_value(true);
    chassis.set_turn_pid(25, TURN_SPEED);
    chassis.wait_until(24);
    intake_speed = -127;
    chassis.set_drive_pid(26, DRIVE_SPEED, true);
    chassis.wait_until(25);
    chassis.set_turn_pid(-160, TURN_SPEED);
    chassis.wait_drive();
    nextState();
    nextState();
    chassis.set_drive_pid(54, DRIVE_SPEED, true);
    chassis.wait_drive();
  }
	void Skills(){                              
    //intake on alliance stake                               
    intake_speed = -127;
    pros::delay(600);
    intake_speed = 0;
    chassis.set_drive_pid(13, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(90, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-26, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-6, DRIVE_SPEED, true);
    chassis.wait_drive();
    //clamps goal
    mogo.set_value(true);
    chassis.set_turn_pid(20, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = -127;
    chassis.set_drive_pid(25, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(-30, TURN_SPEED);
    chassis.wait_drive();
    //drive for 2nd ring
    chassis.set_drive_pid(47, DRIVE_SPEED, true);
    chassis.wait_drive();
    nextState();
    //intake ring for wallstake
    chassis.set_turn_pid(-10, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(100);
    intake_speed = -127;
    chassis.set_drive_pid(8, DRIVE_SPEED, true);
    chassis.wait_drive();
    intake_speed = 0;
    intake_speed = -127;
    chassis.set_turn_pid(-190, TURN_SPEED);
    chassis.wait_drive();
    pros::delay(300);
    intake_speed = 0;
    target = states[3];
    pros::delay(100);
    intake_speed = -127;
    chassis.set_drive_pid(22.75, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(-90, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(16, DRIVE_SPEED, true);
    chassis.wait_drive();
    //wall stake
    pros::delay(200);
    target = states[5];
    chassis.set_drive_pid(4, DRIVE_SPEED, true);
    chassis.wait_drive();
    pros::delay(500);
    nextState();
    chassis.set_drive_pid(-13, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(-180, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(100);
    intake_speed = -127;
    //drive and intake 3 rings
    chassis.set_drive_pid(25, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(25, DRIVE_SPEED, true);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(75);
    intake_speed = -127;
    chassis.set_drive_pid(10, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-14, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(-135, TURN_SPEED);
    chassis.wait_drive();
    //intake 6th ring
    chassis.set_drive_pid(10, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(35, TURN_SPEED);
    chassis.wait_drive();
    pros::delay(100);
    chassis.set_drive_pid(-9, DRIVE_SPEED, true);
    chassis.wait_drive();
    //drop goal in 1st corner
    mogo.set_value(false);
    intake_speed = 127;
    chassis.set_drive_pid(10, DRIVE_SPEED, true);
    chassis.wait_drive();
    intake_speed = 0;
    chassis.set_turn_pid(-90, TURN_SPEED);
    chassis.wait_drive();
    nextState();
    chassis.set_drive_pid(-75, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-11, 60, true);
    chassis.wait_drive();
    //second goal
    mogo.set_value(true);
    pros::delay(200);
    chassis.set_turn_pid(-16, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = -127;
    chassis.set_drive_pid(22, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(40, TURN_SPEED);
    chassis.wait_drive();
    //drive for 2nd ring
    chassis.set_drive_pid(43, DRIVE_SPEED, true);
    chassis.wait_drive();
    nextState();
    //intake ring for wallstake
    chassis.set_turn_pid(0, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(100);
    intake_speed = -127;
    chassis.set_drive_pid(12, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(190, TURN_SPEED);
    chassis.wait_drive();
    pros::delay(300);
    intake_speed = 0;
    target = states[3];
    pros::delay(300);
    intake_speed = -127;
    chassis.set_drive_pid(19.75, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(90, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(14, DRIVE_SPEED, true);
    chassis.wait_drive();
    //wall stake
    pros::delay(400);
    target = states[5];
    chassis.set_drive_pid(4, DRIVE_SPEED, true);
    chassis.wait_drive();
    pros::delay(500);
    nextState();
    chassis.set_drive_pid(-18, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(180, TURN_SPEED);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(100);
    intake_speed = -127;
    //drive and intake 3 rings
    chassis.set_drive_pid(25, DRIVE_SPEED, true);
    chassis.wait_drive();
    intake_speed = 127;
    pros::delay(100);
    intake_speed = -127;
    chassis.set_drive_pid(25, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(10, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-14, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(135, TURN_SPEED);
    chassis.wait_drive();
    //intake 6th ring
    chassis.set_drive_pid(10, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(-35, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-13, DRIVE_SPEED, true);
    chassis.wait_drive();
    //drop goal in 1st corner
    mogo.set_value(false);
    intake_speed = 127;
    chassis.set_drive_pid(25, DRIVE_SPEED, true);
    chassis.wait_drive();
    intake_speed = 0;
    chassis.set_turn_pid(180, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-75, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(145, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-27, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-10, 60, true);
    chassis.wait_drive();
    mogo.set_value(true);
    pros::delay(200);
    chassis.set_turn_pid(-105, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-39, DRIVE_SPEED, true);
    chassis.wait_drive();
    mogo.set_value(false);
    chassis.set_drive_pid(9, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(90, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-75, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(115, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-51, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-15, 60, true);
    chassis.wait_drive();
    chassis.set_drive_pid(40, DRIVE_SPEED, true);
    chassis.wait_drive();
  }

  void goalrush(){ 
    //goal rush 
    doinker.set_value(true);
    intake_speed = -100;                                                            
    chassis.set_drive_pid(42, DRIVE_SPEED, true);
    chassis.wait_drive();
    doinker.set_value(false);
    intake_speed = 0;
    pros::delay(150);
    chassis.set_drive_pid(-22, DRIVE_SPEED, true);
    chassis.wait_drive();
    doinker.set_value(true);
    pros::delay(100);
    chassis.set_drive_pid(-9, DRIVE_SPEED, true);
    chassis.wait_drive();
    doinker.set_value(false);
    //clamp and score
    chassis.set_turn_pid(170, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-16, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-3, DRIVE_SPEED, true);
    chassis.wait_drive();
    mogo.set_value(true);
    pros::delay(300);
    intake_speed = -127;
    chassis.set_turn_pid(-80, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-15, DRIVE_SPEED, true);
    mogo.set_value(false);
    intake_speed = 0;
    chassis.set_drive_pid(7, DRIVE_SPEED, true);
    chassis.wait_drive();
    //clamp second goal
    chassis.set_turn_pid(23, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(-19, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_drive_pid(-8, DRIVE_SPEED, true);
    chassis.wait_drive();
    mogo.set_value(true);
    pros::delay(100);
    chassis.set_turn_pid(135, TURN_SPEED);
    chassis.wait_drive();
    //second goal ring
    intake_speed = -127;
    chassis.set_drive_pid(23, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(100, TURN_SPEED);
    chassis.wait_drive();
    //corner clear
    chassis.set_drive_pid(12, DRIVE_SPEED, true);
    chassis.wait_drive();
    chassis.set_turn_pid(300, TURN_SPEED);
    chassis.wait_drive();

    intake_speed = 127;
    //bar touch
    nextState();
    nextState();
    intake_speed = -127;
    chassis.set_drive_pid(56, DRIVE_SPEED, true);
    chassis.wait_drive();
  }

  void bluegoalrush(){
   //goal rush 
   doinker.set_value(true);
   intake_speed = -100;                                                            
   chassis.set_drive_pid(43, DRIVE_SPEED, true);
   chassis.wait_drive();
   doinker.set_value(false);
   intake_speed = 0;
   pros::delay(300);
   chassis.set_drive_pid(-19, DRIVE_SPEED, true);
   chassis.wait_drive();
   doinker.set_value(true);
   pros::delay(100);
   chassis.set_drive_pid(-9, DRIVE_SPEED, true);
   chassis.wait_drive();
   doinker.set_value(false);
   //clamp and score
   chassis.set_turn_pid(167, TURN_SPEED);
   chassis.wait_drive();
   chassis.set_drive_pid(-19, DRIVE_SPEED, true);
   chassis.wait_drive();
   chassis.set_drive_pid(-3, DRIVE_SPEED, true);
   chassis.wait_drive();
   mogo.set_value(true);
   pros::delay(300);
   intake_speed = -127;
   chassis.set_turn_pid(80, TURN_SPEED);
   chassis.wait_drive();
   chassis.set_drive_pid(-15, DRIVE_SPEED, true);
   mogo.set_value(false);
   intake_speed = 0;
   //clamp second goal
   chassis.set_turn_pid(-80, TURN_SPEED);
   chassis.wait_drive();
   chassis.set_drive_pid(-19.5, DRIVE_SPEED, true);
   chassis.wait_drive();
   chassis.set_drive_pid(-7, DRIVE_SPEED, true);
   chassis.wait_drive();
   mogo.set_value(true);
   chassis.set_turn_pid(-190, TURN_SPEED);
   chassis.wait_drive();
   //second goal ring
   intake_speed = -127;
   chassis.set_drive_pid(26, DRIVE_SPEED, true);
   chassis.wait_drive();
   chassis.set_turn_pid(-135, TURN_SPEED);
   chassis.wait_drive();
   //corner clear
   chassis.set_drive_pid(24, DRIVE_SPEED, true);
   chassis.wait_drive();
   chassis.set_turn_pid(20, TURN_SPEED);
   chassis.wait_drive();
   intake_speed = 127;
   pros::delay(300);
   intake_speed = -127;
   //bar touch
   nextState();
   nextState();
   intake_speed = 0;
   chassis.set_drive_pid(52, DRIVE_SPEED, true);
   chassis.wait_drive(); 
  }

  void redElims(){

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