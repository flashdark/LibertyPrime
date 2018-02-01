#include <API.H>
#include "robot.h"
#define DIST 60
#define DIST2 -52
#define OK_TO_BRAKE 10
extern int speed;
static int mp = 50;

void auton4()
{
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


}
