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
  MotorDriveLeft.spin(forward, 6, volt);
  MotorDriveRight.spin(forward, 6, volt);
  while(MotorDriveLeft.position(degrees)<=1080){//move forward a little
    MotorDriveLeft.spin(forward, 6, volt);
    MotorDriveRight.spin(forward, 6, volt);
  }MotorDriveLeft.resetRotation();
  IntakeMotor1.spin(forward, 6, volt);
  IntakeMotor2.spin(forward, 6, volt);
  while(MotorDriveLeft.position(degrees)<=3600){//go until a certain distance is met
    MotorDriveLeft.spin(forward, 6, volt);
    MotorDriveRight.spin(forward, 6, volt);
    IntakeMotor1.spin(forward, 12, volt);
    IntakeMotor2.spin(forward, 12, volt);
  }MotorDriveLeft.resetRotation();
  turnRight(65);//turn right x degrees
  while(MotorDriveLeft.position(degrees)<=1800){//move forward
    MotorDriveLeft.spin(forward, 6, volt);
    MotorDriveRight.spin(forward, 6, volt);
  }MotorDriveLeft.resetRotation();
  MidMotor.spin(forward,6, volt);
  while(MidMotor.position(degrees)<=1440){//lift the slide
    MidMotor.spin(forward, 3, volt);
  }MidMotor.resetRotation();
  MidMotor.spin(reverse,6, volt);
  while(MidMotor.position(degrees)<=1440){//lower the slide again
    MidMotor.spin(reverse, 3, volt);
  }MidMotor.resetRotation();
}

void turnRight(double dabbers){
  while(MotorDriveLeft.position(degrees)<=dabbers){//5 is just a guess
    MotorDriveLeft.spin(forward, 6, volt);
    MotorDriveRight.spin(reverse, 6, volt);
  }MotorDriveLeft.resetRotation();
}

void turnLeft(double dabbers){
  while(MotorDriveLeft.position(degrees)<=dabbers){//5 is just a guess
    MotorDriveLeft.spin(reverse, 6, volt);
    MotorDriveRight.spin(forward, 6, volt);
  }MotorDriveRight.resetRotation();
}