#include <API.H>
#include "robot.h"
#define DIST 36
void auton2()
{
  motorLeftDriveSet(10);
  motorRightDriveSet(10);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)) )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
