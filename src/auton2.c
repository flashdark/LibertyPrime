#include <API.H>
#include "robot.h"
#define DIST 36
void auton2()
{

  motorSet(CLAW_MOTOR,-100);//pull cone in
  delay(250);
  motorSet(CLAW_MOTOR,-10);//hold cone
  motorSet(LIFT_MOTOR,100);//lift up
  while( encoderGet(LiftEncoder) < 17)
  {

  }
  motorSet(LIFT_MOTOR,0);
  motorSet(MOBILE_GOAL_MOTOR,-100);//deploy mobile goal
  motorLeftDriveSet(50);//drive forward
  motorRightDriveSet(50);//drive forward
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(51) )  )
  {

  }
  motorLeftDriveSet(0);//stop
  motorRightDriveSet(0);//stop
  motorSet(MOBILE_GOAL_MOTOR,100);
  while(analogRead(MOBILE_GOAL_POT) > 10)
  {

  }
  motorSet(MOBILE_GOAL_MOTOR,0);//stop pulling in
  motorSet(ARM_MOTOR,-25);
  while (encoderGet(ArmEncoder) < 64){}
  motorSet(ARM_MOTOR,0);
  delay(100);
  motorSet(LIFT_MOTOR,-50);//lower lift
  while( encoderGet(LiftEncoder) > 7)
  {

  }

  motorSet(CLAW_MOTOR,60);//drop cone
  delay(100);
  motorSet(LIFT_MOTOR,50);//lift up again
  while( encoderGet(LiftEncoder) > 17)
  {

  }
  delay(100);
motorSet(CLAW_MOTOR,0);//stop releasing cone
motorSet(LIFT_MOTOR,0);//stop lifting
delay(100);
motorLeftDriveSet(-100);//drive backwards
motorRightDriveSet(-100);//drive backwards
while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(28) )  )
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving
delay(250);
encoderReset(LeftDriveEncoder);//reset encoder
delay(100);
motorLeftDriveSet(-50);//turn left
motorRightDriveSet(50);//turn left
while(encoderGet(LeftDriveEncoder) >= encoderInchesToCounts(-15))
{

}
motorLeftDriveSet(0);//stop driving
motorRightDriveSet(0);//stop driving
delay(100);
// motorLeftDriveSet(-50);
// motorRightDriveSet(-50);
// while(encoderGet(LeftDriveEncoder) >= encoderInchesToCounts(-36))
// {
//
// }
// motorLeftDriveSet(0);
// motorRightDriveSet(0);

// encoderReset(LeftDriveEncoder);
// motorLeftDriveSet(-50);
// motorRightDriveSet(50);
//
// while(encoderGet(LeftDriveEncoder) <= encoderInchesToCounts(-18))
// {
//
// }
// motorLeftDriveSet(0);
// motorRightDriveSet(0);
// delay(100);
// encoderReset(LeftDriveEncoder);
// motorLeftDriveSet(-50);
// motorRightDriveSet(50);
//
// while(encoderGet(LeftDriveEncoder) <= encoderInchesToCounts(-18))
// {
//
// }
// motorLeftDriveSet(0);
// motorRightDriveSet(0);


  //motorSet(MOBILE_GOAL_MOTOR,-100);
  //encoderReset(LeftDriveEncoder);
  // motorLeftDriveSet(-50);
  // motorRightDriveSet(-50);
  // while( (encoderGet(LeftDriveEncoder) > encoderInchesToCounts(-7) )  )
  // {
  //
  // }
  // motorLeftDriveSet(0);
  // motorRightDriveSet(0);
}
