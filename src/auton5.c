#include <API.H>
#include "robot.h"
void auton5()
{
  motorLeftDriveSet(50);
  motorRightDriveSet(50);
  while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(46)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(46)))
  {

  }
  motorLeftDriveSet(-10);
  motorRightDriveSet(-10);
  delay(25);
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
