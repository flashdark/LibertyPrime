#include "main.h"
extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int operation; //intake state
extern int volatile intpwr;
extern bool volatile drivedone;
void auton9()
{
  armdist = 3700;
  amp = -127;
  delay(100);
  while(motorGet(ARM_MOTOR) != -10);
}
