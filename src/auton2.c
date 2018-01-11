#include <API.H>
#include "robot.h"
#define DIST 36
void auton2()
{
  motorLeftDriveSet(100);
  motorRightDriveSet(-100);
  while(encoderGet(LeftDriveEncoder) <= encoderInchesToCounts(7.85))
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
