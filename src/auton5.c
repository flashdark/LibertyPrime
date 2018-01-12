#include <API.H>
#include "robot.h"

void auton5()
{
  motorSet(CLAW_MOTOR,-100);
  delay(50);
  motorSet(CLAW_MOTOR,0);
  motorLeftDriveSet(50);
  motorRightDriveSet(50);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(10)) )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
  motorSet(LIFT_MOTOR,100);
  while( encoderGet(LiftEncoder) < 37)
  {

  }
  motorSet(LIFT_MOTOR,0);
  motorSet(ARM_MOTOR,50);
  while (encoderGet(ArmEncoder) < 150);
  motorSet(ARM_MOTOR,0);
  motorSet(LIFT_MOTOR,-50);
  while( encoderGet(LiftEncoder) > 27)
  {

  }
  motorSet(LIFT_MOTOR,0);
  motorSet(CLAW_MOTOR,60);
  delay(100);
  motorSet(CLAW_MOTOR,0);
  motorSet(LIFT_MOTOR,100);
  while( encoderGet(LiftEncoder) < 37)
  {

  }
  motorSet(LIFT_MOTOR,0);
  motorLeftDriveSet(-50);
  motorRightDriveSet(-50);
  while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(11)) )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);


}
