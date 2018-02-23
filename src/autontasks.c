#include "main.h"

#define OK_TO_BRAKE 10

extern int dmp;
extern int liftdist;
extern int lmp;
extern int armdist;
extern int amp;
int speed = 0;

void movelift()
{
  if (encoderGet(LiftEncoder) <= liftdist)
  {
  motorSet(LIFT_MOTOR,lmp);
  }

  else
  {
    motorSet(LIFT_MOTOR,0);
  }
}

void movearm()
{
if (encoderGet(ArmEncoder) <= armdist)
{
  motorSet(ARM_MOTOR,amp);
}
else
{
  motorSet(ARM_MOTOR,0);
}
}

void decelerate(int counts)
{
  int mp = 0;
  while( (encoderGet(LeftDriveEncoder) < counts-375) )
  {
  //speed =
    if (speed > OK_TO_BRAKE)
    {
    //char buf[17];
      mp = -2 * (speed / 4.5);
    }
    motorLeftDriveSet(mp);
    motorRightDriveSet(mp);
  }


  mp = 20;
  motorLeftDriveSet(mp);
  motorRightDriveSet(mp);

  while( encoderGet(LeftDriveEncoder) < counts ){delay(20);}
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}

void decelerateBack(int counts)
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
    motorLeftDriveSet(mp);
    motorRightDriveSet(mp);
  }

  mp = -20;
  motorLeftDriveSet(mp);
  motorRightDriveSet(mp);

  while( encoderGet(LeftDriveEncoder) > -counts ){delay(20);}
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}


void getSpeed()
{
  static int lastcounts = 0;
  int a = encoderGet(LeftDriveEncoder);
  speed = encoderGet(LeftDriveEncoder) - lastcounts;
  lastcounts = a;
}


void autoMobileGoal()
{
  digitalWrite(9,HIGH);
  int status = readmgs();
  switch(status)
  {
    case 0:
            break;
    case 1:
            motorSet(MOBILE_GOAL_MOTOR,-127);
            if(analogRead(MOBILE_GOAL_POT) < 1515){}
            else
            {
                motorSet(MOBILE_GOAL_MOTOR,0);
                status=0;
            }
            break;
    case 2:
            if(analogRead(MOBILE_GOAL_POT) > 9) {motorSet(MOBILE_GOAL_MOTOR,127); }
            else
            {
              motorSet(MOBILE_GOAL_MOTOR,0);
             status=0;
            }
            break;

  }
}
