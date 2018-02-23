#include "main.h"

extern int dmp;

  void turnClockwise(int counts)

{
  motorLeftDriveSet(50);
  motorRightDriveSet(-50);
  while(encoderGet(LeftDriveEncoder) <= counts){}
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}

void turnCclwise(int counts)
{
  motorLeftDriveSet(-50);
  motorRightDriveSet(50);
  while(encoderGet(LeftDriveEncoder) >= -counts){}
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}

void driveforward(int counts, int power)
{
  AccelerateForward(power); //accelerateion to prevent torque steer
  while (encoderGet(LeftDriveEncoder) < counts-400)
  {
    drivestraight();//adjustment code
  }
  decelerate(counts);//slow down to prevent overshooting
}

void driveBackward(int counts, int power)
{
    AccelerateBackward(power);
    while(encoderGet(LeftDriveEncoder) > -counts + 400)
    {
      drivestraightBack(counts);
    }
    decelerateBack(counts);
  }


void AccelerateForward(int power)
{
  int i;
  for (i = 0; i < 1; i++)
  {
    motorLeftDriveSet(10);
    motorRightDriveSet(10);
    delay(20);
    if (power <= 10) {break;}

    motorRightDriveSet(20);
    motorLeftDriveSet(20);
    delay(20);
    if (power <= 20) {break;}

    motorLeftDriveSet(30);
    motorRightDriveSet(30);
    delay(20);
    if (power <= 30) {break;}

    motorRightDriveSet(40);
    motorLeftDriveSet(40);
    delay(20);
    if (power <= 40) {break;}

    motorLeftDriveSet(50);
    motorRightDriveSet(50);
    delay(20);
    if (power <= 50) {break;}

    motorLeftDriveSet(60);
    motorRightDriveSet(60);
    delay(20);
    if (power <= 60) {break;}

    motorLeftDriveSet(70);
    motorRightDriveSet(70);
    delay(20);
    if (power <= 70) {break;}

    motorLeftDriveSet(80);
    motorRightDriveSet(80);
    delay(20);
    if (power <= 80) {break;}

    motorLeftDriveSet(90);
    motorRightDriveSet(90);
    delay(20);
    if (power <= 90) {break;}

    motorLeftDriveSet(100);
    motorRightDriveSet(100);
    delay(20);
    if (power <= 100) {break;}

    motorLeftDriveSet(110);
    motorRightDriveSet(110);
    delay(20);
    if (power <= 110) {break;}

    motorLeftDriveSet(120);
    motorRightDriveSet(120);
    delay(20);
  }
}

void AccelerateBackward(int power)
{
  int i;
  for (i = 0; i < 1; i++)
  {
    motorLeftDriveSet(-10);
    motorRightDriveSet(-10);
    delay(20);
    if (power >= -10) {break;}

    motorRightDriveSet(-20);
    motorLeftDriveSet(-20);
    delay(20);
    if (power >= -20) {break;}

    motorLeftDriveSet(-30);
    motorRightDriveSet(-30);
    delay(20);
    if (power >= -30) {break;}

    motorRightDriveSet(-40);
    motorLeftDriveSet(-40);
    delay(20);
    if (power >= -40) {break;}

    motorLeftDriveSet(-50);
    motorRightDriveSet(-50);
    delay(20);
    if (power >= -50) {break;}

    motorLeftDriveSet(-60);
    motorRightDriveSet(-60);
    delay(20);
    if (power >= -60) {break;}

    motorLeftDriveSet(-70);
    motorRightDriveSet(-70);
    delay(20);
    if (power >= -70) {break;}

    motorLeftDriveSet(-80);
    motorRightDriveSet(-80);
    delay(20);
    if (power >= -80) {break;}

    motorLeftDriveSet(-90);
    motorRightDriveSet(-90);
    delay(20);
    if (power >= -90) {break;}

    motorLeftDriveSet(-100);
    motorRightDriveSet(-100);
    delay(20);
    if (power >= -100) {break;}

    motorLeftDriveSet(-110);
    motorRightDriveSet(-110);
    delay(20);
    if (power >= -110) {break;}

    motorLeftDriveSet(-120);
    motorRightDriveSet(-120);
    delay(20);
  }
}

void deploymobilegoal()
{
  motorSet(MOBILE_GOAL_MOTOR,-127);
  if(analogRead(MOBILE_GOAL_POT) < 1515){

  }
  else
  {
  motorSet(MOBILE_GOAL_MOTOR,0);
  }
}

void retractmobilegoal()
{
  if(analogRead(MOBILE_GOAL_POT) > 9) {motorSet(MOBILE_GOAL_MOTOR,127); }
  else
  {
  motorSet(MOBILE_GOAL_MOTOR,0);
  }
}

void drivestraight(int counts)
{
  if( (encoderGet(LeftDriveEncoder) < counts-400) )//stop at mobile goal
  {
    //go straight algorithm
      static int offset = 0;
      if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 15  )
      {
        offset += 10;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 10  )
      {
        offset += 5;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 5  )
      {
        offset += 2;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -5  )
      {
        offset -= 2;
      }
      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -10  )

      {
        offset -= 5;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -15  )
      {
        offset -= 10;
      }


      else if ( (encoderGet(LeftDriveEncoder) >= -5) && (encoderGet(LeftDriveEncoder) <= 5) )
      {
        offset = 0;
      }

      if ( (offset > 500))
      {
        offset = 500;
      }
      else if (offset < -500)
      {
        offset = -500;
      }
    motorRightDriveSet(dmp-offset/50);

  }
}

  void drivestraightBack(void)
{
  int leftencval = -encoderGet(LeftDriveEncoder);//making values positive for math
  int rightencval = -encoderGet(RightDriveEncoder);//making values positive for math
    //go straight algorithm
      static int offset = 0;
      if ( (rightencval - leftencval) >= 15  )//if off a lot, compenate accordingly
      {
        offset += 10;
      }

      else if ( (rightencval - leftencval) >= 10  )//if off more, compenate accordingly
      {
        offset += 5;
      }

      else if ( (rightencval - leftencval) >= 5  )//if off a little, compenate accordingly
      {
        offset += 2;
      }

       else if ( (rightencval - leftencval) <= -15  )
      {
        offset -= 10;
      }

      else if ( (rightencval - leftencval) <= -10  )
      {
        offset -= 5;
      }

      else if ( (rightencval - leftencval) <= -5  )
      {
        offset -= 2;
      }


      if ( (leftencval == rightencval) ) //reset offset
      {
        offset = 0;
      }

      if ( (offset > 500))
      {
        offset = 500;
      }
      else if (offset < -500)
      {
        offset = -500;
      }
    motorRightDriveSet(dmp-offset/50);


}
