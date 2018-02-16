#include <API.H>
#include "robot.h"
#define DIST 65
#define DIST2 -52
#define OK_TO_BRAKE 10
extern int speed;
static int mp = 50;

void auton3()
{
  //setup to grab mobile goal

  motorSet(CLAW_MOTOR,-100);//pull cone in
  delay(200);
  motorSet(CLAW_MOTOR,-10);//hold cone
  motorSet(LIFT_MOTOR,100);//raise lift
  while( encoderGet(LiftEncoder) < 17) //lift until enough space for mobile goal
  {

  }
  motorSet(LIFT_MOTOR,20);
  motorSet(MOBILE_GOAL_MOTOR,-100);//deploy mobile goal lift
  delay(20);




  //drive forward towards mobile goal
AccelerateToX(50);

  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-400) )//stop at mobile goal
  {
    //go straight algorithm
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
    //braking algorithm
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
  motorSet(MOBILE_GOAL_MOTOR,100); //pull in mobile goal
  while(analogRead(MOBILE_GOAL_POT) > 10)//drive until mobile goal retracted
  {

  }
  motorSet(MOBILE_GOAL_MOTOR,0);//stop pulling in
  delay(20);
  motorSet(LIFT_MOTOR,0);//release power



  //stack cone
  motorSet(ARM_MOTOR,-40);//move arm to position cone for release
  while (encoderGet(ArmEncoder) < 64){}
  motorSet(ARM_MOTOR,0);//stop moving arm
  delay(100);
  motorSet(LIFT_MOTOR,-50);//lower lift to place cone
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



//drive backwards toward scoring zone
motorLeftDriveSet(-100);//drive backwards
motorRightDriveSet(-100);//drive backwards
while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(29) )  )
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving

delay(200);
encoderReset(LeftDriveEncoder);//reset encoder preparing for turn
delay(100);

//turn around to face scoring zone
motorLeftDriveSet(-50);
motorRightDriveSet(50);
while(encoderGet(LeftDriveEncoder) >= 10)
{

}

motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving

delay(200);
encoderReset(LeftDriveEncoder);//reset encoder preparing for turn
delay(20);


motorLeftDriveSet(50);
motorRightDriveSet(-50);
while(encoderGet(LeftDriveEncoder) <= 550) //larger value = more turn
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving

delay(200);
encoderReset(LeftDriveEncoder);//reset encoder to ensure consistent alignment

//drive to scoring zone

motorLeftDriveSet(60);
motorRightDriveSet(60);
while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(20) )  )
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving

delay(200);
encoderReset(LeftDriveEncoder);//reset encoder before turn
delay(20);

//turn to score mobile goal
motorLeftDriveSet(50);//turn left
motorRightDriveSet(-50);//turn left
while(encoderGet(LeftDriveEncoder) <= 350)
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving
delay(20);

//drive to scoring zone
motorLeftDriveSet(50);
motorRightDriveSet(50);
while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(23) )  )
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving
motorSet(LIFT_MOTOR,100);//lift up
while( encoderGet(LiftEncoder) < 17)
{

}
motorSet(LIFT_MOTOR,20);
motorSet(MOBILE_GOAL_MOTOR,-100);//deploy mobile goal
delay(1000);
//stop driving
motorLeftDriveSet(-100);//stop driving
motorRightDriveSet(-100);//stop driving

while( (encoderGet(LeftDriveEncoder) > -10 )  )
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving

}
