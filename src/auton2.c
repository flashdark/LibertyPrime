#include "main.h"
extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int operation; //intake state
//5 point red
void auton2()
{
      char buf[16];
      //phase 1 drive and deploy goal lift

          //phase 1 drive and deploy goal lift
          operation = 1;//intake cone
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
          delay(1000);//delay 600 ms
          //phase 2 stack cone
          encoderReset(LeftDriveEncoder);
          writemgs(2);//retract mobile goal
          delay(1000);//delay 600 ms

          amp = -100;//set arm power to -100
          armdist = 18;//set arm distance
          delay(500);

          lmp = -50;//set lift power to -50
          liftdist = 8;//set liftdist to 10 counts
          delay(500);//delay 300 ms

          operation = 2;//release cone
          delay(300);//delay 300 ms

          turnCclwise(15);//rotate counter clockwise 15 counts
          encoderReset(LeftDriveEncoder);

          driveBackward(1300,-100);//reverse 1300 counts with -80 power
          encoderReset(LeftDriveEncoder);

          turnCclwise(600);//turn 500 counts counter clockwise towards scoring zone
          delay(1000);
          encoderReset(LeftDriveEncoder);
          //driveforward(800,40,1);//drive forward 200 counts with 50 power

          lmp = 100;//set lift power to 100
          liftdist = 17;//set lift distance to 17 counts
          delay(250);//delay 250 ms

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
  //turnCclwise(700);
  //driveforward(1700,120);
}
