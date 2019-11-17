/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\qukev                                            */
/*    Created:      Sun Nov 17 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// CL1                  motor         1
// CR1                  motor         10
// LiftMotor2           motor         8
// IntakeMotor2         motor         9
// LiftMotor1           motor         12
// MidMotor             motor         3
// IntakeMotor1         motor         2
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
void drive(int cm, int speed) {
  int driveDegree = 0;
  int totalDegree = 10.87 * cm;
  while (1) {
    driveDegree = CL1.rotation(rotationUnits::deg);
    if (cm > 0) {
      CL1.spin(directionType::fwd, speed, vex::velocityUnits::rpm);
      CR1.spin(directionType::fwd, speed, vex::velocityUnits::rpm);
      if (driveDegree >= totalDegree)
        break;
    }
    if (cm < 0) {
      CL1.spin(directionType::rev);
      CR1.spin(directionType::rev);
      if (driveDegree <= totalDegree)
        break;
    }
  }
  CL1.stop(brakeType::brake);
  CR1.stop(brakeType::brake);
  CL1.resetRotation();
}

void arcDrive(int cm) {
  int driveDegree = 0;
  int totalDegree = 10.87 * cm;
  while (1) {
    driveDegree = CL1.rotation(rotationUnits::deg);
    if (cm > 0) {
      CL1.spin(directionType::fwd, 60, vex::velocityUnits::pct);
      CR1.spin(directionType::fwd, 40, vex::velocityUnits::pct);
      if (driveDegree >= totalDegree)
        break;
    }
    if (cm < 0) {
      CL1.spin(directionType::rev);
      CR1.spin(directionType::rev);
      if (driveDegree <= totalDegree)
        break;
    }
  }
  CL1.stop(brakeType::brake);
  CR1.stop(brakeType::brake);
  CL1.resetRotation();
}

void rotate(int degree) {
  int driveDegree = 0;
  int totalDegree = 3.67 * degree;
  while (1) {
    CL1.spin(directionType::fwd);
    CR1.spin(directionType::rev);
    driveDegree = CL1.rotation(rotationUnits::deg);
    if (driveDegree >= totalDegree)
      break;
  }
  CL1.stop(brakeType::brake);
  CR1.stop(brakeType::brake);
  CL1.resetRotation();
}

void roller(int speed) {
  if (speed > 0) {
    IntakeMotor1.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
    IntakeMotor2.spin(vex::directionType::fwd, speed, vex::velocityUnits::pct);
  }
  if (speed < 0) {
    IntakeMotor1.spin(vex::directionType::rev, speed * -1,
                      vex::velocityUnits::pct);
    IntakeMotor2.spin(vex::directionType::rev, speed * -1,
                      vex::velocityUnits::pct);
  }
  if (speed == 0) { // 0 is off
    IntakeMotor1.stop(brakeType::hold);
    IntakeMotor2.stop(brakeType::hold);
  }
}

void mid(int degree) {
  int driveDegree = 0;
  int totalDegree = 4.89 * degree;
  while (1) {
    MidMotor.spin(directionType::fwd, 20, vex::velocityUnits::pct);
    driveDegree = MidMotor.rotation(rotationUnits::deg);
    if (driveDegree >= totalDegree) {
      MidMotor.stop(brakeType::coast);
      break;
    }
  }
}

int main() {
  vexcodeInit();
  double leftAxis;
  double rightAxis;
  double CL1Velocity, CR1Velocity;
  double midRotation = 0;
  Controller1.Screen.clearScreen();
  // int testVar =0;

  while (1) {
    if (Controller1.ButtonA.pressing())
      break;
  }
  /*
  roller(100);
  drive(95, 120);
  task::sleep(1000);
  roller(0);
  rotate(145);
  arcDrive(50);
  drive(40, 60);
  roller(-10);
  mid(90);
  roller(-20);
  drive(-35,40);
  roller(0);
  */

  while (1) {
    leftAxis = Controller1.Axis3.value();
    rightAxis = Controller1.Axis1.value() * 0.7;
    CL1Velocity = ((leftAxis + rightAxis) / 2);
    CR1Velocity = ((leftAxis - rightAxis) / 2);
    midRotation = MidMotor.rotation(rotationUnits::deg);

    // chasis
    CL1.spin(vex::directionType::fwd, CL1Velocity, vex::velocityUnits::pct);
    CR1.spin(vex::directionType::fwd, CR1Velocity, vex::velocityUnits::pct);

    // intake motors
    if (Controller1.ButtonA.pressing()) {
      IntakeMotor1.spin(vex::directionType::fwd, CL1Velocity,
                        vex::velocityUnits::pct);
      IntakeMotor2.spin(vex::directionType::fwd, CR1Velocity,
                        vex::velocityUnits::pct);
    } else {
      if (Controller1.ButtonL1.pressing()) {
        IntakeMotor1.spin(vex::directionType::fwd, 100,
                          vex::velocityUnits::pct);
        IntakeMotor2.spin(vex::directionType::fwd, 100,
                          vex::velocityUnits::pct);
      } else if (Controller1.ButtonL2.pressing()) {
        IntakeMotor1.spin(vex::directionType::rev, 100,
                          vex::velocityUnits::pct);
        IntakeMotor2.spin(vex::directionType::rev, 100,
                          vex::velocityUnits::pct);
      } else {
        IntakeMotor1.stop(brakeType::hold);
        IntakeMotor2.stop(brakeType::hold);
      }
    }

    // mid motor
    if (Controller1.ButtonR1.pressing()) {
      MidMotor.spin(vex::directionType::fwd, 20, vex::velocityUnits::pct);
    } else if (Controller1.ButtonR2.pressing()) {
      MidMotor.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
    } else {
      MidMotor.stop(brakeType::hold);
    }

    // lift motors
    if (Controller1.ButtonUp.pressing()) {
      // checking mid motor position
      if (midRotation < 150) {
        MidMotor.spin(vex::directionType::fwd, 40, vex::velocityUnits::pct);
      }
      LiftMotor1.spin(vex::directionType::fwd, 40, vex::velocityUnits::pct);
      LiftMotor2.spin(vex::directionType::fwd, 40, vex::velocityUnits::pct);
    } else if (Controller1.ButtonDown.pressing()) {
      LiftMotor1.spin(vex::directionType::rev, 40, vex::velocityUnits::pct);
      LiftMotor2.spin(vex::directionType::rev, 40, vex::velocityUnits::pct);
    } else {
      LiftMotor1.stop(brakeType::hold);
      LiftMotor2.stop(brakeType::hold);
    }

    Controller1.Screen.clearLine(1);
    Controller1.Screen.setCursor(1, 0);
    Controller1.Screen.print("midMotor: %.2f", midRotation);
    Controller1.Screen.clearLine(2);
    Controller1.Screen.setCursor(2, 0);
    // Controller1.Screen.print("Right Axis: %.2f",rightAxis);
    // Controller1.Screen.clearLine(3);
    // Controller1.Screen.setCursor(3,0);
    // Controller1.Screen.print("MRn: %.2f",midRotation);
  }
}
