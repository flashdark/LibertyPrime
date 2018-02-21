#include <API.h>
#include "robot.h"
extern int powerLeft;
extern int powerRight;
extern bool armup;
extern bool armdown;
extern bool liftup;
extern bool liftdown;
extern bool incone;
extern bool relcone;
extern int ts;
void MobileGoalControl()
{
switch(ts)
{
  case 0:
        motorSet(MOBILE_GOAL_MOTOR,0);
        break;
  case 1:
          motorSet(MOBILE_GOAL_MOTOR,-127);
          if(analogRead(MOBILE_GOAL_POT) < 1515){

          }
          else{
          motorSet(MOBILE_GOAL_MOTOR,0);
          ts = 0;
        }
          break;
  case 2:

          if(analogRead(MOBILE_GOAL_POT) > 9) {motorSet(MOBILE_GOAL_MOTOR,127); }
          else{
          motorSet(MOBILE_GOAL_MOTOR,0);
          ts = 0;
        }
          break;
  case 3:

        if (analogRead(MOBILE_GOAL_POT) <= 800){motorSet(MOBILE_GOAL_MOTOR,-127);}
        else{
        motorSet(MOBILE_GOAL_MOTOR,5);
        delay(50);
        motorSet(MOBILE_GOAL_MOTOR,10);
          delay(50);
        motorSet(MOBILE_GOAL_MOTOR,15);
        delay(50);
        motorSet(MOBILE_GOAL_MOTOR,25);
          delay(50);
        motorSet(MOBILE_GOAL_MOTOR,30);
        delay(50);
        motorSet(MOBILE_GOAL_MOTOR,0);
        ts = 0;
      }
        break;
case 4:
      motorSet(MOBILE_GOAL_MOTOR,127);
      ts = 0;
      break;
}
}

void DriverControl()
{
  char buffer[16];
  sprintf(buffer,"%d",encoderGet(LeftDriveEncoder));
  lcdSetText(uart2, 1,buffer);

    if (abs(powerLeft) > STICK_THRESHOLD && powerLeft < 60) {
      //motorLeftDriveSet(powerLeft/3);
      motorLeftDriveSet(powerLeft);
    } else if (abs(powerLeft) > STICK_THRESHOLD && powerLeft > 60) {
      motorLeftDriveSet(powerLeft);
    }
      else
      {
        motorLeftDriveSet(0);
      }

    delay(20);
    if (abs(powerRight) > STICK_THRESHOLD && powerRight < 60) {
      //motorRightDriveSet(powerRight/3);
      motorRightDriveSet(powerRight);
    } else if (abs(powerRight) > STICK_THRESHOLD && powerRight > 60) {
      motorRightDriveSet(powerRight);
    }
      else
      {
        motorRightDriveSet(0);
      }

}

void ArmControl()
{

  char buffer[16];
  sprintf(buffer,"%d",armup);
  lcdSetText(uart2, 1,buffer);
  if(armup != 0)
  {
    motorSet(ARM_MOTOR,80);//up
  }

  else if(armdown)
  {
    motorSet(ARM_MOTOR,-60);//down
  }
  else
  {
    motorSet(ARM_MOTOR,0);
  }
}

void LiftControl()
{
  if (liftup)//if lifting up
     {
       motorSet(LIFT_MOTOR,120);//go up
     }
     else if (liftdown)//if moving down
     {
       motorSet(LIFT_MOTOR,-60);//go down
     }

     else
     {
       motorSet(LIFT_MOTOR,0);//otherwise release power to ease strain on motors
     }
}

void IntakeControl() {
static bool close;
   if(relcone) //open claw if button 7L is pressed
   {
     motorSet(CLAW_MOTOR,127);//apply open power
     close = false;
     //holdCounter = 0;//reset close hold power counter
   }
   else if(incone)
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


void TaskManager(TaskHandle th,int operation)
{
  switch(operation)
  {
    case 0:
          taskResume(th);
          break;
    case 1:
          taskSuspend(th);
          break;
    case 2:
          taskDelete(th);
          break;
    default:
            break;
  }
}
