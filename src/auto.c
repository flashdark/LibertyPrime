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




void autonomous() {
suspenddrivertasks();
enableautotasks();
mgs = 1;
driveforward(1350,120);
encoderReset(LeftDriveEncoder);

mgs = 2;
delay(100);
turnCclwise(50);
//driveBackward(1350,-40);
//turnClockwise(700);

//turnCclwise(700);
//driveforward(1700,120);
suspendalltasks();

}
