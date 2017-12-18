#include <API.H>
#include "robot.h"

void auton2()
{
  motorLeftDriveSet(100);
  motorRightDriveSet(100);
  delay(300);
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
