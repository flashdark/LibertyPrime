/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions
 * related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "robot.h"

///////////////////////////////////////////////////////////////////////////////
// Global Variable Initialization
///////////////////////////////////////////////////////////////////////////////
unsigned g_selectedAutonomous = 0;

///////////////////////////////////////////////////////////////////////////////
// Read Select Mode Pot
// Must be done prior to autonomous mode,
///////////////////////////////////////////////////////////////////////////////
void getAutonMode() {
  // when converting from RobotC 
  // 1) read Selection POT status once
  // 2) change if-if-if... to if-else if-else if... just need < term
  // 3) don't distinguish between match and skill auton here 
  //    use the STRING_AUTON_# define in robot.h to indicate that
  // 4) probably should use defines for POT values and store them in robot.h
  // 5) remove list when done


  // TBD Add Code
} // end getAutonMode

///////////////////////////////////////////////////////////////////////////////
// Use LCD buttons to display
// Battery Voltages
// Disable LCD Backlight
// Autonomous Selection
// called from initialize and opcontrol
///////////////////////////////////////////////////////////////////////////////
void displayRobotStatus() {

  // 1) ADD When Left and Middle button pressed
  //    display raw value from autonModePot for calibrating auton selection
  // 2) Convert the rest of the RobotC Status code

} // end displayRobotStatus()

/*
   Runs the user autonomous code. This function will be started in its own 
   task with the default priority and stack size whenever the robot is 
   enabled via the Field Management System or the VEX Competition Switch in 
   the autonomous mode.

   If the robot is disabled or communications is lost, the autonomous task 
   will be stopped by the kernel. Re-enabling the robot will restart the 
   task, not re-start it from where it left off.

   Code running in the autonomous task cannot access information from the 
   VEX Joystick. However, the autonomous function can be invoked from another 
   task if a VEX Competition Switch is not available, and it can access 
   joystick information if called in this way.

   The autonomous task may exit, unlike operatorControl() which should never
   exit. If it does so, the robot will await a switch to another mode or
   disable/enable cycle.
*/

void autonomous() {
  // Convert AUTON SWITCH code from RobotC  
}
