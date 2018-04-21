#include "main.h"
extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int operation; //intake state
extern int volatile intpwr;
extern bool volatile drivedone;
extern bool volatile turndone;
//10 point blue
void auton12()
{
  char buf[16];
  //phase 1 drive and deploy goal lift

      //phase 1 drive and deploy goal lift
      operation = 1;//intake cone
      intpwr = 100;
      delay(40);//delay 40 ms

      lmp = 100;//set lift power to 100
      liftdist = 17;//set lift distance to 17 counts
      delay(500);
      operation = 0;//release cone hold power
      operation = 1;//enable cone hold power
      delay(250);//delay 1/2 second
      writemgs(1);//deploy mobile goal
      delay(300);//delay 300 ms
      driveforward(1550,100,1);//1400,120
      while(!drivedone);
      //phase 2 stack cone
      encoderReset(LeftDriveEncoder);
      writemgs(2);//retract mobile goal
      while(readmgs() != 3);

      lmp = -50;//set lift power to -50
      liftdist = 8;//set liftdist to 10 counts
      delay(500);//delay 300 m

      operation = 2;//release cone
      intpwr = 100;
      delay(300);//delay 300 ms

      turnClockwise(15);//rotate counter clockwise 15 counts
      encoderReset(LeftDriveEncoder);

      lmp = 100;//set lift power to 100
      liftdist = 17;//set lift distance to 17 counts
      driveBackward(1300,-100);//reverse 1300 counts with -80 power
      encoderReset(LeftDriveEncoder);

      turnCclwise(800);//turn 500 counts counter clockwise towards scoring zone
      while(!turndone);
      encoderReset(LeftDriveEncoder);
      //driveforward(800,40,1);//drive forward 200 counts with 50 power

      writemgs(1);//deploy mobile goal
      delay(700);

      encoderReset(LeftDriveEncoder);
      driveBackward(500,-100);//reverse away from  mobile goal
      //turnClockwise(700);
    motorLeftDriveSet(0);
    motorRightDriveSet(0);
    amp = 0;
    lmp = 0;
    operation = 0;
    delay(500);
}
