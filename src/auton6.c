#include <API.H>
#include "robot.h"
void auton6()
{
  char buf[17];
sprintf(buf,"In A6");
//lcdSetText(uart2,1,buf);
motorLeftDriveSet(50);
motorRightDriveSet(50);
while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(36)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(36)))
{
//sprintf(buf,"In While Loop");
//lcdSetText(uart2,2,buf);

}
motorLeftDriveSet(-10);
motorRightDriveSet(-10);
motorLeftDriveSet(0);
motorRightDriveSet(0);
}
