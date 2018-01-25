#include <API.H>
#include "robot.h"
//////////////////////////
//Stationary goal auton//
////////////////////////
void auton5()
{
  motorSet(CLAW_MOTOR,-100);//pull in cone
  delay(250);
  motorSet(CLAW_MOTOR,-10);//apply hold power
  motorLeftDriveSet(50);//drive forward at half power
  motorRightDriveSet(50);//drive forward at half power
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(15.5) )  )//drive to stationary goal
  {

  }
  motorLeftDriveSet(0);//stop driving
  motorRightDriveSet(0);//stop driving
  delay(100);
  motorSet(LIFT_MOTOR,100);//start lifting
  while( encoderGet(LiftEncoder) < 37)//lift up to stationary goal
  {

  }
  motorSet(LIFT_MOTOR,20);//apply hold power to stabilize lift
  delay(300);
  motorSet(ARM_MOTOR,-25);//start deploying arm
  while (encoderGet(ArmEncoder) < 86){}//deploy arm
  motorSet(ARM_MOTOR,0);//stop deploying arm
  delay(100);
  motorSet(LIFT_MOTOR,-50);//lower cone onto stationary goal
  while( encoderGet(LiftEncoder) > 27)
  {

  }
  motorSet(LIFT_MOTOR,0);//stop moving lif down
  motorSet(CLAW_MOTOR,0);//release intake power
  delay(100);
  motorSet(CLAW_MOTOR,60);//drop cone
  motorSet(LIFT_MOTOR,75);//lift up to finish releasing the cone
  while( encoderGet(LiftEncoder) < 37)
  {

  }
  motorSet(LIFT_MOTOR,0);//stop lifting up
  motorLeftDriveSet(-50);//back away from goal
  motorRightDriveSet(-50);
  motorSet(CLAW_MOTOR,0);//stop trying to release cone
  while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(11)) )
  {

  }
  motorLeftDriveSet(0);//stop driving
  motorRightDriveSet(0);


}
