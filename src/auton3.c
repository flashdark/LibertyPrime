#include <API.H>
#include "robot.h"
#define SCALER .7
#define DIST1 43
void auton3()
{
  motorLeftDriveSet(100);
  motorRightDriveSet(100);
  while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1*SCALER)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1*SCALER)))
  {

  }

  motorLeftDriveSet(75);
  motorRightDriveSet(75);

  while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER+.09))) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER-.1))))
  {

  }
  motorLeftDriveSet(50);
  motorRightDriveSet(50);
  while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER+.150))) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER-.2))))
  {

  }
  motorLeftDriveSet(25);
  motorRightDriveSet(25);
  while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER+.2))) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER-.3))))
  {

  }
  motorLeftDriveSet(10);
  motorRightDriveSet(10);
  while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1)))
  {

  }



}
