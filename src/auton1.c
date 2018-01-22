#include <API.H>
#include "robot.h"

void auton1()
{
  motorSet(LIFT_MOTOR,100);
  while( encoderGet(LiftEncoder) < 17)
  {

  }
  motorSet(LIFT_MOTOR,20);
  motorSet(MOBILE_GOAL_MOTOR,-50);
  motorLeftDriveSet(50);
  motorRightDriveSet(50);
  while( (encoderGet(LeftDriveEncoder) < encoderInchesToCounts(48) )  )
  {

  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
  motorSet(MOBILE_GOAL_MOTOR,50);
  while(analogRead(MOBILE_GOAL_POT) > 10)
  {

  }
  motorSet(MOBILE_GOAL_MOTOR,0);


}
