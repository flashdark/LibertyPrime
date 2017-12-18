#include <API.H>
#include "robot.h"

void auton3()
{
  motorLeftDriveSet(100);
  motorRightDriveSet(100);
  delay(300);
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
