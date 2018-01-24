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
#include "config.h"

//debug defines
#define MOBILE_GOAL_DEBUG
//#define LIFT_DEBUG
//#define DRIVE_POWER_DEBUG
//#define DRIVE_ENCODER_POSITION_DEBUG
//#define ARM_POSITION_DEBUG
// #define ARM_SECTOR_DEBUG
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
  int mobileGoalPower = MOBILE_GOAL_POWER;  // 80% power
  int mobileHoldPower = MOBILE_GOAL_HOLD_POWER; //16% power
  bool leftpressed = joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_LEFT); // check Button 8L is pressed
  bool rightpressed = joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_RIGHT);// check Button 8R is pressed
  if(leftpressed)
  {
    motorSet(MOBILE_GOAL_MOTOR,mobileGoalPower); //retract mobile goal
  }
  else if(rightpressed)
  {
    motorSet(MOBILE_GOAL_MOTOR,-mobileGoalPower);//extend mobile goal
  }
  else if (joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_UP) && (analogRead(MOBILE_GOAL_POT) >= 475))
  {
      motorSet(MOBILE_GOAL_MOTOR,65);

  }
    else{
      if((analogRead(MOBILE_GOAL_POT) < 1300 )&& (analogRead(MOBILE_GOAL_POT) >= 160))
      {
        motorSet(MOBILE_GOAL_MOTOR,-mobileHoldPower);
      }//boundaries where hold power should be applied
       // apply hold power to stabilize mobile goal lift
      else{motorSet(MOBILE_GOAL_MOTOR,0);}

    }

  #ifdef MOBILE_GOAL_DEBUG
  char buffer[16];
  sprintf(buffer,"%d",analogRead(MOBILE_GOAL_POT));
  lcdSetText(uart2,1,buffer);
#endif
}
void intakeControl () {
static bool close;
   if(joystickGetDigital(JOY_MASTER,BTN7_LEFT_THUMB,JOY_LEFT)) //open claw if button 7L is pressed
   {
     motorSet(CLAW_MOTOR,127);//apply open power
     close = false;
     //holdCounter = 0;//reset close hold power counter
   }
   else if(joystickGetDigital(JOY_MASTER,BTN7_LEFT_THUMB,JOY_RIGHT))
   {
    motorSet(CLAW_MOTOR,-65);
    close = true;
     }

     else
     {
       if (close == true)
       {
          motorSet(CLAW_MOTOR,-10);
       }
       else
       {
       motorSet(CLAW_MOTOR,0);
     }
   }
 }


