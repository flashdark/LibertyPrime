#include <API.H>
#include "robot.h"
#define DIST 36
void auton4()
{
  motorLeftDriveSet(30);
  motorRightDriveSet(30);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)) )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
