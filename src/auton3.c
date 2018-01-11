#include <API.H>
#include "robot.h"
#define DIST 40
void auton3()
{
  motorLeftDriveSet(50);
  motorRightDriveSet(50);

  while(encoderGet(LeftDriveEncoder) <= encoderInchesToCounts(3))
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
  encoderReset(LeftDriveEncoder);
  delay(2000);
  motorLeftDriveSet(-50);
  motorRightDriveSet(50);

  // while(encoderGet(LeftDriveEncodner) >= encoderInchesToCounts(-7.85))
  // {
  // turning at 100
  // }
  while(encoderGet(LeftDriveEncoder) >= encoderInchesToCounts(-8.25))
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
  encoderReset(LeftDriveEncoder);
  delay(2000);
  motorSet(MOBILE_GOAL_MOTOR,-100);
  while(analogRead(MOBILE_GOAL_POT) <= 1513)
  {

  }
  motorSet(MOBILE_GOAL_MOTOR,0);
  motorLeftDriveSet(100);
  motorRightDriveSet(100);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)) )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
  encoderReset(LeftDriveEncoder);
  delay(100);
  // motorLeftDriveSet(50);
  // motorRightDriveSet(-50);
  //
  // while(encoderGet(LeftDriveEncoder) <= encoderInchesToCounts(15.7))
  // {
  //
  // }
  // motorLeftDriveSet(0);
  // motorRightDriveSet(0);
  // encoderReset(LeftDriveEncoder);
  // delay(1000);
  // motorLeftDriveSet(100);
  // motorRightDriveSet(100);
  // while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST)) )
  // {
  //
  // }
}
