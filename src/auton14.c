#include "main.h"
extern bool volatile turndone;
void auton14()
{
  turnCclwise(3600);
  while(!turndone);
  encoderReset(LeftDriveEncoder);
  turnClockwise(3600);
  while(!turndone);
}
