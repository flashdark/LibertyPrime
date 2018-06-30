#include "robot.h"

void auton1()
{
  int error = 0;
  int kp = 20;
  int leftPower = 50;
  int rightPower = 50;
  int leftEnc, rightEnc;
  int leftDist, rightDist;

  char lcdTextLine1[16], lcdTextLine2[16];

  leftDist = encoderInches2Counts(24);
  rightDist = leftDist;

  if (LCD_DEBUG_LEVEL == LCD_DEBUG_AUTON1) {
    sprintf(lcdTextLine2, "Dist=%4d", leftDist);
    lcdSetText(uart2, 1, "Auton 1");
    lcdSetText(uart2, 2, lcdTextLine2);
    delay(3000);
  }

  motorSet(LIFT_MOTOR,50);
  motorSet(MOGO_MOTOR, MOGO_EGRESS_POWER);

  do {
    leftEnc = encoderGet(leftDriveEncoder);
    rightEnc = encoderGet(rightDriveEncoder);

    if (analogRead(MOGO_POT) > MOGO_DEPLOYED) {
      motorSet(MOGO_POT, 0);
    }
    if (encoderGet(liftEncoder) > 10) {
      motorSet(LIFT_MOTOR,0);
    }

    error = leftEnc - rightEnc;
    rightPower += error/kp;
    rightPower = (abs(rightPower)>127) ? sign(rightPower)*127 : rightPower;
    //rightPower = (rightPower>127) ? 127 : (rightPower<-127) ? -127 : rightPower;

    motorRightDriveSet(0);
    motorLeftDriveSet(0);

    if (LCD_DEBUG_LEVEL == LCD_DEBUG_AUTON1) {
      sprintf(lcdTextLine1, "LE=%4d RE=%4d", leftEnc,rightEnc);
      sprintf(lcdTextLine2, "Lp=%4d RP=%4d", leftPower,rightPower);
      lcdSetText(uart2, 1, lcdTextLine1);
      lcdSetText(uart2, 2, lcdTextLine2);
      delay(1000);
    }
    motorRightDriveSet(rightPower);
    motorLeftDriveSet(leftPower);

    delay(20);
  } while (leftEnc < leftDist && rightEnc < rightDist);

  motorRightDriveSet(0);
  motorLeftDriveSet(0);

  if (LCD_DEBUG_LEVEL == LCD_DEBUG_AUTON1) {
    while (1) {
      leftEnc = encoderGet(leftDriveEncoder);
      rightEnc = encoderGet(rightDriveEncoder);
      sprintf(lcdTextLine1, "LE=%4d RE=%4d", leftEnc,rightEnc);
      sprintf(lcdTextLine2, "Lp=%4d RP=%4d", leftPower,rightPower);
      lcdSetText(uart2, 1, lcdTextLine1);
      lcdSetText(uart2, 2, lcdTextLine2);
      delay(20);
    }
  }

} // auton1

// notes:
// for 12", LE is 165 and RE is 328. RE is correct
