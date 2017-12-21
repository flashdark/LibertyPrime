#include <API.H>
#include "robot.h"
#define SCALER .7
#define DIST1 43
void auton3()
{
  char buffer[16];
  // motorLeftDriveSet(100);
  // motorRightDriveSet(100);
  // while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1*SCALER)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1*SCALER)))
  // {
  //
  // }
  //
  // motorLeftDriveSet(-10);
  // motorRightDriveSet(-10);
  //
  // while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER+.09))) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER-.1))))
  // {
  //
  // }
  // motorLeftDriveSet(50);
  // motorRightDriveSet(50);
  // while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER+.150))) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER-.2))))
  // {
  //
  // }
  // motorLeftDriveSet(25);
  // motorRightDriveSet(25);
  // while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER+.2))) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1*(SCALER-.3))))
  // {
  //
  // }
  // motorLeftDriveSet(10);
  // motorRightDriveSet(10);
  // while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(DIST1)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(DIST1)))
  // {
  //
  // }
  //
  //
  motorLeftDriveSet(20);
  motorRightDriveSet(20);
  sprintf(buffer,"%d",encoderInchesToCounts(72));
  lcdSetText(uart2,1,buffer);
  while ((encoderGet(LeftDriveEncoder) < encoderInchesToCounts(72)) && (encoderGet(RightDriveEncoder) < encoderInchesToCounts(72)))
  {
    sprintf(buffer,"%d",encoderGet(LeftDriveEncoder));
    lcdSetText(uart2,2,buffer);
  }
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}
