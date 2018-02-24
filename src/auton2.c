#include "main.h"
void auton2()
{
  delay(40);
  writemgs(1);
  driveforward(1300,120);
  encoderReset(LeftDriveEncoder);
  writemgs(2);
  delay(100);
  turnCclwise(15);
  encoderReset(LeftDriveEncoder);
  driveBackward(1000,-40);
  encoderReset(LeftDriveEncoder);
  turnCclwise(380);
  driveforward(300,50);
  //turnClockwise(700);

  //turnCclwise(700);
  //driveforward(1700,120);
}
