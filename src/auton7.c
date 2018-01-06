#include <API.H>
#include "robot.h"
#define DIST 36
#define DECEL_DIST DIST/12
#define OK_TO_BRAKE 10
extern int speed;
static int mp = 0;

void auton7()
{
  static int maxspeed = 0;

    motorLeftDriveSet(100);
    motorRightDriveSet(100);
    while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-400) )
    {
        if (speed > maxspeed)
        {
          maxspeed = speed;

        }
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

  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)) );
  motorLeftDriveSet(0);
  motorRightDriveSet(0);

}
