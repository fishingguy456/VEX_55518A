using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor CL1;
extern motor CR1;
extern motor LiftMotor2;
extern motor IntakeMotor2;
extern motor LiftMotor1;
extern motor MidMotor;
extern motor IntakeMotor1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );