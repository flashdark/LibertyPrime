#include "main.h"

  void turnClockwise(int counts)//turn robot clockwise to specified number of counts

{
  motorLeftDriveSet(50);
  motorRightDriveSet(-50);
  while(encoderGet(LeftDriveEncoder) <= counts){}
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}

void turnCclwise(int counts)//turn robot counter-clockwise to specified number of counts
{
  motorLeftDriveSet(-50);
  motorRightDriveSet(50);
  while(encoderGet(LeftDriveEncoder) >= -counts){}
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}

void driveforward(int counts, int power,int mode)//drive forward to specified counts with specified power
{
  static int preencval = 0;
  static int postencval = 0;
  AccelerateForward(power); //accelerateion to prevent torque steer
  while (encoderGet(LeftDriveEncoder) < counts-400)
  {
    preencval = encoderGet(LeftDriveEncoder);
    drivestraight(power);//adjustment code
    postencval = encoderGet(LeftDriveEncoder);
    if (postencval-preencval == 0){ break;}//check if there is movement, if not something happened so move on
  }
  if (mode == 0)//enable decelerate
  {
    decelerate(counts);//slow down to prevent overshooting
  }
  else//disable decelerate for crash runs
  {
    motorLeftDriveSet(0);//clear motors
    motorRightDriveSet(0);//clear motors
  }
}

void driveBackward(int counts, int power)//drive back to specified counts with specified power
{
    AccelerateBackward(power);
    while(encoderGet(LeftDriveEncoder) > -counts + 400)
    {
      drivestraightBack(power);//driving straight
    }
    decelerateBack(counts);//decelerate
  }


void AccelerateForward(int power)//gradually increase power to avoid sudden jerking or steering movements
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

void AccelerateBackward(int power)//gradually increase power to avoid sudden jerking or steering movements
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

void drivestraight(int dmp)//add or subtract power to stay on course when driving long distances
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
    delay(30);

  }

  void drivestraightBack(int dmp)//add or subtract power to stay on course when driving long distances but with the logic flipped since we are going backwards
{

  int leftencval = -encoderGet(LeftDriveEncoder);//making values positive for math
  int rightencval = -encoderGet(RightDriveEncoder);//making values positive for math
  delay(30);
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

       else if ( (rightencval - leftencval) <= -15  )//if off a lot, compenate accordingly
      {
        offset -= 10;
      }

      else if ( (rightencval - leftencval) <= -10  )//if off more, compenate accordingly
      {
        offset -= 5;
      }

      else if ( (rightencval - leftencval) <= -5  )//if off a little, compenate accordingly
      {
        offset -= 2;
      }


    //  if ( (leftencval == rightencval) ) //reset offset
    //  {
    //    offset = 0;
    //  }

      if ( (offset > 500))
      {
        offset = 500;
      }
      else if (offset < -500)
      {
        offset = -500;
      }
    motorRightDriveSet(dmp-offset/50);//apply offset
    delay(30);

}
