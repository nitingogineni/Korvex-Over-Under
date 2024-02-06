#include "main.h"
using namespace std;


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negati	cve port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-6, -11, 7}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-4, 20, 12}	

  // IMU Port
  ,15

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,3.25

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,1.666

  // Uncomment if using tracking wheels
  /*
  // Left Tracking Wheel Ports (negative port will reverse it!)
  // ,{1, 2} // 3 wire encoder
  // ,8 // Rotation sensor

  // Right Tracking Wheel Ports (negative port will reverse it!)
  // ,{-3, -4} // 3 wire encoder
  // ,-9 // Rotation sensor
  */

  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,1
);

enum class autonStates { // the possible auton selections
	off,
	RedDescore,
	RedGoalSide,
	BlueDescore,
	BlueGoalSide,
	RedElims,
	BlueElims,
	Skills,
	test
};


autonStates autonSelection = autonStates::off;

static lv_res_t RedLeftBtnAction(lv_obj_t *btn) {
	autonSelection = autonStates::RedDescore;
	std::cout << pros::millis() << "RedLeft" << std::endl;
	return LV_RES_OK;
}

static lv_res_t RedRightBtnAction(lv_obj_t *btn) {
	autonSelection = autonStates::RedGoalSide;
	std::cout << pros::millis() << "RedRight" << std::endl;
	return LV_RES_OK;
}

static lv_res_t BlueLeftBtnAction(lv_obj_t *btn) {
	autonSelection = autonStates::BlueDescore;
	std::cout << pros::millis() << "BlueLeft" << std::endl;
	return LV_RES_OK;
}

static lv_res_t BlueRightBtnAction(lv_obj_t *btn) {
	autonSelection = autonStates::BlueGoalSide;
	std::cout << pros::millis() << "BlueRight" << std::endl;
	return LV_RES_OK;
}

static lv_res_t RedSoloWPBtnAction(lv_obj_t *btn) {
	autonSelection = autonStates::RedElims;
	std::cout << pros::millis() << "RedSoloWP" << std::endl;
	return LV_RES_OK;
}

static lv_res_t BlueSoloWPBtnAction(lv_obj_t *btn) {
	autonSelection = autonStates::BlueElims;
	std::cout << pros::millis() << "BlueSoloWP" << std::endl;
	return LV_RES_OK;
}

static lv_res_t SkillsBtnAction(lv_obj_t *btn) {
	autonSelection = autonStates::Skills;
	std::cout << pros::millis() << "Skills" << std::endl;
	return LV_RES_OK;
}

static lv_res_t ResetBtnAction(lv_obj_t *btn) {
	imu.reset();

	leftMotors.tare_position();
	rightMotors.tare_position();

	while (imu.is_calibrating() and pros::millis() < 5000)
	{
		pros::delay(10);
	}
	if (pros::millis() < 5000) std::cout << pros::millis() << ": finished calibrating!" << std::endl;
	return LV_RES_OK;
}

static lv_res_t noAutonBtnAction(lv_obj_t *btn) {
	autonSelection = autonStates::off;
	std::cout << pros::millis() << "None" << std::endl;
	return LV_RES_OK;
}




