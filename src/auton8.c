#include <API.H>
#include "robot.h"
#define DIST 72
#define DECEL_DIST DIST/12
#define OK_TO_BRAKE 10
extern int speed;
static int mp = 0;



void auton8()
{
  static int maxspeed = 0;
  mp = 50;
    motorLeftDriveSet(mp);
    motorRightDriveSet(mp);
    while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-400) )
    {
        if (speed > maxspeed)
        {
          maxspeed = speed;
        }

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

    mp = 20;
    motorLeftDriveSet(mp);
    motorRightDriveSet(mp);

    while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)) );
    motorLeftDriveSet(0);
    motorRightDriveSet(0);
}
