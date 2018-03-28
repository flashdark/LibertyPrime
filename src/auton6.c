#include "main.h"
extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int volatile operation;
extern int volatile intpwr;
//sg
void auton6()
{
  char buffer[16];
	sprintf(buffer,"%d",isAutonomous());
	lcdSetText(uart2,2,buffer);

  operation = 1; //intake cone
  intpwr = 100;
  delay(100);
  operation = 3;//hold

  liftdist = 37;//set lift target position
  lmp = 100;//set lift power
  delay(1000);

  driveforward(900,100,1);

//at destination
  delay(1000);
  liftdist = 28;
  lmp = -50; //lower
  delay(1000);

  operation = 2; //release cone
  intpwr = 100;
  //motorSet(CLAW_MOTOR,120);
  //delay(1000);
  liftdist = 30;//lift up
  lmp = 60;
  delay(100);
  liftdist = 31;//lift up
  lmp = 60;
  delay(1000);
  //operation = 0;//clear motors
  driveBackward(50,-75);
  //operation = 0;//disable intake

}
