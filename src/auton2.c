#include "main.h"
extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int operation;

void auton2()
{
  operation = 1;
  delay(40);
  lmp = 100;
  liftdist = 17;
  delay(500);
  writemgs(1);
  driveforward(1400,120);
  encoderReset(LeftDriveEncoder);
  writemgs(2);
  delay(600);
  amp = -100;
  armdist = 10;
  delay(500);
  lmp = -50;
  liftdist = 10;
  delay(300);
  operation = 2;
  delay(300);
  turnCclwise(15);
  encoderReset(LeftDriveEncoder);
  driveBackward(1300,-80);
  encoderReset(LeftDriveEncoder);
  turnCclwise(500);
  encoderReset(LeftDriveEncoder);
  driveforward(200,50);
  lmp = 100;
  liftdist = 17;
  delay(250);
  writemgs(1);
  delay(500);
  encoderReset(LeftDriveEncoder);
  driveBackward(200,-100);
  //turnClockwise(700);

  //turnCclwise(700);
  //driveforward(1700,120);
}
