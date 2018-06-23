/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "robot.h"

/*
   Runs the user operator control code. This function will be started in its
   own task with the default priority and stack size whenever the robot is
   enabled via the Field Management System or the VEX Competition Switch in
   the operator control mode. If the robot is disabled or communications is
   lost, the operator control task will be stopped by the kernel. Re-enabling
   the robot will restart the task, not resume it from where it left off.

   If no VEX Competition Switch or Field Management system is plugged in, the
   VEX Cortex will run the operator control task. Be warned that this will
   also occur if the VEX Cortex is tethered directly to a computer via the
   USB A to A cable without any VEX Joystick attached.

   Code running in this task can take almost any action, as the VEX Joystick
   is available and the scheduler is operational. However, proper use of
   delay() or taskDelayUntil() is highly recommended to give other tasks
   (including system tasks such as updating LCDs) time to run.

   This task should never exit; it should end with some kind of infinite loop,
   even if empty.
 */

 //////////////////////////////////////////////////////////////////////
 // Cone intake Control
 // Cone Egress - drop cone
 // Cone Ingress - pickup cone
 // Cone hold
 // Intake Idle - allows fastack to control intake if not actively used
 /////////////////////////////////////////////////////////////////////
void intakeControl () {
  static int active_ingress = 0;
  static int not_idle = 1;

  if (joystickGetDigital(BTN_INTAKE_EGRESS)) {
    motorSet(INTAKE_MOTOR, INTAKE_EGRESS_POWER);
    active_ingress = 0;
    not_idle = 1;
  } else if (joystickGetDigital(BTN_INTAKE_INGRESS)) {
    motorSet(INTAKE_MOTOR, INTAKE_INGRESS_POWER);
    active_ingress = 1;
  } else if (active_ingress) {
    motorSet(INTAKE_MOTOR, INTAKE_INGRESS_HOLD_POWER);
    active_ingress = 1;
    not_idle = 1;
  } else if (not_idle){
    motorSet(INTAKE_MOTOR,0);
    not_idle = 0;
  }
} // end intakeControl()

//////////////////////////////////////////////////////////////////////
// Arm Control (cone intake) - raise and lower arm holding cone intake
// Arm Down - to pick up cone
// Arm Up - get to near stack position fast
// Arm decel - soften the stop so not to knock cone out
// Arm Idle - allows fastack to control arm if not actively used
// //////////////////////////////////////////////////////////////////
// to work with fastack armControl cannot actively drive the motor
// to 0 when it is idle. it must only set the motor to idle after the
// button is released and then not call motorSet until the next time
// an arm button is released
/////////////////////////////////////////////////////////////////////
void armControl () {
   static int not_idle = 1;
   int armPotValue = analogRead(ARM_POT);

   if (joystickGetDigital(BTN_ARM_DOWN) && (armPotValue < ARM_DEPLOYED)) {
     motorSet(ARM_MOTOR, ARM_DOWN_POWER);
     not_idle = 1;
   } else if (joystickGetDigital(BTN_ARM_UP) && (armPotValue > ARM_DECEL_POINT)) {
     motorSet(ARM_MOTOR, ARM_UP_POWER);
     not_idle = 1;
   } else if (joystickGetDigital(BTN_ARM_UP) && (armPotValue > ARM_STOWED)) {
     motorSet(ARM_MOTOR, ARM_DECEL_POWER);
     not_idle = 1;
   } else if (not_idle) {
     motorSet(ARM_MOTOR,0);
     not_idle = 0;
   }
} // end armControl()

//////////////////////////////////////////////////////////////////////
// Lift Control - raise and lower lift
// Lift Down
// Lift Up
// Lift Idle - allows fastack to control lift if not actively used
/////////////////////////////////////////////////////////////////////
void liftControl () {
  static int not_idle = 1;

  if (joystickGetDigital(BTN_LIFT_DOWN)) {
    motorSet(LIFT_MOTOR, LIFT_DOWN_POWER);
    not_idle = 1;
  } else if (joystickGetDigital(BTN_LIFT_UP)) {
    motorSet(LIFT_MOTOR, LIFT_UP_POWER);
    not_idle = 1;
  } else if (not_idle) {
    motorSet(LIFT_MOTOR,0);
    not_idle = 0;
  }
} // end liftControl()

