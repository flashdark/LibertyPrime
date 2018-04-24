#include "main.h"
extern int dmp;//drive motor power
extern int liftdist;//how far to lift
extern int lmp; //power to use when lifting
extern int armdist;//dist to move arm
extern int amp;//power to use to move arm
extern int operation; //intake state
extern int volatile intpwr;
extern bool volatile drivedone;
//5 point red
void auton2()
{
      //phase 1 drive and deploy goal lift

          //phase 1 drive and deploy goal lift
          operation = 1;//intake cone
          intpwr = 100;//use 100 power
          delay(40);//delay 40 ms
          operation = 3;
          lmp = 100;//set lift power to 100
          liftdist = 17;//set lift distance to 17 counts
          while(motorGet(LIFT_MOTOR) != 20);//check if lift done

          writemgs(1);//deploy mobile goal
          delay(300);//delay 300 ms
          driveforward(1550,100,1);//1400,120
          while(drivedone == false);//check if drive done


          encoderReset(LeftDriveEncoder);
          writemgs(2);//retract mobile goal
          delay(100);//delay 100 ms

          while(readmgs() != 3);//wait for goal to retract


          //phase 2 stack cone
          lmp = -50;//set lift power to -50
          liftdist = 8;//set liftdist to 10 counts
          delay(30);
          while(motorGet(LIFT_MOTOR) != 20);//check if lift done

          operation = 2;//release cone
          intpwr = 100;
          delay(30);//delay 300 ms

          //drive to scoring zone
          driveBackward(250,-100);
          operation = 0;//release cone
          delay(30);//delay 300 ms
          turnCclwise(15);//rotate counter clockwise 15 counts
          encoderReset(LeftDriveEncoder);
          delay(1000);
          lmp = 100;//set lift power to 100
          liftdist = 17;//set lift distance to 17 counts
          delay(30);
          while(motorGet(LIFT_MOTOR) != 20);//check if lift done
          lmp = 0;
          delay(30);

          driveBackward(750,-100);//reverse 1300 counts with -80 power
          while(drivedone == false);
          encoderReset(LeftDriveEncoder);

          turnCclwise(600);//turn 500 counts counter clockwise towards scoring zone
          delay(750);
          encoderReset(LeftDriveEncoder);
          //driveforward(800,40,1);//drive forward 200 counts with 50 power

          writemgs(1);//deploy mobile goal
          delay(300);

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
  //turnCclwise(700);
  //driveforward(1700,120);
}