/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.

  imu.reset();
	
	lv_theme_t *th = lv_theme_alien_init(360, NULL); //Set a HUE value and keep font default RED
	lv_theme_set_current(th);

	// create a tab view object
	std::cout << pros::millis() << ": creating gui..." << std::endl;
	lv_obj_t *tabview = lv_tabview_create(lv_scr_act(), NULL);

	//button layout
	lv_obj_t *RedTab = lv_tabview_add_tab(tabview, "Red");
	lv_obj_t *BlueTab = lv_tabview_add_tab(tabview, "Blue");
	lv_obj_t *SkillsTab = lv_tabview_add_tab(tabview, "Skills");
	lv_obj_t *OffTab = lv_tabview_add_tab(tabview, "Turn Off");
	

	// Red tab
	lv_obj_t *RedLeftBtn = lv_btn_create(RedTab, NULL);
	lv_obj_t *labelRedLeft = lv_label_create(RedLeftBtn, NULL);

	lv_obj_t *RedRightBtn = lv_btn_create(RedTab, NULL);
	lv_obj_t *labelRedRight = lv_label_create(RedRightBtn, NULL);

	lv_obj_t *RedSoloWPBtn = lv_btn_create(RedTab, NULL);
	lv_obj_t *labelRedSolo = lv_label_create(RedSoloWPBtn, NULL);

	lv_label_set_text(labelRedLeft, "RedDescore");
	lv_btn_set_action(RedLeftBtn, LV_BTN_ACTION_CLICK, RedLeftBtnAction);
	lv_obj_set_size(RedLeftBtn, 150, 50);
	lv_btnm_set_toggle(RedLeftBtn, true, 1);
	lv_obj_set_pos(RedLeftBtn, 0, 0);
	lv_obj_align(RedLeftBtn, NULL, LV_ALIGN_CENTER, -150, -5);

	lv_label_set_text(labelRedRight, "RedGoalSide");
	lv_btn_set_action(RedRightBtn, LV_BTN_ACTION_CLICK, RedRightBtnAction);
	lv_obj_set_size(RedRightBtn, 150, 50);
	lv_btnm_set_toggle(RedRightBtn, true, 1);
	lv_obj_set_pos(RedRightBtn, 0, 0);
	lv_obj_align(RedRightBtn, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_label_set_text(labelRedSolo, "RedElims");
	lv_btn_set_action(RedSoloWPBtn, LV_BTN_ACTION_CLICK, RedSoloWPBtnAction);
	lv_obj_set_size(RedSoloWPBtn, 150, 50);
	lv_btnm_set_toggle(RedSoloWPBtn, true, 1);
	lv_obj_set_pos(RedSoloWPBtn, 0, 0);
	lv_obj_align(RedSoloWPBtn, NULL, LV_ALIGN_CENTER, 150, 12.5);
	

	// Blue tab
	lv_obj_t *BlueLeftBtn = lv_btn_create(BlueTab, NULL);
	lv_obj_t *labelBlueLeft = lv_label_create(BlueLeftBtn, NULL);

	lv_obj_t *BlueRightBtn = lv_btn_create(BlueTab, NULL);
	lv_obj_t *labelBlueRight = lv_label_create(BlueRightBtn, NULL);

	lv_obj_t *BlueSoloWPBtn = lv_btn_create(BlueTab, NULL);
	lv_obj_t *labelBlueSolo = lv_label_create(BlueSoloWPBtn, NULL);

	lv_label_set_text(labelBlueLeft, "BlueDescore");
	lv_btn_set_action(BlueLeftBtn, LV_BTN_ACTION_CLICK, BlueLeftBtnAction);
	lv_obj_set_size(BlueLeftBtn, 150, 50);
	lv_btnm_set_toggle(BlueLeftBtn, true, 1);
	lv_obj_set_pos(BlueLeftBtn, 0, 0);
	lv_obj_align(BlueLeftBtn, NULL, LV_ALIGN_CENTER, -150, -5);

	lv_label_set_text(labelBlueRight, "BlueGoalSide");
	lv_btn_set_action(BlueRightBtn, LV_BTN_ACTION_CLICK, BlueRightBtnAction);
	lv_obj_set_size(BlueRightBtn, 150, 50);
	lv_btnm_set_toggle(BlueRightBtn, true, 1);
	lv_obj_set_pos(BlueRightBtn, 0, 0);
	lv_obj_align(BlueRightBtn, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_label_set_text(labelBlueSolo, "BlueElims");
	lv_btn_set_action(BlueSoloWPBtn, LV_BTN_ACTION_CLICK, BlueSoloWPBtnAction);
	lv_obj_set_size(BlueSoloWPBtn, 150, 50);
	lv_btnm_set_toggle(BlueSoloWPBtn, true, 1);
	lv_obj_set_pos(BlueSoloWPBtn, 0, 0);
	lv_obj_align(BlueSoloWPBtn, NULL, LV_ALIGN_CENTER, 150, 12.5);
	

	//DiagonalDouble tab
	lv_obj_t *OffBtn = lv_btn_create(OffTab, NULL);
	lv_obj_t *Offlabel = lv_label_create(OffBtn, NULL);
	lv_label_set_text(Offlabel, "Turn Off");
	lv_btn_set_action(OffBtn, LV_BTN_ACTION_CLICK, noAutonBtnAction);
	lv_obj_set_size(OffBtn, 450, 50);
	lv_btnm_set_toggle(OffBtn, true, 1);
	lv_obj_set_pos(OffBtn, 0, 100);
	lv_obj_align(OffBtn, NULL, LV_ALIGN_CENTER, 0, 0);


	// skills tab
	lv_obj_t *SkillsBtn = lv_btn_create(SkillsTab, NULL);
	lv_obj_t *skillslabel = lv_label_create(SkillsBtn, NULL);

	lv_label_set_text(skillslabel, "Skills");
	lv_btn_set_action(SkillsBtn, LV_BTN_ACTION_CLICK, SkillsBtnAction);
	lv_obj_set_size(SkillsBtn, 450, 50);
	lv_btnm_set_toggle(SkillsBtn, true, 1);
	lv_obj_set_pos(SkillsBtn, 0, 100);
	lv_obj_align(SkillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);

	//reset btn
	lv_obj_t *ResetBtn = lv_btn_create(tabview, NULL);
	lv_obj_t *ResetLabel = lv_label_create(ResetBtn, NULL);

	lv_label_set_text(ResetLabel, "Reset");
	lv_btn_set_action(ResetBtn, LV_BTN_ACTION_CLICK, ResetBtnAction);
	lv_obj_set_size(ResetBtn, 250, 50);
	lv_btnm_set_toggle(ResetBtn, true, 1);
	lv_obj_set_pos(ResetBtn, 0, 100);
	lv_obj_align(ResetBtn, NULL, LV_ALIGN_CENTER, 0, 50);

	chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.


  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults(); // Set the exit conditions to your own constants from autons.cpp!

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  

  // Initialize chassis and auton selector
  chassis.initialize();
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
Hang1.set_value(false);
Hang2.set_value(false);
}



/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}



