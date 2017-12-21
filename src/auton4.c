#include <API.H>
#include "robot.h"
void auton4()
{
motorLeftDriveSet(20);
motorRightDriveSet(20);
while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(72)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(72)))
{

}
motorLeftDriveSet(0);
motorRightDriveSet(0);
}
