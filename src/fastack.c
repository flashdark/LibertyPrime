#include "main.h"

int stackHeight[15] = {0,10,18,26,34, 42,50,58,66,74, 82,90,98,106,114};
int holdAtHeight[15] = {0,0,0,0,0, 20,20,20,20,20, 40,40,40,40,40};
int coneCount = 0;//track number of cones stacked


 /*
this function is ment to be run as a task by taskCreate
and is ment to automaticly stack cones on a mobike goal when it is
initiated by the partner controler
this code was writen by Dean Pesavento
STEPS:
1 test joystick imput for fast stack
2 move lift up basted on stackHeight and coneCount
3 move arm to stack possition
4 lower lift a little and drop cone
5 raise lift
6 move arm to deploied position
7 move lift down
8 incrament cone count
  */

 void fastack(void * parameter) {//fast stack

char fsStr1[15];

  while (1) {
    if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_DOWN)) {
      coneCount = 0;
    }
    if (joystickGetDigital(JOY_SLAVE , BTN7_LEFT_THUMB, JOY_DOWN)) {
      coneCount--;
    }

    //test joystick imput for fast stack
    if (joystickGetDigital(JOY_SLAVE , BTN7_LEFT_THUMB, JOY_UP)) {

      sprintf(fsStr1, "FS1 L:%d", encoderGet(LiftEncoder));
      lcdSetText(uart2, 2, fsStr1);
      delay(2000);
      // move lift up basted on stackHeight and coneCount
      // move arm to prestack position to not hit cone stack
      motorSet(LIFT_MOTOR, 100);
      motorSet(ARM_MOTOR, 127);
      while ((encoderGet(LiftEncoder) < stackHeight[coneCount]) | (encoderGet(ArmEncoder) < ARM_PRESTACK)) {
        if (encoderGet(LiftEncoder) >= stackHeight[coneCount])  {
          motorSet(LIFT_MOTOR,holdAtHeight[coneCount]);
        }
        if (encoderGet(ArmEncoder) >= ARM_PRESTACK) {
          motorSet(ARM_MOTOR, 25);
        }
        //if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somthings wrong get out of while
        delay(500);
      } //while

      sprintf(fsStr1, "FS2 L:%d", encoderGet(LiftEncoder));
      lcdSetText(uart2, 2, fsStr1);
      delay(2000);

      //if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somthings wrong get out of while
      motorSet(LIFT_MOTOR,holdAtHeight[coneCount]);

      // move arm to stack possition
      motorSet(ARM_MOTOR, 80);
      while (encoderGet(ArmEncoder) < ARM_STACK) {
        delay(20);
      }
      motorSet(ARM_MOTOR, 0);
      //if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somthings wrong get out of while

      sprintf(fsStr1, "FS3 L:%d", encoderGet(LiftEncoder));
      lcdSetText(uart2, 2, fsStr1);
      delay(2000);

      // lower lift a little and drop cone
      motorSet(LIFT_MOTOR, -30);
      delay(500);
      motorSet(CLAW_MOTOR, -100);
      motorSet(LIFT_MOTOR, 0);
      delay(500);
    //  if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somethings wrong get out of while

      // raise lift
      // move arm to deploied position
      motorSet(LIFT_MOTOR, 50);
      delay(500);
      motorSet(LIFT_MOTOR, 80);
      delay(500);
      //if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somethings wrong get out of while
      motorSet(LIFT_MOTOR,holdAtHeight[coneCount]);
      motorSet(ARM_MOTOR,-80);
      while (encoderGet(ArmEncoder) < ARM_PRESTACK) {
        delay(20);
      }
      motorSet(CLAW_MOTOR, 0);

      sprintf(fsStr1, "FS L:%d", encoderGet(LiftEncoder));
      lcdSetText(uart2, 2, fsStr1);
      delay(2000);

      //if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somethings wrong get out of while

      // move lift down
      motorSet(LIFT_MOTOR, -60);
      //if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somethings wrong get out of while
      delay(500);
      motorSet(LIFT_MOTOR, 0);
      motorSet(ARM_MOTOR, 0);

      // incrament cone count
      coneCount++;
    } // End of fast stack if
    delay(500);
  }
}
