#include <API.H>
#include "robot.h"
#define DIST 60
#define DIST2 -52
#define OK_TO_BRAKE 10
extern int speed;
static int mp = 50;
void auton2()
{

  motorSet(CLAW_MOTOR,-100);//pull cone in
  delay(250);
  motorSet(CLAW_MOTOR,-10);//hold cone
  motorSet(LIFT_MOTOR,100);//lift up
  while( encoderGet(LiftEncoder) < 17)
  {

  }
  motorSet(LIFT_MOTOR,0);
  motorSet(MOBILE_GOAL_MOTOR,-100);//deploy mobile goal
  motorLeftDriveSet(50);//drive forward
  motorRightDriveSet(50);//drive forward
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-400) )
  {
      static int offset = 0;
      if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 15  )
      {
        offset += 10;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 10  )
      {
        offset += 5;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 5  )
      {
        offset += 2;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -5  )
      {
        offset -= 2;
      }
      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -10  )

      {
        offset -= 5;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -15  )
      {
        offset -= 10;
      }


      else if ( (encoderGet(LeftDriveEncoder) >= -5) && (encoderGet(LeftDriveEncoder) <= 5) )
      {
        offset = 0;
      }

      if ( (offset > 500))
      {
        offset = 500;
      }
      else if (offset < -500)
      {
        offset = -500;
      }

    //motorLeftDriveSet(mp+offset);
    motorRightDriveSet(mp-offset/50);

  }

  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-375) )
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
  motorLeftDriveSet(0);//stop
  motorRightDriveSet(0);//stop
  motorSet(MOBILE_GOAL_MOTOR,100);
  while(analogRead(MOBILE_GOAL_POT) > 10)
  {

  }
  motorSet(MOBILE_GOAL_MOTOR,0);//stop pulling in
  motorSet(ARM_MOTOR,-25);
  while (encoderGet(ArmEncoder) < 64){}
  motorSet(ARM_MOTOR,0);
  delay(100);
  motorSet(LIFT_MOTOR,-50);//lower lift
  while( encoderGet(LiftEncoder) > 7)
  {

  }

  motorSet(CLAW_MOTOR,60);//drop cone
  delay(100);
  motorSet(LIFT_MOTOR,50);//lift up again
  while( encoderGet(LiftEncoder) > 17)
  {

  }
  delay(100);
motorSet(CLAW_MOTOR,0);//stop releasing cone
motorSet(LIFT_MOTOR,0);//stop lifting
delay(100);
motorLeftDriveSet(-100);//drive backwards
motorRightDriveSet(-100);//drive backwards
while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(29) )  )
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving
delay(250);
encoderReset(LeftDriveEncoder);//reset encoder
delay(100);
motorLeftDriveSet(-50);//turn left
motorRightDriveSet(50);//turn left
while(encoderGet(LeftDriveEncoder) >= -250)
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving
delay(100);
motorLeftDriveSet(-50);//drive backwards toward stationary goal
motorRightDriveSet(-50);
mp = -50;
while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(DIST2)+400) )
{
    static int offset = 0;
    if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 15  )
    {
      offset += 10;
    }

    else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 10  )
    {
      offset += 5;
    }

    else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 5  )
    {
      offset += 2;
    }

    else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -5  )
    {
      offset -= 2;
    }
    else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -10  )

    {
      offset -= 5;
    }

    else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -15  )
    {
      offset -= 10;
    }


    else if ( (encoderGet(LeftDriveEncoder) >= -5) && (encoderGet(LeftDriveEncoder) <= 5) )
    {
      offset = 0;
    }

    if ( (offset > 500))
    {
      offset = 500;
    }
    else if (offset < -500)
    {
      offset = -500;
    }

  //motorLeftDriveSet(mp+offset);
  motorRightDriveSet(mp-offset/50);

}

while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(DIST2)+375) )
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
motorLeftDriveSet(0);//stop
motorRightDriveSet(0);//stop
delay(250);
encoderReset(LeftDriveEncoder);//reset encoder
motorLeftDriveSet(-50);//pivot left
motorRightDriveSet(50);//pivot left
while(encoderGet(LeftDriveEncoder) >= encoderInchesToCounts(-21))
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving
delay(250);
encoderReset(LeftDriveEncoder);//reset encoder
delay(100);
motorLeftDriveSet(50);//turn left
motorRightDriveSet(50);//turn left
while(encoderGet(LeftDriveEncoder) <= encoderInchesToCounts(8))
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving
delay(250);
encoderReset(LeftDriveEncoder);//reset encoder
delay(100);
motorLeftDriveSet(-50);//turn left
motorRightDriveSet(-50);//turn left
while(encoderGet(LeftDriveEncoder) >= encoderInchesToCounts(-4))
{

}
motorSet(LIFT_MOTOR,100);//lift up
while( encoderGet(LiftEncoder) < 17)
{

}
motorSet(LIFT_MOTOR,20);
delay(100);
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving

delay(250);
encoderReset(LeftDriveEncoder);//reset encoder
delay(100);

motorLeftDriveSet(100);//turn left
motorRightDriveSet(100);//turn left
while(encoderGet(LeftDriveEncoder) <= encoderInchesToCounts(30))
{

}
motorSet(MOBILE_GOAL_MOTOR,-100);//deploy mobile goal
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving


}
