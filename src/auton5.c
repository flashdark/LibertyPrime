#include <API.H>
#include "robot.h"

#define DIST 36
#define SCALER .8
#define POWER_STEP_1 .2
#define POWER_STEP_2 .15
void auton5()
{
  motorLeftDriveSet(50);
  motorRightDriveSet(50);
  while( (encoderGet(LeftDriveEncoder) > -encoderInchesToCounts(DIST*SCALER)) && (encoderGet(RightDriveEncoder) > -encoderInchesToCounts(DIST*SCALER)) )
  {

  }
  motorLeftDriveSet(50*POWER_STEP_1);
  motorRightDriveSet(50*POWER_STEP_1);
  while( (encoderGet(LeftDriveEncoder) > -encoderInchesToCounts(DIST*.1)) && (encoderGet(RightDriveEncoder) > -encoderInchesToCounts(DIST*.1)) )
  {

  }
  motorLeftDriveSet(50*POWER_STEP_2);
  motorRightDriveSet(50*POWER_STEP_2);
  while( (encoderGet(LeftDriveEncoder) > -encoderInchesToCounts(DIST)) && (encoderGet(RightDriveEncoder) > -encoderInchesToCounts(DIST)) )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
