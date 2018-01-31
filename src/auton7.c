#include <API.H>
#include "robot.h"
void auton7()
{
motorLeftDriveSet(10);
motorRightDriveSet(10);
delay(20);
motorRightDriveSet(20);
motorLeftDriveSet(20);
delay(20);
motorLeftDriveSet(30);
motorRightDriveSet(30);
delay(20);
motorRightDriveSet(40);
motorLeftDriveSet(40);
delay(20);
motorLeftDriveSet(50);
motorRightDriveSet(50);
delay(1000);
motorLeftDriveSet(0);
motorRightDriveSet(0);

}
