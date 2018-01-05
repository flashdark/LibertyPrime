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
  lcdSetBacklight(uart2, true);
  int modePotValue = analogRead(SELECT_MODE_POT);
  char buff[16];
  sprintf(buff,"%d",modePotValue);
  lcdSetText(uart2,2,buff);
  g_selectedAutonomous = 0;

  // 1st choice
  if (modePotValue <= 5) {
    lcdSetText(uart2, 1, STRING_AUTON_1);
    g_selectedAutonomous = 1;
  }
  // 2nd choice
  else if (modePotValue <= 345) {
    lcdSetText(uart2, 1, STRING_AUTON_2);
    g_selectedAutonomous = 2;
  }
  // 3rd choice
  else if (modePotValue <= 905) {
    lcdSetText(uart2, 1, STRING_AUTON_3);
    g_selectedAutonomous = 3;
  }
  // 4th choice
  else if (modePotValue <= 1410) {
    lcdSetText(uart2, 1, STRING_AUTON_4);
    g_selectedAutonomous = 4;
  }
  // 5th choice
  else if (modePotValue <= 1880) {
    lcdSetText(uart2, 1, STRING_AUTON_5);
    g_selectedAutonomous = 5;
  }
  // 6th choice
  else if (modePotValue <= 2430) {
    lcdSetText(uart2, 1, STRING_AUTON_6);
    g_selectedAutonomous = 6;
  }
  // 7th choice
  else if (modePotValue <= 3025) {
    lcdSetText(uart2, 1, STRING_AUTON_7);
    g_selectedAutonomous = 7;
  }
  // 8th choice
  else if (modePotValue <= 3685) {
    lcdSetText(uart2, 1, STRING_AUTON_8);
    g_selectedAutonomous = 8;
  }
  // 9th choice
  else if (modePotValue <= 4075) {
    lcdSetText(uart2, 1, STRING_AUTON_9);
    g_selectedAutonomous = 9;
  }
  // 10th choice
  else if (modePotValue > 4076) {
    lcdSetText(uart2, 1, STRING_AUTON_A);
    g_selectedAutonomous = 10;
  }
} // end getAutonMode

///////////////////////////////////////////////////////////////////////////////
// Use LCD buttons to display
// Battery Voltages
// Disable LCD Backlight
// Autonomous Selection
// called from initialize and opcontrol
///////////////////////////////////////////////////////////////////////////////
void displayRobotStatus() {
  char mainBattery[16], backupBattery[16];

  // When Left and Middle button pressed
  // display raw value from autonModePot for calibrating auton selection
  if ((lcdReadButtons(uart2) & LCD_BTN_LEFT) &&
      (lcdReadButtons(uart2) & LCD_BTN_CENTER)) {
    // TBD

    // Short delay for the LCD refresh rate
    taskDelay(100);
  } else if (lcdReadButtons(uart2) & LCD_BTN_LEFT) {
    lcdSetBacklight(uart2, true); // Turn on LCD Backlight

    // Display the Primary Robot battery voltage
    sprintf(mainBattery, "M:%1.2fV, E: %1.2fV", powerLevelMain() / 1000.0,
            analogRead(PWR_EXP_PORT) / 280.0);
    lcdSetText(uart2, 1, mainBattery);

    // Display the Backup battery voltage
    sprintf(backupBattery, "B:%1.2fV", powerLevelBackup() / 1000.0);
    lcdSetText(uart2, 2, backupBattery);

    // Short delay for the LCD refresh rate
    taskDelay(100);
  } else if (lcdReadButtons(uart2) & LCD_BTN_CENTER) {
    lcdSetBacklight(uart2, false); // Turn off LCD Backlight
    taskDelay(100);
  }
  // Right button calls this function from usercontrol() or during initialize.
  else if ((lcdReadButtons(uart2) & LCD_BTN_RIGHT) || !isEnabled()) {
    getAutonMode();
    taskDelay(100);
  }
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
  getAutonMode();
  char buf[17];
  sprintf(buf,"%d",g_selectedAutonomous);
  //lcdSetText(uart2,2,buf);
  switch (g_selectedAutonomous) {
  case 1:
    auton1();
    //sprintf(buf,"A1 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 2:
    auton2();
    //sprintf(buf,"A2 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 3:
    auton3();
    //sprintf(buf,"A3 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 4:
    auton4();
    //sprintf(buf,"A4 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 5:
    auton5();
    //sprintf(buf,"A5 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 6:
    auton6();

    break;
  case 7:
    auton7();
    //sprintf(buf,"A7 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 8:
    auton8();
    //sprintf(buf,"A8 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 9: // Skills Auton
    auton9();
    //sprintf(buf,"A9 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 10:
    autonA();
    //sprintf(buf,"A10 Called");
    //lcdSetText(uart2,2,buf);
    break;
  default:
    lcdSetText(uart2, 1, "No Valid Choice");
    lcdSetText(uart2, 2, "   Was Made");
    break;
  } // switch
}
