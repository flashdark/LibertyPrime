#include "main.h"
extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int operation;
//sg
void auton6()
{
  char buffer[16];
	sprintf(buffer,"%d",isAutonomous());
	lcdSetText(uart2,2,buffer);

  operation = 1;
  delay(1000);

  lmp = 100;
  liftdist = 37;
  delay(1000);
driveforward(800,100,1);
delay(1000);
lmp = -50;
liftdist = 27;
delay(1000);
operation = 2;
delay(300);
operation = 0;
delay(1000);

lmp = 100;
liftdist = 30;
delay(1000);
driveBackward(50,-75);

}
