#include <API.H>
#include "robot.h"

void auton1()
{
  /* Insert claw hold power*/
motorLeftDriveSet(100);
motorRightDriveSet(100);
while(encoderGet(LeftDriveEncoder) <= 12)
{

}
motorLeftDriveSet(-10);// -gw acts similar to engine braking
motorRightDriveSet(-10);
motorLeftDriveSet(0);
motorRightDriveSet(0);
motorSet(ARM_MOTOR,-50);
/* Insert Positional code here*/
motorSet(ARM_MOTOR,-15);
motorSet(LIFT_MOTOR,127);
/* Inster Positional code for lift Here*/
//open claw

}
