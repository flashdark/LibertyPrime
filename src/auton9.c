#include <API.H>
#include "robot.h"
#define DIST 72
#define DECEL_DIST (DIST/12)
void auton9()
{
  int spd =0;
  motorLeftDriveSet(127);
  motorRightDriveSet(127);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-400) )
  {
    //spd =
    // if (spd > OK_TO_BRAKE)
    //           {
    //             *pMp = -10 * (spd / 10);
    //           }
    //           else
    //           {
    //            *pMp = 20;
    //          }
  }
  motorLeftDriveSet(-15);
  motorRightDriveSet(-15);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-300) )
  {

  }
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-250) )
  {

  }
  motorLeftDriveSet(-10);
  motorRightDriveSet(-10);

  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-200) )
  {

  }
  motorLeftDriveSet(-5);
  motorRightDriveSet(-5);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-200) )
  {

  }

  motorLeftDriveSet(25);
  motorRightDriveSet(25);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)-200) )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
