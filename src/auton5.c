#include <API.H>
#include "robot.h"
void auton5()
{
  motorLeftDriveSet(25);
  motorRightDriveSet(25);
  while ((encoderGet(LeftDriveEncoder) > -encoderInchesToCounts(6)) && (encoderGet(RightDriveEncoder) > -encoderInchesToCounts(6)))
  {

  }
  motorLeftDriveSet(-10);
  motorRightDriveSet(-10);
  delay(25);
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
