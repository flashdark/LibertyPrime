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
  char buf[16];

  lcdClear(uart2);

  //phase 1 drive and deploy goal lift

      //phase 1 drive and deploy goal lift
      operation = 1;//intake cone
      intpwr = 100;
      delay(40);//delay 40 ms
      operation = 3;
      lmp = 100;//set lift power to 100
      liftdist = 17;//set lift distance to 17 counts
      while(motorGet(LIFT_MOTOR) != 20);

      writemgs(1);//deploy mobile goal
      delay(300);//delay 300 ms
      driveforward(1550,100,1);//1400,120
      while(drivedone == false);


      encoderReset(LeftDriveEncoder);
      writemgs(2);//retract mobile goal
      delay(100);//delay 600 ms

      // sprintf(buf,"Pot: %d Wait",analogRead(MOBILE_GOAL_POT));
      // lcdSetText(uart2,2,buf);
      // delay(20);

      while(readmgs() != 3);

      // sprintf(buf,"Pot: %d Done",analogRead(MOBILE_GOAL_POT));
      // lcdSetText(uart2,2,buf);
      // delay(20);

      //phase 2 stack cone
      lmp = -50;//set lift power to -50
      liftdist = 8;//set liftdist to 10 counts
      delay(30);
      while(motorGet(LIFT_MOTOR) != 20);

      operation = 2;//release cone
      intpwr = 100;
      delay(30);//delay 300 ms
      liftdist = 17;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100
      delay(100);
      while(motorGet(LIFT_MOTOR) != 20);
      encoderReset(LeftDriveEncoder);
      turnClockwise(20);
      delay(250);
      armdist = 3700;
      amp = -60;
      delay(100);
      while(motorGet(ARM_MOTOR) != -10);
      operation = 1;//intake cone
      encoderReset(LeftDriveEncoder);
      delay(250);

      driveforward(75,60,3);
      while(drivedone == false);
      liftdist = 2;
      lmp = -50;
      delay(100);
      while(motorGet(LIFT_MOTOR) != 20);
      operation = 3;
      delay(100);
      liftdist = 17;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100
      delay(100);
      while(motorGet(LIFT_MOTOR) != 20);
      armdist = 1200;
      amp = 80;
      delay(100);
      while(motorGet(ARM_MOTOR) != -10);
      liftdist = 13;//set lift distance to 17 counts
      lmp = -50;//set lift power to 100
      delay(100);
      while(motorGet(LIFT_MOTOR) != 20);
      operation = 2;
      intpwr = 100;
      delay(100);
      encoderReset(LeftDriveEncoder);
      delay(250);
      //turnClockwise(15);
      operation = 0;//release cone
      encoderReset(LeftDriveEncoder);
      delay(250);
      //drive to scoring zone
      driveBackward(250,-100);
      while(drivedone == false);
      operation = 0;//release cone
      delay(30);//delay 300 ms
      turnCclwise(15);//rotate counter clockwise 15 counts
      encoderReset(LeftDriveEncoder);
      delay(100);
      lmp = 100;//set lift power to 100
      liftdist = 17;//set lift distance to 17 counts
      delay(30);
      while(motorGet(LIFT_MOTOR) != 20);
      lmp = 0;
      delay(30);

      driveBackward(850,-100);//reverse 1300 counts with -80 power
      while(drivedone == false);
      encoderReset(LeftDriveEncoder);
      turnCclwise(200);
      delay(1000);
      encoderReset(LeftDriveEncoder);
      delay(100);
      driveBackward(900,-127);//reverse 1300 counts with -80 power
      while(drivedone == false);
      delay(250);
      encoderReset(LeftDriveEncoder);
      delay(100);
      turnCclwise(350);
      delay(1000);
      driveforward(800,127,1);
      while(drivedone == false);
      writemgs(1);
      while(readmgs() != 3);

      driveBackward(500,-80);
      //turnClockwise(700);
    motorLeftDriveSet(0);
    motorRightDriveSet(0);
    amp = 0;
    lmp = 0;
    writemgs(0);
    operation = 0;
    delay(500);
}
