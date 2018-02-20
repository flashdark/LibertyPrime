#include "main.h"
  char buffer[16];
  void turnClockwise(int counts)

{

}

void turnCclwise(int counts)
{
  motorLeftDriveSet(-50);
  motorRightDriveSet(50);
  while(encoderGet(LeftDriveEncoder) > counts){}
  motorLeftDriveSet(0);
  motorRightDriveSet(0);
}

void driveforward(int counts, int power)
{

  sprintf(buffer,"%d  A",encoderGet(LeftDriveEncoder));
  lcdSetText(uart2, 1,buffer);
  AccelerateToX(power);
  sprintf(buffer,"%d  D",encoderGet(LeftDriveEncoder));
  lcdSetText(uart2, 1,buffer);
  while (encoderGet(LeftDriveEncoder) < counts-400)
  {
  drivestraight();
  }
  decelerate(counts);
}

void driveBackward(int counts, int power)
{

}

void AccelerateToX(int power)
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
