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
      delay(100);//delay 300 ms
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

      //stack 1st cone
      operation = 2;//release cone
      intpwr = 100;
      delay(30);//delay 300 ms

      //position lift for second cone
      liftdist = 15;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100
      delay(30);//100
      while(motorGet(LIFT_MOTOR) != 20);

      //turn ,drive, and prepare to pickup second cone
      encoderReset(LeftDriveEncoder);
      turnClockwise(20);
      while(turndone == false);
      armdist = 3700;
      amp = -60;
      delay(30);//100
      while(motorGet(ARM_MOTOR) != -10);
      operation = 1;//turns on intake
      encoderReset(LeftDriveEncoder);
      //delay(250);

      //drive and stack 2nd cone
      driveforward(50,60,3);
      while(drivedone == false);
      liftdist = 6;//lower to get cone
      lmp = -50;
      delay(30);//100
      while(motorGet(LIFT_MOTOR) != 20);
      operation = 3;//intake hold power
      delay(30);//100
      liftdist = 15;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100
      delay(30);//100
      while(motorGet(LIFT_MOTOR) != 20);

      //stack 2nd cone
      armdist = 1200;
      amp = 80;
      delay(30);//100
      while(motorGet(ARM_MOTOR) != -10);
      liftdist = 13;//set lift distance to 17 counts
      lmp = -50;//set lift power to 100
      delay(30);//100
      while(motorGet(LIFT_MOTOR) != 20);
      operation = 2;
      intpwr = 100;
      delay(30);//100
      encoderReset(LeftDriveEncoder);
      //delay(250);
      //turnClockwise(15);
      operation = 0;//turn off intake

      encoderReset(LeftDriveEncoder);
      //delay(250);
      //drive to scoring zone
      driveBackward(250,-100);
      while(drivedone == false);
      delay(30);
      turnCclwise(15);//rotate counter clockwise 15 counts
      while(turndone == false);
      encoderReset(LeftDriveEncoder);
      delay(30);
      liftdist = 18;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100
      delay(30);

      driveBackward(850,-120);//reverse 1300 counts with -80 power
      while(drivedone == false);
      delay(30);
      encoderReset(LeftDriveEncoder);
      turnCclwise(200);
      while(turndone == false);
      delay(30);
      encoderReset(LeftDriveEncoder);
      delay(30);
      driveBackward(900,-127);//reverse 1300 counts with -80 power
      while(drivedone == false);
      delay(30);
      encoderReset(LeftDriveEncoder);
      delay(30);//100
      turnCclwise(350);
      while(turndone == false);

      motorSet(MOBILE_GOAL_MOTOR,-80);
      delay(25);
      driveforward(800,127,1);
      while(drivedone == false);
      while(analogRead(MOBILE_GOAL_POT) < 750);
      motorSet(MOBILE_GOAL_MOTOR,5);

      driveBackward(500,-120);
      //turnClockwise(700);
    motorLeftDriveSet(0);
    motorRightDriveSet(0);
    amp = 0;
    lmp = 0;
    writemgs(0);
    operation = 0;
    delay(500);
}
