#include "main.h"
extern int powerLeft;
extern int powerRight;
extern bool armup;
extern bool armdown;
extern bool liftup;
extern bool liftdown;
extern bool incone;
extern bool relcone;
extern bool shiftpressed;
extern int ts;
extern bool rgoal;
extern bool dgoal;


void MobileGoalControl()
{
  if (dgoal)
  {
    motorSet(MOBILE_GOAL_MOTOR,-127);//deploy mobile goal at max power
  }
  else if(rgoal)
{
  motorSet(MOBILE_GOAL_MOTOR,127);//retract mobile goal at max power
}
else
{
  motorSet(MOBILE_GOAL_MOTOR,0);//stop mobile goal
}
}

void DriverControl()
{
  char buffer[16];
  sprintf(buffer,"%d",encoderGet(LeftDriveEncoder));
  //lcdSetText(uart2, 1,buffer);

    if (abs(powerLeft) > STICK_THRESHOLD && powerLeft < 60) { //min deadzone
      //motorLeftDriveSet(powerLeft/3);
      motorLeftDriveSet(powerLeft);//set power of motors to joystick value
    } else if (abs(powerLeft) > STICK_THRESHOLD && powerLeft > 60) {//max deadzone
      motorLeftDriveSet(powerLeft);//set power of motors to joystick value
    }
      else
      {
        motorLeftDriveSet(0);//turn off motor
      }

    // delay(20);
    if (abs(powerRight) > STICK_THRESHOLD && powerRight < 60) { //min deadzone
      //motorRightDriveSet(powerRight/3);
      motorRightDriveSet(powerRight);//set power of motors to joystick value
    } else if (abs(powerRight) > STICK_THRESHOLD && powerRight > 60) { //max deadzone
      motorRightDriveSet(powerRight);//set power of motors to joystick value
    }
      else
      {
        motorRightDriveSet(0); //turn off motor
      }

}

void ArmControl()
{

  char buffer[16];
  sprintf(buffer,"%d",armup);
  //lcdSetText(uart2, 1,buffer);
  if(armup != 0)
  {
    motorSet(ARM_MOTOR,120);//up
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
    motorSet(CLAW_MOTOR,-65); //pull cone in
    close = true;
     }

     else
     {
       if (close == true)
       {
          motorSet(CLAW_MOTOR,-10); //intake hold power
       }
       else
       {
       motorSet(CLAW_MOTOR,0); //stop intake motor
     }
   }
 }