void liftControl () {
   int liftPower = LIFT_POWER;//maximum power to lift
   bool liftup = joystickGetDigital(JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_UP);//check if button 5U was pressed
   bool liftdown = joystickGetDigital(JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_DOWN);//check if button 5D was pressed
   if (liftup)//if lifting up
   {
     motorSet(LIFT_MOTOR,liftPower);//go up
   }
   else if (liftdown)//if moving down
   {
     motorSet(LIFT_MOTOR,-liftPower);//go down
   }

   else
   {
     motorSet(LIFT_MOTOR,0);//otherwise release power to ease strain on motors
   }
   #ifdef LIFT_DEBUG
   char buf[17];
   sprintf(buf,"%d",encoderGet(LiftEncoder));
   lcdSetText(uart2,1,buf);
   #endif
}
void armControl () {

  if(joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_UP))
  {
    motorSet(ARM_MOTOR,75);
  }

  else if(joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_DOWN))
  {
    motorSet(ARM_MOTOR,-75);
  }
  else
  {
    motorSet(ARM_MOTOR,0);
  }

  // int state = USER_CONTROL_STATE;//puts code in user controlled mode
  // int sector = 0;//arm position is divided into 7 sectors. These determin e the amount of hold power to be applied
  //  if((joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_DOWN)))//test if button 6D was pressed
  //  {
  //    motorSet(ARM_MOTOR,50);//move arm down
  //    state = HOLD_POWER_STATE;//move to hold power state
  //  }
  //
  //  else if (joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,BTN_ARM_UP))//test if button 6U was presed
  //  {
  //    motorSet(ARM_MOTOR,-50);//move arm up
  //    state = HOLD_POWER_STATE;//move to hold power state
  //  }
  //
  //  if(state == 1)
  //  {
  //    if (encoderGet(ArmEncoder) <= SECTOR1)//if arm encoder is less than start of hold power then release hold power and it is in sector0
  //    {
  //      motorSet(ARM_MOTOR,0);
  //      sector = 0;
  //    }
  //
  //    if (encoderGet(ArmEncoder) >= SECTOR1 && encoderGet(ArmEncoder) <= SECTOR2)//if arm encoder is between sectors 1 and 2, apply neccesary hold power for this region
  //    {
  //      motorSet(ARM_MOTOR,-15);
  //      sector = 1;
  //    }
  //
  //    if (encoderGet(ArmEncoder) >= SECTOR2 && encoderGet(ArmEncoder) <= SECTOR3)//if arm encoder is between sectors 2 and 3, apply neccesary hold power for this region
  //    {
  //      motorSet(ARM_MOTOR,-13);
  //      sector = 2;
  //    }
  //    if (encoderGet(ArmEncoder) >= SECTOR3 && encoderGet(ArmEncoder) <= SECTOR4)//if arm encoder is between sectors 3 and 4, apply neccesary hold power for this region
  //    {
  //      motorSet(ARM_MOTOR,-15);
  //      sector = 3;
  //    }
  //    if (encoderGet(ArmEncoder) >= SECTOR4 && encoderGet(ArmEncoder) <= SECTOR5)//if arm encoder is between sectors 4 and 5, apply neccesary hold power for this region
  //    {
  //      motorSet(ARM_MOTOR,-20);
  //      sector = 4;
  //    }
  //    if (encoderGet(ArmEncoder) >= SECTOR5 && encoderGet(ArmEncoder) <= SECTOR6)//if arm encoder is between sectors 5 and 6, apply neccesary hold power for this region
  //    {
  //      motorSet(ARM_MOTOR,15);
  //      sector = 5;
  //    }
  //    if (encoderGet(ArmEncoder) >= SECTOR6 && encoderGet(ArmEncoder) <= SECTOR7)//if arm encoder is between sectors 6 and 7, apply neccesary hold power for this region
  //    {
  //      motorSet(ARM_MOTOR,-15);
  //      sector = 6;
  //    }
  //
  //    if (encoderGet(ArmEncoder) >= SECTOR7)//if arm encoder greater than max value for hold position, release hold power
  //    {
  //      motorSet(ARM_MOTOR,0);
  //      sector = 7;
  //    }


  #ifdef ARM_POSITION_DEBUG
  char b[16];
  sprintf(b,"%d",encoderGet(ArmEncoder));
  lcdSetText(uart2,1,b);
  #endif

  #ifdef ARM_SECTOR_DEBUG
  char b[16];
  sprintf(b,"%d",sector);
  lcdSetText(uart2,1,b);
  #endif
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
  #ifdef DRIVE_ENCODER_POSITION_DEBUG
  char buffer[16];
  sprintf(buffer,"%d",encoderGet(LeftDriveEncoder));
  lcdSetText(uart2,1,buffer);
  sprintf(buffer,"%d",encoderGet(RightDriveEncoder));
  lcdSetText(uart2, 2,buffer);
  #endif

#ifdef DRIVE_POWER_DEBUG
char buffer[16];
sprintf(buffer,"%d",LeftDriveEncoder.velocity());//-gw calculates actual power motors are running at
lcdSetText(uart2,1,buffer);
sprintf(buffer,"%d",RightDriveEncoder.velocity());//-gw calculates actual power motors are running at
lcdSetText(uart2, 2,buffer);
#endif
}


void operatorControl() {
  while (1) {

    delay(20);
    driveControl();
    mobileGoalControl();
    armControl();
    liftControl();
    intakeControl();

    delay(20);


    // If any LCD button is pressed from operatorControl, display Robot status.
    // This is useful since operatorControl is run if not in autonomous mode.
    while (lcdReadButtons(uart2))
    {
      displayRobotStatus();
      delay(200);
    }
  }
}
