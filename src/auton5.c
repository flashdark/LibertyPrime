#include <API.H>
#include "robot.h"

void auton5()
{
//   motorSet(CLAW_MOTOR,-100);
//   delay(250);
//   motorSet(CLAW_MOTOR,0);
//   motorLeftDriveSet(50);
//   motorRightDriveSet(50);
//   while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(16) )  )
//   {
//
//   }
//   motorLeftDriveSet(0);
//   motorRightDriveSet(0);
//   delay(100);
//   motorSet(LIFT_MOTOR,100);
//   while( encoderGet(LiftEncoder) < 37)
//   {
//
//   }
//   motorSet(LIFT_MOTOR,20);
//   delay(300);
  motorSet(ARM_MOTOR,50);
  while (encoderGet(ArmEncoder) < 86){}
  motorSet(ARM_MOTOR,0);
//   delay(100);
//   motorSet(LIFT_MOTOR,-50);
//   while( encoderGet(LiftEncoder) > 27)
//   {
//
//   }
//   motorSet(LIFT_MOTOR,0);
//   motorSet(CLAW_MOTOR,0);
//   delay(100);
//   motorSet(CLAW_MOTOR,60);
//   motorSet(LIFT_MOTOR,75);
//   while( encoderGet(LiftEncoder) < 37)
//   {
//
//   }
//   motorSet(CLAW_MOTOR,0);
//   motorSet(LIFT_MOTOR,0);
//   motorLeftDriveSet(-50);
//   motorRightDriveSet(-50);
//   while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(11)) )
//   {
//
//   }
//   motorLeftDriveSet(0);
//   motorRightDriveSet(0);


}
