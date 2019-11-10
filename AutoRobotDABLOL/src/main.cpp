/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\qukev                                            */
/*    Created:      Sun Nov 03 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// MotorDriveLeft       motor         1               
// MotorDriveRight      motor         10              
// LiftMotor1           motor         12              
// LiftMotor2           motor         8               
// MidMotor             motor         3               
// IntakeMotor1         motor         2               
// IntakeMotor2         motor         7               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
void turnRight(double degrees);
void turnLeft(double degrees);
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
    if(Controller1.ButtonA.pressing()){
      break;
    }
  }
  int autoCount = 0;
  MotorDriveLeft.spin(forward, 6, volt);
  MotorDriveRight.spin(forward, 6, volt);
  while(autoCount <= 25){//move forward a little
    MotorDriveLeft.spin(forward, 6, volt);
    MotorDriveRight.spin(forward, 6, volt);
    autoCount++;
  }
  IntakeMotor1.spin(forward, 6, volt);
  IntakeMotor2.spin(forward, 6, volt);
  autoCount = 0;
  while(autoCount <= 500){//go until a certain distance is met
    MotorDriveLeft.spin(forward, 6, volt);
    MotorDriveRight.spin(forward, 6, volt);
    IntakeMotor1.spin(forward, 6, volt);
    IntakeMotor2.spin(forward, 6, volt);
    autoCount++;
  }
  turnRight(65);//turn right x degrees
  autoCount = 0;
  while(autoCount <= 250){//move forward
    MotorDriveLeft.spin(forward, 6, volt);
    MotorDriveRight.spin(forward, 6, volt);
  }
  autoCount = 0;
  MidMotor.spin(forward,6, volt);
  while(autoCount <= 25){//lift the slife
    MidMotor.spin(forward, 3, volt);
  }autoCount = 0;
  MidMotor.spin(reverse,6, volt);
  while(autoCount <= 25){//lower the slide again
    MidMotor.spin(reverse, 3, volt);
  }
}

void turnRight(double degrees){
  int autoCount = 0;
  while(autoCount <= degrees/5){//5 is just a guess
    MotorDriveLeft.spin(forward, 6, volt);
    MotorDriveRight.spin(reverse, 6, volt);
    autoCount++;
  }
}

void turnLeft(double degrees){
  int autoCount = 0;
  while(autoCount <= degrees/5){//5 is just a guess
    MotorDriveLeft.spin(reverse, 6, volt);
    MotorDriveRight.spin(forward, 6, volt);
    autoCount++;
  }
}