#include "main.h"
//5 point red
extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int operation; //intake state
extern int status;

void auton3()
{

    //phase 1 drive and deploy goal lift
    operation = 1;//intake cone
    delay(40);//delay 40 ms

    lmp = 100;//set lift power to 100
    liftdist = 17;//set lift distance to 17 counts
    operation = 0;
    delay(500);//delay 1/2 second
    writemgs(1);//deploy mobile goal
    delay(300);//delay 300 ms
    driveforward(1550,100,1);//1400,120
    delay(1000);

    //phase 2 stack cone
    encoderReset(LeftDriveEncoder);
    writemgs(2);//retract mobile goal
    while (status != 0);//wait for moible goal routine to complete
    delay(500);
    amp = -100;//set arm power to -100
    armdist = 12;//set arm distance
    delay(250);

    lmp = -50;//set lift power to -50
    liftdist = 10;//set liftdist to 10 counts
    delay(500);//delay 300 ms

    operation = 2;//release cone
    delay(500);//delay 300 ms

    turnClockwise(15);//rotate counter clockwise 15 counts
    encoderReset(LeftDriveEncoder);

    driveBackward(1400,-80);//reverse 1300 counts with -80 power
    encoderReset(LeftDriveEncoder);

    turnClockwise(550);//turn 500 counts counter clockwise
    encoderReset(LeftDriveEncoder);

    lmp = 100;//set lift power to 100
    liftdist = 17;//set lift distance to 17 counts
    delay(250);//delay 250 ms

    writemgs(1);//deploy mobile goal
    delay(500);

    encoderReset(LeftDriveEncoder);
    driveBackward(600,-100);
    //turnClockwise(700);

    //turnCclwise(700);
    //driveforward(1700,120);
}
