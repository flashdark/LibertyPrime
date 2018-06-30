#include "robot.h"
// this auton will raise the lift so the mogo can deploy
void auton2() {
  // int error = 0;
  // int kp = 20;
  int leftPower = 50;
  int rightPower = 50;
  int leftEnc, rightEnc;
  int leftDist, rightDist;

  char lcdTextLine1[16], lcdTextLine2[16];
//set drive forward distance
  leftDist = encoderInches2Counts(52);
  rightDist = leftDist;

  if (LCD_DEBUG_LEVEL == LCD_DEBUG_AUTON1) {
    sprintf(lcdTextLine2, "Dist=%4d", leftDist);
    lcdSetText(uart2, 1, "Auton 2");
    lcdSetText(uart2, 2, lcdTextLine2);
    delay(3000);
  }
  //raise lift allitle
  motorSet(LIFT_MOTOR, 50);
  motorSet(MOGO_MOTOR, MOGO_EGRESS_POWER);

  motorRightDriveSet(rightPower);
  motorLeftDriveSet(leftPower);

  do {
    delay(20);
    //get the encoder value for drive motors
    leftEnc = encoderGet(leftDriveEncoder);
    rightEnc = encoderGet(rightDriveEncoder);
//deploy mogo
    if (analogRead(MOGO_POT) > MOGO_DEPLOYED) {
      motorSet(MOGO_MOTOR, 10);
    }
    if (encoderGet(liftEncoder) > 10) {
      motorSet(LIFT_MOTOR, 0);
    }

  } while (leftEnc < leftDist && rightEnc < rightDist);

  motorRightDriveSet(0);
  motorLeftDriveSet(0);
//stow mogo
delay(20);
  motorSet(MOGO_MOTOR, 100);
  while (analogRead(MOGO_POT) > MOGO_STOWED);
//drive back
  leftDist = encoderInches2Counts(26);
  rightDist = leftDist;

  motorRightDriveSet(-1 * rightPower);
  motorLeftDriveSet(-1 * leftPower);

  do {
    delay(20);
    leftEnc = encoderGet(leftDriveEncoder);
    rightEnc = encoderGet(rightDriveEncoder);

  } while (leftEnc > leftDist && rightEnc > rightDist);
//reset encoder
  encoderReset(leftDriveEncoder);
  encoderReset(rightDriveEncoder);
//rotation 180 deg
  leftDist = encoderInches2Counts(26);
  rightDist = encoderInches2Counts(-26);

  motorRightDriveSet(-1 * rightPower);
  motorLeftDriveSet(+1 * leftPower);

  do {
    delay(20);
    //get the encoder values
    leftEnc = encoderGet(leftDriveEncoder);
    rightEnc = encoderGet(rightDriveEncoder);
//left encoder is less then left distance and
//right encoder is fre
  } while (leftEnc < leftDist && rightEnc > rightDist);
//set motors to 0
  motorRightDriveSet(0);
  motorLeftDriveSet(0);

  //reset encoder
    encoderReset(leftDriveEncoder);
    encoderReset(rightDriveEncoder);
 //drive forwards alittle
 leftDist = encoderInches2Counts(0);
 rightDist = leftDist;

 motorRightDriveSet(1 * rightPower);
 motorLeftDriveSet(1 * leftPower);

 do {
   delay(20);
   leftEnc = encoderGet(leftDriveEncoder);
   rightEnc = encoderGet(rightDriveEncoder);

 } while (leftEnc < leftDist && rightEnc < rightDist);
 //set motors to 0
   motorRightDriveSet(0);
   motorLeftDriveSet(0);
//reset encoder
 encoderReset(leftDriveEncoder);
 encoderReset(rightDriveEncoder);
 //place mogo
 motorSet(MOGO_MOTOR,MOGO_EGRESS_POWER);
while (analogRead(MOGO_POT) < MOGO_PLACE_POINT) {};

//drive back
  leftDist = encoderInches2Counts(5);
  rightDist = leftDist;

  motorRightDriveSet(-1 * rightPower);
  motorLeftDriveSet(-1 * leftPower);

  do {
    delay(20);
    leftEnc = encoderGet(leftDriveEncoder);
    rightEnc = encoderGet(rightDriveEncoder);

  } while (leftEnc > leftDist && rightEnc > rightDist);
//reset encoder
  encoderReset(leftDriveEncoder);
  encoderReset(rightDriveEncoder);

  if (LCD_DEBUG_LEVEL == LCD_DEBUG_AUTON1) {
    while (1) {
      leftEnc = encoderGet(leftDriveEncoder);
      rightEnc = encoderGet(rightDriveEncoder);
      sprintf(lcdTextLine1, "LE=%4d RE=%4d", leftEnc, rightEnc);
      sprintf(lcdTextLine2, "Lp=%4d RP=%4d", leftPower, rightPower);
      lcdSetText(uart2, 1, lcdTextLine1);
      lcdSetText(uart2, 2, lcdTextLine2);
      delay(20);
    }
  }

} // auton1

// notes:
// for 12", LE is 165 and RE is 328. RE is correct
