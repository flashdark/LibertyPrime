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
void (*auton_p)();

///////////////////////////////////////////////////////////////////////////////
// Read Select Mode Pot
// Must be done prior to autonomous mode,
///////////////////////////////////////////////////////////////////////////////
// Pot Read Values = 8, 530, 1000, 1495, 1975, 2530, 3100, 3800, 4095
void getAutonMode() {
  int modePotValue = analogRead(SELECT_MODE_POT);
  lcdSetBacklight(uart2, true);


  // 1st choice
  if (modePotValue <= 100) {
    lcdSetText(uart2, 1, STRING_AUTON_1);
    auton_p = &auton1;
  }
  // 2nd choice
  else if (modePotValue <= 700) {
    lcdSetText(uart2, 1, STRING_AUTON_2);
    auton_p = &auton2;
  }
  // 3rd choice
  else if (modePotValue <= 1250) {
    lcdSetText(uart2, 1, STRING_AUTON_3);
    auton_p = &auton3;
  }
  // 4th choice
  else if (modePotValue <= 1700) {
    lcdSetText(uart2, 1, STRING_AUTON_4);
    auton_p = &auton4;
  }
  // 5th choice
  else if (modePotValue <= 2250) {
    lcdSetText(uart2, 1, STRING_AUTON_5);
    auton_p = &auton5;
  }
  // 6th choice
  else if (modePotValue <= 2800) {
    lcdSetText(uart2, 1, STRING_AUTON_6);
    auton_p = &auton6;
  }
  // 7th choice
  else if (modePotValue <= 3450) {
    lcdSetText(uart2, 1, STRING_AUTON_7);
    auton_p = &auton7;
  }
  // 8th choice
  else if (modePotValue <= 3950) {
    lcdSetText(uart2, 1, STRING_AUTON_8);
    auton_p = &auton8;
  }
  // 9th choice
  else if (modePotValue > 4075) {
    lcdSetText(uart2, 1, STRING_AUTON_9);
    auton_p = &auton9;
  }
  else
  {
    return;
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
  char lcdTextLine[16];
  static int lcdButtonsPressed=0;

  // once lcd button pressed keep updating display
  // until only center button pressed
  // allows live update of select pots
  if (lcdReadButtons(uart2)) {
    lcdButtonsPressed = lcdReadButtons(uart2);
  }

  if (lcdButtonsPressed == (LCD_BTN_LEFT | LCD_BTN_CENTER)) {
    lcdSetBacklight(uart2, true); // Turn on LCD Backlight

    // Display liftEncoder for calibrating fastack, & Mogo Pot
    sprintf(lcdTextLine, "L%d M%d A%d",
      encoderGet(liftEncoder), analogRead(MOGO_POT), analogRead(ARM_POT));
    lcdSetText(uart2, 1, lcdTextLine);

    // Display selectModePot for calibrating auton selection
    sprintf(lcdTextLine, "SP=%d CP=%d",
      analogRead(SELECT_MODE_POT), analogRead(SELECT_COLOR_POT));
    lcdSetText(uart2, 2, lcdTextLine);
  } else if (lcdButtonsPressed == (LCD_BTN_LEFT | LCD_BTN_RIGHT)) {
    lcdSetBacklight(uart2, true); // Turn on LCD Backlight

    // Display liftEncoder for calibrating fastack, & Mogo Pot
    sprintf(lcdTextLine, "L%d M%d A%d",
      encoderGet(liftEncoder), analogRead(MOGO_POT), analogRead(ARM_POT));
    lcdSetText(uart2, 1, lcdTextLine);

    // Display left and right drive encoders
    sprintf(lcdTextLine, "LE=%d RE=%d",
      encoderGet(leftDriveEncoder), encoderGet(rightDriveEncoder));
    lcdSetText(uart2, 2, lcdTextLine);
  } else if (lcdButtonsPressed == LCD_BTN_LEFT) {
    lcdSetBacklight(uart2, true); // Turn on LCD Backlight

    // Display the Primary Robot battery voltage
    sprintf(lcdTextLine, "M:%1.2fV, E: %1.2fV", powerLevelMain() / 1000.0,
            analogRead(PWR_EXP_PORT) / 280.0);
    lcdSetText(uart2, 1, lcdTextLine);

    // Display the Backup battery voltage
    sprintf(lcdTextLine, "B:%1.2fV", powerLevelBackup() / 1000.0);
    lcdSetText(uart2, 2, lcdTextLine);

  } else if (lcdButtonsPressed == LCD_BTN_CENTER) {
    // Turn off LCD Backlight and clear screen
    lcdSetBacklight(uart2, false);
    lcdSetText(uart2, 1, "");
    lcdSetText(uart2, 2, "");

    // Turn off live update of data
    lcdButtonsPressed = 0;
  } else if ((lcdButtonsPressed == LCD_BTN_RIGHT) || !isEnabled()) {
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
  (*auton_p)();
  // switch (g_selectedAutonomous) {
  // case 1:
  //   auton1();
  //   break;
  // case 2:
  //   auton2();
  //   break;
  // case 3:
  //   auton3();
  //   break;
  // case 4:
  //   auton4();
  //   break;
  // case 5:
  //   auton5();
  //   break;
  // case 6:
  //   auton6();
  //   break;
  // case 7:
  //   auton7();
  //   break;
  // case 8:
  //   auton8();
  //   break;
  // case 9: // Skills Auton
  //   auton9();
  //   break;
  // default:
  //   lcdSetText(uart2, 1, "No Valid Choice");
  //   lcdSetText(uart2, 2, "   Was Made");
  //   break;
  // } // switch
}
