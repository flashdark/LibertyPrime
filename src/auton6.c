#include <API.H>
#include "robot.h"
void auton6()
{
motorLeftDriveSet(100);
motorRightDriveSet(100);
motorSet(MOBILE_GOAL_MOTOR,-20);
while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(48)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(48)))
{

}
motorLeftDriveSet(-10);
motorRightDriveSet(-10);
delay(20);
motorLeftDriveSet(0);
motorRightDriveSet(0);
motorLeftDriveSet(50);
motorRightDriveSet(-50);
delay(50);
motorLeftDriveSet(0);
motorRightDriveSet(0);

}
