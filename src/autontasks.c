#include "main.h"

#define OK_TO_BRAKE 10
extern int operation;
extern int liftdist;
extern int lmp;
extern int armdist;
extern int amp;
extern int volatile intpwr;

int speed = 0;
int status = 0;
void movelift()
{
  if (lmp < 0)//if we are lowering down
  {
    if (encoderGet(LiftEncoder) >= liftdist)
    {
      motorSet(LIFT_MOTOR,lmp);
      //delay(30);
    }
    else
    {
      motorSet(LIFT_MOTOR,20);
    }

  }
  else if (lmp > 0)//if we are lifting up
     {
       if (encoderGet(LiftEncoder) <= liftdist)
       {
         motorSet(LIFT_MOTOR,lmp);
         //delay(30);
       }

       else
       {
         motorSet(LIFT_MOTOR,20);
       }
    }
}
void movearm()
{
if (encoderGet(ArmEncoder) <= armdist)
{
  motorSet(ARM_MOTOR,amp);
  delay(30);
}
else
{
  motorSet(ARM_MOTOR,0);
}

}

void decelerate(int counts)//decelerate for accuracy
{
  int mp = 0;
  while( (encoderGet(LeftDriveEncoder) < counts-375) )
  {
  //speed =
    if (speed > OK_TO_BRAKE)
    {
    //char buf[17];
      mp = -2 * (speed / 4.5);//calculate braking
    }
    motorLeftDriveSet(mp);//apply braking
    motorRightDriveSet(mp);//apply braking
  }


  mp = 20;
  motorLeftDriveSet(mp);//crawl forward
  motorRightDriveSet(mp);//crawl forward

  while( encoderGet(LeftDriveEncoder) < counts ){delay(20);}//crawl to destination
  motorLeftDriveSet(0);//clear motors
  motorRightDriveSet(0);//clear motors
}

void decelerateBack(int counts)//logic is flipped for going opposite way
{
  int mp = 0;
  while( (encoderGet(LeftDriveEncoder) > -counts+375) )
  {
  //speed =
    if (speed < -OK_TO_BRAKE)
    {
    //char buf[17];
      mp = 2 * (speed / 4.5);
    }
    motorLeftDriveSet(mp);//apply braking
    motorRightDriveSet(mp);//apply braking
  }

  mp = -20;
  motorLeftDriveSet(mp);//crawl forward
  motorRightDriveSet(mp);//crawl forward

  while( encoderGet(LeftDriveEncoder) > -counts ){delay(20);}//crawl to destination
  motorLeftDriveSet(0);//clear motors
  motorRightDriveSet(0);//clear motors
}


void getSpeed()//get speed the robot is traveling at
{
  static int lastcounts = 0;
  int a = encoderGet(LeftDriveEncoder);
  speed = encoderGet(LeftDriveEncoder) - lastcounts;
  lastcounts = a;
}


void autoMobileGoal()
{
  status = readmgs();
  switch(status)
  {
    case 0://stop
            motorSet(MOBILE_GOAL_MOTOR,0);
            break;
    case 1://deploy
            motorSet(MOBILE_GOAL_MOTOR,-127);//deploy goal
            if(analogRead(MOBILE_GOAL_POT) < 1515){}//check if deployed
            else//if deployed turn power off and do nothing
            {
                motorSet(MOBILE_GOAL_MOTOR,-70);//hold power
                writemgs(3);
            }
            break;
    case 2://retract
            lcdSetBacklight(uart2,true);
            if(analogRead(MOBILE_GOAL_POT) > 15) {motorSet(MOBILE_GOAL_MOTOR,127); }//retract mobile goal
            else//when finished
            {
              lcdSetBacklight(uart2,false);
              motorSet(MOBILE_GOAL_MOTOR,0);//zero motors
              writemgs(3);
            }
            break;
    case 3://done
            break;
    default:
            writemgs(0);
            break;


  }
}

void intake()
{
  switch(operation)
  {
    case 0:
          motorSet(CLAW_MOTOR,0);//off motors
          break;
    case 1:
          motorSet(CLAW_MOTOR,-intpwr);//intake cone
          break;
    case 2:
          motorSet(CLAW_MOTOR,intpwr);//release cone
          break;
    case 3:
          motorSet(CLAW_MOTOR,-20);//hold
          break;
  }
}
