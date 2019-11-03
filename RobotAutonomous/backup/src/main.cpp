/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\qukev                                            */
/*    Created:      Sun Oct 06 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "robotConfig.h"
//#include "autoFunction"
using namespace vex;
// A global instance of vex::brain used for printing to the V5 brain screen
// define your global instances of motors and other devices here


int main() {
    vex::task::sleep(2000);
    Brain.Screen.print("User Program has Started");
    /*
    double wheelDiameterCM = 10.16;
    double travelTargetCM = 20;
    double circumference = wheelDiameterCM*3.141592;
    double degreesToRotate = (360*travelTargetCM)/circumference;
    */
    while(Controller.ButtonR1.pressing()){
      MotorIntakeL.spin(directionType::fwd, 50, velocityUnits::rpm);
      MotorIntakeR.spin(directionType::rev, 50, velocityUnits::rpm);
    }
}
