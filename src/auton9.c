#include <API.H>
#include "robot.h"
#define DIST 72
#define DECEL_DIST (DIST/12)
void auton9()
{
  motorLeftDriveSet(50);
  motorRightDriveSet(50);
  while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(DIST*(1-(1/DECEL_DIST)))) && (encoderGet(RightDriveEncoder) > encoderInchesToCounts(DIST*(1-(1/DECEL_DIST)))) )
  {

  }
  motorLeftDriveSet(50*.2);
  motorRightDriveSet(50*.2);
  while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(DIST)) && (encoderGet(RightDriveEncoder) > encoderInchesToCounts(DIST)) )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
