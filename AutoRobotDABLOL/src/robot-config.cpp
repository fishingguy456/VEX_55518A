#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor MotorDriveLeft = motor(PORT1, ratio18_1, false);
motor MotorDriveRight = motor(PORT10, ratio18_1, true);
motor LiftMotor1 = motor(PORT12, ratio18_1, false);
motor LiftMotor2 = motor(PORT8, ratio18_1, true);
motor MidMotor = motor(PORT3, ratio18_1, false);
motor IntakeMotor1 = motor(PORT2, ratio18_1, false);
motor IntakeMotor2 = motor(PORT7, ratio18_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}