#include "main.h"
#include <fstream>

using namespace std;

void wait(int sec) {
  pros::delay(sec);
}

void deployintake() {
catapult.move_voltage(-12000);
}

void outtake() {
intake.move_voltage(12000);
}


void intaketriball() {
intake.move_voltage(-12000);
}

void stopintake() {
intake.move_voltage(0);
}

void expandWings() {
  wing1.set_value(true);
  wing2.set_value(true);
}

void retractWings() {
  wing1.set_value(false);
  wing2.set_value(false);
}

void shootCata() {
	catapult.move_voltage(9000);
}

void stopCata() {
	catapult.move_voltage(0);
}
