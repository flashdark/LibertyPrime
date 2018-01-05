#include <API.H>
#include "robot.h"

void auton7()
{
  motorLeftDriveSet(50);
  motorRightDriveSet(50);
  while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(72)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(72)))
  {

  }
  motorLeftDriveSet(-10);
  motorRightDriveSet(-10);
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
