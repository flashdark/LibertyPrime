#include "main.h"
int dmp = 0;
int liftdist = 0;
int lmp = 0;
int armdist = 0;
int amp = 0;
int dist = 0;

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
//driveforward(1800,120);
delay(1000);
encoderReset(LeftDriveEncoder);


//turnClockwise(700)
//turnCclwise(560);


}
