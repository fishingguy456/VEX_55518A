/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

vex::brain Brain;
vex::controller Controller1 = vex::controller();
vex::motor MotorDriveLeft = vex::motor (vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor MotorDriveRight = vex::motor (vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor LiftMotor1 = vex::motor (vex::PORT12, vex::gearSetting::ratio18_1, false);
vex::motor LiftMotor2 = vex::motor (vex::PORT8, vex::gearSetting::ratio18_1, false);
vex::motor MidMotor = vex::motor (vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor IntakeMotor1 = vex::motor (vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor IntakeMotor2 = vex::motor (vex::PORT7, vex::gearSetting::ratio18_1, false);
    