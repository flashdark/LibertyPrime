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
void mobileGoalControl()
{
  int mobileGoalPower = 100;
  int mobileHoldPower = 30;
  bool leftpressed = joystickGetDigital(JOY_MASTER,BTN7_LEFT_THUMB,JOY_LEFT);
  bool rightpressed = joystickGetDigital(JOY_MASTER,BTN7_LEFT_THUMB,JOY_RIGHT);
  if(leftpressed)
  {
    motorSet(MOBILE_GOAL_MOTOR,mobileGoalPower);
  }
  else if(rightpressed)
  {
    motorSet(MOBILE_GOAL_MOTOR,-mobileGoalPower);

  }
  else
  {
    if(analogRead(MOBILE_GOAL_POT) >= 340)
    {
      motorSet(MOBILE_GOAL_MOTOR,-mobileHoldPower);
    }
    else
    {
      motorSet(MOBILE_GOAL_MOTOR,0);
    }
  }
  char buffer[16];
  sprintf(buffer,"%d",analogRead(MOBILE_GOAL_POT));
  lcdSetText(uart2,1,buffer);

}
void clawControl () {
   // TBD add code
}

void liftControl () {
   // TODO add code
   int liftPower = 127;
   bool liftup = joystickGetDigital(JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_UP);
   bool liftdown = joystickGetDigital(JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_DOWN);
   if (liftup)
   {
     motorSet(LIFT_MOTOR,liftPower);
   }
   else if (liftdown)
   {
     motorSet(LIFT_MOTOR,-liftPower);
   }

   else
   {
     motorSet(LIFT_MOTOR,0);
   }
}

void armControl () {
  int state = 0;
   if((joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,BTN_ARM_DOWN) || joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,BTN_ARM_DOWN)) && state == 0)
   {
     motorSet(ARM_MOTOR,50);
     state = 1;
   }

  //  if(state == 1)
  //  {
  //    if (encoderGet(ArmEncoder) <= SECTOR1)
  //    {
  //      motorSet(ARM_MOTOR,0);
  //    }
   //
  //    if (encoderGet(ArmEncoder) >= SECTOR1 && encoderGet(ArmEncoder) <= SECTOR2)
  //    {
  //      motorSet(ARM_MOTOR,-15)
  //    }
   //
  //  }
}

// drivecontrol reads the analog stick value and assigns it to the drive motors
// the left stick controls left drive and right stick controls right drive
// If the stick's Y-axis is greater than the threshold
//  ...the motors are assigned the stick's analog value
// Else the readings are within the threshold, so
// ...the motors are stopped with a power level of 0
void driveControl () {
  int powerLeft = joystickGetAnalog(JOY_MASTER, STK3_LEFT_Y);
  if (abs(powerLeft) > STICK_THRESHOLD) {
    motorLeftDriveSet(powerLeft);
    //delay(20); -gw delay should be run with any branch
  } else {
    motorLeftDriveSet(0);
  }

  delay(20);

  int powerRight = joystickGetAnalog(JOY_MASTER, STK2_RIGHT_Y);
  if (abs(powerRight) > STICK_THRESHOLD) {
    motorRightDriveSet(powerRight);
  } else {
    motorRightDriveSet(0);
  }
  // char buffer[16];
  // sprintf(buffer,"%d",encoderGet(LeftDriveEncoder));
  // lcdSetText(uart2,1,buffer);
  // sprintf(buffer,"%d",encoderGet(RightDriveEncoder));
  // lcdSetText(uart2, 2,buffer);

}


void operatorControl() {
  while (1) {
    //char buffer[16];
    //sprintf(buffer,"%d",encoderGet(LeftDriveEncoder));
    //lcdSetText(uart2,1,buffer);
    delay(20);
    driveControl();
    mobileGoalControl();
    armControl();
    liftControl();
    clawControl();

    delay(20);


    // If any LCD button is pressed from operatorControl, display Robot status.
    // This is useful since operatorControl is run if not in competition mode.
    while (lcdReadButtons(uart2))
    {
      displayRobotStatus();
      delay(200);
    }
  }
}