/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.

  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.

  if(autonSelection == autonStates::off) {
		autonSelection = autonStates::test;
	}	

	switch(autonSelection) {
		case autonStates::RedDescore:
			RedDescore();
			break;
		case autonStates::RedGoalSide:
			RedGoalSide();
			break;
		case autonStates::BlueDescore:
			BlueDescore();
			break;
		case autonStates::BlueGoalSide:
			BlueGoalSide();
			break;
		case autonStates::RedElims:
			RedElims();
			break;
		case autonStates::BlueElims:
			BlueElims();
			break;
		case autonStates::Skills:
			Skills();
			break;
		case autonStates::test:
			test();
			break;
		default:
			break;
	}
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

bool wings = false;
bool Hang = false;
bool Vwings = false;
void opcontrol() {
  // This is preference to what you like to drive on.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  pros::Motor intake(14);
  pros::Motor catapult(13);
  pros::ADIDigitalOut wing1('C', false);
  pros::ADIDigitalOut wing2('F', false);
  pros::ADIDigitalOut Hang1('G', false);
  pros::ADIDigitalOut Hang2('A', false);
  pros::ADIDigitalOut Vwing1('E', false);
  pros::ADIDigitalOut Vwing2('B', false);
  pros::ADIDigitalOut SideHang('H', true);
  while (true) {

    chassis.tank(); // Tank control
    // chassis.arcade_standard(ez::SPLIT); // Standard split arcade
    // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
    // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
    // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade

    // . . .
    // Put more user control code here!
    // . . .
    // intake code
    if(master.get_digital(DIGITAL_L1)){
        intake.move_voltage(12000);
    }  
    else if(master.get_digital(DIGITAL_L2)){
        intake.move_voltage(-12000);
    }
    else{
        intake.move_voltage(0);
    }
    // catapult
    if(master.get_digital(DIGITAL_LEFT)){
        catapult.move_voltage(12000);
    }
    else if(master.get_digital(DIGITAL_RIGHT)){
        catapult.move_voltage(-12000);
    }
    else{
        catapult.move_voltage(0);
    }
    
    // wing code
		if(master.get_digital_new_press(DIGITAL_DOWN)){
      if(wings == false) {
          wing1.set_value(true);
          wing2.set_value(true);
          wings = true;
      
      } else if(wings == true) {
          wing1.set_value(false);
          wing2.set_value(false);
          wings = false;
      }
    }

    if(master.get_digital_new_press(DIGITAL_UP)){
      if(Vwings == false) {
          Vwing1.set_value(true);
          Vwing2.set_value(true);
          Vwings = true;
      
      } else if(Vwings == true) {
          Vwing1.set_value(false);
          Vwing2.set_value(false);
          Vwings = false;
      }
    }
    // blocker code
		if(master.get_digital_new_press(DIGITAL_B)) {
      if(Hang == false){
          Hang1.set_value(true);
          Hang2.set_value(true);
          Hang = true;
      }
      else if(Hang == true){
        Hang1.set_value(false);
        Hang2.set_value(false);
        Hang = false;
            }
        }
    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}