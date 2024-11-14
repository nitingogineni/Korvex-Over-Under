[1mdiff --git a/src/main.cpp b/src/main.cpp[m
[1mindex df7a7bd..bc68e77 100644[m
[1m--- a/src/main.cpp[m
[1m+++ b/src/main.cpp[m
[36m@@ -12,11 +12,11 @@[m [musing namespace std;[m
 Drive chassis ([m
   // Left Chassis Ports (negati	cve port will reverse it!)[m
   //   the first port is the sensored port (when trackers are not used!)[m
[31m-  {-6, -11, 7}[m
[32m+[m[32m  {-9, -10, -18}[m[41m[m
 [m
   // Right Chassis Ports (negative port will reverse it!)[m
   //   the first port is the sensored port (when trackers are not used!)[m
[31m-  ,{-4, 20, 12}	[m
[32m+[m[32m  ,{4, 11, 12}[m[41m	[m
 [m
   // IMU Port[m
   ,15[m
[36m@@ -283,12 +283,6 @@[m [mvoid initialize() {[m
  * the VEX Competition Switch, following either autonomous or opcontrol. When[m
  * the robot is enabled, this task will exit.[m
  */[m
[31m-void disabled() {[m
[31m-Hang1.set_value(false);[m
[31m-Hang2.set_value(false);[m
[31m-}[m
[31m-[m
[31m-[m
 [m
 /**[m
  * Runs after initialize(), and before autonomous when connected to the Field[m
[36m@@ -373,22 +367,19 @@[m [mvoid autonomous() {[m
  * operator control task will be stopped. Re-enabling the robot will restart the[m
  * task, not resume it from where it left off.[m
  */[m
[31m-[m
[31m-bool wings = false;[m
[31m-bool Hang = false;[m
[31m-bool Vwings = false;[m
[32m+[m[32mbool wing1;[m[41m[m
[32m+[m[32mbool wing2;[m[41m[m
[32m+[m[32mbool Rachet;[m[41m[m
[32m+[m[32mbool Vwing;[m[41m[m
 void opcontrol() {[m
   // This is preference to what you like to drive on.[m
   chassis.set_drive_brake(MOTOR_BRAKE_COAST);[m
   pros::Motor intake(14);[m
[31m-  pros::Motor catapult(13);[m
[31m-  pros::ADIDigitalOut wing1('C', false);[m
[31m-  pros::ADIDigitalOut wing2('F', false);[m
[31m-  pros::ADIDigitalOut Hang1('G', false);[m
[31m-  pros::ADIDigitalOut Hang2('A', false);[m
[31m-  pros::ADIDigitalOut Vwing1('E', false);[m
[31m-  pros::ADIDigitalOut Vwing2('B', false);[m
[31m-  pros::ADIDigitalOut SideHang('H', true);[m
[32m+[m[32m  pros::Motor hang(8);[m[41m[m
[32m+[m[32m  pros::ADIDigitalOut wing1('H', false);[m[41m[m
[32m+[m[32m  pros::ADIDigitalOut wing2('G', false);[m[41m[m
[32m+[m[32m  pros::ADIDigitalOut Vwing('A', false);[m[41m[m
[32m+[m[32m  pros::ADIDigitalOut Rachet('B', true);[m[41m[m
   while (true) {[m
 [m
     chassis.tank(); // Tank control[m
[36m@@ -412,54 +403,48 @@[m [mvoid opcontrol() {[m
     }[m
     // catapult[m
     if(master.get_digital(DIGITAL_LEFT)){[m
[31m-        catapult.move_voltage(12000);[m
[32m+[m[32m        hang.move_voltage(12000);[m[41m[m
     }[m
     else if(master.get_digital(DIGITAL_RIGHT)){[m
[31m-        catapult.move_voltage(-12000);[m
[32m+[m[32m        hang.move_voltage(-12000);[m[41m[m
     }[m
     else{[m
[31m-        catapult.move_voltage(0);[m
[32m+[m[32m        hang.move_voltage(0);[m[41m[m
     }[m
     [m
     // wing code[m
 		if(master.get_digital_new_press(DIGITAL_DOWN)){[m
[31m-      if(wings == false) {[m
[32m+[m[32m      if(wing1 == true) {[m[41m[m
[32m+[m[32m          wing1.set_value(false);[m[41m[m
[32m+[m[41m      [m
[32m+[m[32m      } if(wing1 == false) {[m[41m[m
           wing1.set_value(true);[m
[32m+[m[32m      }[m[41m[m
[32m+[m[32m    }[m[41m[m
[32m+[m[41m	[m
[32m+[m	[32mif(master.get_digital_new_press(DIGITAL_B)){[m[41m[m
[32m+[m[32m      if(wing2 == false) {[m[41m[m
           wing2.set_value(true);[m
[31m-          wings = true;[m
       [m
[31m-      } else if(wings == true) {[m
[31m-          wing1.set_value(false);[m
[32m+[m[32m      } if(wing2 == true) {[m[41m[m
           wing2.set_value(false);[m
[31m-          wings = false;[m
       }[m
     }[m
 [m
     if(master.get_digital_new_press(DIGITAL_UP)){[m
[31m-      if(Vwings == false) {[m
[31m-          Vwing1.set_value(true);[m
[31m-          Vwing2.set_value(true);[m
[31m-          Vwings = true;[m
[32m+[m[32m      if(Vwing == false) {[m[41m[m
[32m+[m[32m          Vwing.set_value(true);[m[41m[m
       [m
[31m-      } else if(Vwings == true) {[m
[31m-          Vwing1.set_value(false);[m
[31m-          Vwing2.set_value(false);[m
[31m-          Vwings = false;[m
[32m+[m[32m      } else if(Vwing == true) {[m[41m[m
[32m+[m[32m          Vwing.set_value(false);[m[41m[m
       }[m
     }[m
[31m-    // blocker code[m
[31m-		if(master.get_digital_new_press(DIGITAL_B)) {[m
[31m-      if(Hang == false){[m
[31m-          Hang1.set_value(true);[m
[31m-          Hang2.set_value(true);[m
[31m-          Hang = true;[m
[31m-      }[m
[31m-      else if(Hang == true){[m
[31m-        Hang1.set_value(false);[m
[31m-        Hang2.set_value(false);[m
[31m-        Hang = false;[m
[31m-            }[m
[31m-        }[m
[32m+[m[41m[m
[32m+[m	[32mif(master.get_digital_new_press(DIGITAL_UP)){[m[41m[m
[32m+[m[32m      if(Rachet == true) {[m[41m[m
[32m+[m[32m          Rachet.set_value(false);[m[41m[m
[32m+[m	[32m  }[m[41m[m
[32m+[m	[32m}[m[41m[m
     pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME[m
   }[m
 }[m
\ No newline at end of file[m
