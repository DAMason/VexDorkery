/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       vex                                                       */
/*    Created:      10/15/2023, 8:45:03 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

void MoveForward(float, int);



bool FlyWheelSpinning=false;


motor FrontLeftMotor = motor(PORT2, ratio18_1, false);
motor FrontRightMotor = motor(PORT9, ratio18_1, true);
motor BackLeftMotor = motor(PORT10, ratio18_1, false);
motor BackRightMotor = motor(PORT1, ratio18_1, true);

motor FlyWheelMotor = motor(PORT16,ratio6_1, true);

controller Controller1 = controller(primary);


// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {

   FlyWheelMotor.setVelocity(0, rpm);

  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................    
    FrontLeftMotor.setVelocity(Controller1.Axis3.position(), percent);
    BackLeftMotor.setVelocity(Controller1.Axis3.position(), percent);
    FrontRightMotor.setVelocity(Controller1.Axis2.position(), percent);
    BackRightMotor.setVelocity(Controller1.Axis2.position(), percent);
    FrontLeftMotor.spin(forward);
    BackLeftMotor.spin(forward);
    FrontRightMotor.spin(forward);
    BackRightMotor.spin(forward);

  // What is the state of button L1
    bool L1Down = Controller1.ButtonL1.pressing();
  // What is the state of button L1
    bool L2Down = Controller1.ButtonL2.pressing();
  // What is the state of button R1
    bool R1Down = Controller1.ButtonR1.pressing();
  // What is the state of button R1
    bool R2Down = Controller1.ButtonR2.pressing();


    if (R1Down) {
      FlyWheelMotor.setVelocity(-500, rpm);
    }
    if (R2Down) {
      FlyWheelMotor.setVelocity(0, rpm);
    }

    if (L1Down) {
      FlyWheelMotor.setVelocity(500, rpm);
    }
    if (L2Down) {
      FlyWheelMotor.setVelocity(0, rpm);
    }

    FlyWheelMotor.spin(forward);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}



// Function to move forward, howfar is in INCHES

void MoveForward(float howfar, int howfast) {

//units are wheel rotations


  FrontLeftMotor.spinFor(forward,3,turns,false); //false keeps turning
  FrontRightMotor.spinFor(forward,3,turns,false);
  BackLeftMotor.spinFor(forward,3,turns,false);
  BackRightMotor.spinFor(forward,3,turns,true); //so waits until this one ends

 
return;

}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
