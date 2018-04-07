#include "main.h"

#define LIFT_HOLD_POWER 20
#define LIFT_HIGH 27
#define ARM_HOLD_POWER -10
#define ARM_DEPLOY_POWER -60
#define ARM_RETRACT_POWER 80
#define STACK_HEIGHT_INITIAL 8
#define STACK_HEIGHT 13
#define INTAKE_PWR 100
#define OPERATION_INTAKECONE 1
#define OPERATION_RELEASECONE 2
#define OPERATION_HOLDPOWER 3
#define OPERATION_DISABLE 0

extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int operation; //intake state
extern int volatile intpwr;
extern bool volatile drivedone;
//sg
void auton8()
{
  lcdClear(uart2);

  //phase 1 drive and deploy goal lift

      //phase 1 drive and deploy goal lift
      operation = 1;//intake cone
      intpwr = 100;
      delay(40);//delay 40 ms
      operation = 3;
      liftdist = 17;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100

      delay(100);
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
      liftdist = 8;//set liftdist to 10 counts
      lmp = -50;//set lift power to -50

      delay(100);
      while(motorGet(LIFT_MOTOR) != 20);

      operation = 2;//release preload cone
      intpwr = 100;
      delay(100);//delay 300 ms
      liftdist = 17;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100

      delay(100);
      while(motorGet(LIFT_MOTOR) != 20);

      armdist = 3700;
      amp = -60;
      delay(100);
      while(motorGet(ARM_MOTOR) != -10);
      operation = 1;//intake cone
      encoderReset(LeftDriveEncoder);
      delay(250);

      driveforward(100,60,3);
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



      operation = 1;//intake cone
      intpwr = 100;
      encoderReset(LeftDriveEncoder);
      delay(250);
      driveforward(100,60,3);
      while(drivedone == false);
      liftdist = 17;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100
      delay(100);
      while(motorGet(LIFT_MOTOR) != 20);
      armdist = 3700;
      amp = -60;
      delay(100);
      while(motorGet(ARM_MOTOR) != -10);
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
      operation = 0;
      delay(100);
      liftdist = 17;//set lift distance to 17 counts
      lmp = 100;//set lift power to 100
      delay(100);
      while(motorGet(LIFT_MOTOR) != 20);
      //drive to scoring zone
      driveBackward(250,-100);
        while(drivedone == false);
      operation = 0;//release cone
      delay(30);//delay 300 ms
      turnCclwise(15);//rotate counter clockwise 15 counts
      encoderReset(LeftDriveEncoder);
      delay(1000);


      lmp = 0;
      delay(30);
      driveBackward(750,-100);//reverse 1300 counts with -80 power
      while(drivedone == false);
      encoderReset(LeftDriveEncoder);
      turnCclwise(600);//turn 500 counts counter clockwise towards scoring zone
      delay(1000);
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
    writemgs(0);
    operation = 0;
    delay(500);

}
