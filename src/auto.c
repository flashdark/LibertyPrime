#include "main.h"
int dmp = 0;
int liftdist = 0;
int lmp = 0;
int armdist = 0;
int amp = 0;
int dist = 0;
extern int ts;

void autonomous() {
ts = 1;
//driveforward(1800,120);
delay(1000);
encoderReset(LeftDriveEncoder);
ts = 2;


//turnClockwise(700)
//turnCclwise(560);


}
