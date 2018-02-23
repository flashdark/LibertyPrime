#include "main.h"
int dmp = 0;
int liftdist = 0;
int lmp = 0;
int armdist = 0;
int amp = 0;
int dist = 0;
int mgs = 0;

extern TaskHandle mgt;
extern TaskHandle dt;
extern TaskHandle at;
extern TaskHandle lt;
extern TaskHandle it;
extern TaskHandle spd;
extern TaskHandle mat;
extern TaskHandle mlt;

int readmgs()
{
  return mgs;
}

void writemgs(int op)
{
  mgs = op;
}



void autonomous() {
initializeLoopTasks();
suspenddrivertasks();
enableautotasks();
delay(40);
writemgs(1);
driveforward(1300,120);
encoderReset(LeftDriveEncoder);
writemgs(2);
delay(100);
turnCclwise(25);
delay(1000);
encoderReset(LeftDriveEncoder);

driveBackward(1350,-40);
//turnClockwise(700);

//turnCclwise(700);
//driveforward(1700,120);
suspendautotasks();
enabledrivertasks();
}
