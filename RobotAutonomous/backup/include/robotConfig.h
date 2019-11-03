vex::brain Brain;
vex::controller Controller = vex::controller();
vex::motor MotorDriveL = vex::motor (vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor MotorDriveR = vex::motor (vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor MotorIntakeL = vex::motor (vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor MotorIntakeR = vex::motor (vex::PORT12, vex::gearSetting::ratio18_1, false);
vex::motor MotorArm1 = vex::motor (vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor MotorArm2 = vex::motor (vex::PORT13, vex::gearSetting::ratio18_1, false);
vex::motor MotorSlide = vex::motor (vex::PORT4, vex::gearSetting::ratio18_1, false);