//////////////////////////////////////////////////////////////////////
// Mobile Goal Lift Control - pickup and place MoGo
// Mogo Lift Egress
// Mogo Lift Ingress
// Mogo Lift AutoScore - soft placement so cones are not knocked off
// Mogo Lift Idle - not implemented - fastack doesn't use mogo
//////////////////////////////////////////////////////////////////////
void mogoControl () {
  int mogoPotValue = analogRead(MOGO_POT);
  static int mogoAutoScore = 0;
  char lcdTextLine2[16];

  // test the non-autoscore joystick buttons first.
  // if they are pressed during autoscore,
  // exit autoscore and perform active user selection
  if (joystickGetDigital(BTN_MOGO_EGRESS) && (mogoPotValue < MOGO_DEPLOYED)) {
    motorSet(MOGO_MOTOR, MOGO_EGRESS_POWER);
    mogoAutoScore = 0;
  } else if (joystickGetDigital(BTN_MOGO_INGRESS) && (mogoPotValue > MOGO_STOWED)) {
    motorSet(MOGO_MOTOR, MOGO_INGRESS_POWER);
    mogoAutoScore = 0;
  } else if (joystickGetDigital(BTN_MOGO_AUTOSCORE) || mogoAutoScore) {
    // set stacked mogo gently
    // power mogo lift until weight of stacked mogo pulls it down
    // when mogo hit tile, apply a little power so it slide off easier
    mogoAutoScore = 1;
    if (mogoPotValue < MOGO_GRAVITY_POINT) {
      motorSet(MOGO_MOTOR, MOGO_EGRESS_POWER);

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_MOGO) {
        sprintf(lcdTextLine2, "MPot %d", mogoPotValue);
        lcdSetText(uart2, 1, "Mogo AutoScore");
        lcdSetText(uart2, 2, lcdTextLine2);
      }
    } else if (mogoPotValue < MOGO_PLACE_POINT) {
      motorSet(MOGO_MOTOR, 0);

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_MOGO) {
        sprintf(lcdTextLine2, "MPot %d", mogoPotValue);
        lcdSetText(uart2, 1, "Mogo AutoScore");
        lcdSetText(uart2, 2, lcdTextLine2);
      }
    } else if (mogoPotValue < MOGO_DEPLOYED) {
      motorSet(MOGO_MOTOR, -30);

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_MOGO) {
        sprintf(lcdTextLine2, "MPot %d", mogoPotValue);
        lcdSetText(uart2, 1, "Mogo AutoScore");
        lcdSetText(uart2, 2, lcdTextLine2);
      }
    } else {
      motorSet(MOGO_MOTOR, 0);
      mogoAutoScore = 0;

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_MOGO) {
        sprintf(lcdTextLine2, "MPot %d", mogoPotValue);
        lcdSetText(uart2, 1, "Mogo AutoScore");
        lcdSetText(uart2, 2, lcdTextLine2);
      }
    }
  } else {
    motorSet(MOGO_MOTOR, 0);
  }
}

//////////////////////////////////////////////////////////////////////
// Drive Control
// reads the analog stick value and assigns it to the drive motors
// via a lookup table to map to linear speed
// the left stick controls left drive and right stick controls right drive
// If the stick's Y-axis is greater than the threshold
//  ...the motors are assigned the stick's analog value
// Else the readings are within the threshold, so
// ...the motors are stopped with a power level of 0
// note that threshold is built in to the trueSpeed lookup table
//////////////////////////////////////////////////////////////////////
void driveControl () {
  int leftPower = joystickGetAnalog(STICK_LEFT_DRIVE);
  motorLeftDriveSet(sign(leftPower)*trueSpeed[abs(leftPower)]);

  int rightPower = joystickGetAnalog(STICK_RIGHT_DRIVE);
  motorRightDriveSet(sign(rightPower)*trueSpeed[abs(rightPower)]);
}

void operatorControl() {
  while (1) {
    driveControl();
    armControl();
    liftControl();
    intakeControl();
    mogoControl();

    displayRobotStatus();
    delay(20);
  }
}
