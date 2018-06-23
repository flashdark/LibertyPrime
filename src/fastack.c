#include "main.h"
#include "robot.h"

//
// this function is ment to be run as a task by taskCreate
// and is ment to automaticly stack cones on a mobike goal when it is
// initiated by the partner controler
// this code was writen by Dean Pesavento
// STEPS:
// 1 test joystick imput for fast stack
// 2 move lift up basted on stackHeight and coneCount
// 3 move arm to stack possition
// 4 lower lift a little and drop cone
// 5 raise lift
// 6 move arm to deploied position
// 7 move lift down
// 8 incrament cone count
//

 void fastack(void * parameter) {
  char lcdTextLine1[16], lcdTextLine2[16];
  int stackHeight[15] = {0,7,14,21,28, 35,42,49,56,63, 70,77,84,91,98};
  int holdPowerAtHeight[15] = {0,0,0,0,0, 20,20,20,20,20, 40,40,40,40,40};
  int coneCount = 0; //track number of cones stacked

  if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
    lcdSetText(uart2, 1, "  Fastack Task");
    lcdSetText(uart2, 2, "    Started");
  }

  while (1) {
    if (joystickGetDigital(BTN_FASTACK_RESET)) {
      coneCount = 0;

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine2, "     %2d", coneCount);
        lcdSetText(uart2, 1, "FS Reset");
        lcdSetText(uart2, 2, lcdTextLine2);
        delay(LCD_DEBUG_DELAY);
      }
    }

    if (joystickGetDigital(BTN_FASTACK_SUBTRACT)) {
      coneCount--;

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine2, "     %2d", coneCount);
        lcdSetText(uart2, 1, "FS DEC");
        lcdSetText(uart2, 2, lcdTextLine2);
        delay(LCD_DEBUG_DELAY);
      }
    }

    //test joystick imput for fast stack
    if (joystickGetDigital(BTN_FASTACK_CONE)) {

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine2, "LE=%4d AP=%4d", encoderGet(liftEncoder),analogRead(ARM_POT));
        lcdSetText(uart2, 1, "FS INC 2a");
        lcdSetText(uart2, 2, lcdTextLine2);
        delay(500);
      }
      // move lift up basted on stackHeight and coneCount
      // move arm to prestack position to not hit cone stack
      motorSet(LIFT_MOTOR, 60);
      motorSet(ARM_MOTOR, 127);
      while ((encoderGet(liftEncoder) < stackHeight[coneCount]) |
             (analogRead(ARM_POT) > ARM_PRESTACK)) {

        if (encoderGet(liftEncoder) >= stackHeight[coneCount])  {
          //motorSet(LIFT_MOTOR,holdPowerAtHeight[coneCount]);
          motorSet(LIFT_MOTOR,0);
        }
        if (analogRead(ARM_POT) <= ARM_PRESTACK) {
          motorSet(ARM_MOTOR, ARM_HOLD_POWER);
        }
        delay(10);
        if (joystickGetDigital(BTN_LIFT_UP)) {break;} // somthings wrong abort this loop

        if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
          sprintf(lcdTextLine2, "LE=%4d AP=%4d", encoderGet(liftEncoder),analogRead(ARM_POT));
          lcdSetText(uart2, 1, "FS INC 2b");
          lcdSetText(uart2, 2, lcdTextLine2);
          delay(500);
        }
      }
      if (joystickGetDigital(BTN_LIFT_UP)) {continue;} // somthings wrong restart while(1)

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine2, "LE=%4d AP=%4d", encoderGet(liftEncoder),analogRead(ARM_POT));
        lcdSetText(uart2, 1, "FS INC 3");
        lcdSetText(uart2, 2, lcdTextLine2);
        delay(500);
      }
      // move arm to stack possition
      motorSet(ARM_MOTOR, 120);
      while (analogRead(ARM_POT) > ARM_STACK) {
        delay(10);
        if (joystickGetDigital(BTN_LIFT_UP)) {break;} // somthings wrong abort this loop
      }
      motorSet(ARM_MOTOR, 0);
      if (joystickGetDigital(BTN_LIFT_UP)) {continue;} // somthings wrong restart while(1)

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine2, "LE=%4d AP=%4d", encoderGet(liftEncoder),analogRead(ARM_POT));
        lcdSetText(uart2, 1, "FS INC 4");
        lcdSetText(uart2, 2, lcdTextLine2);
        delay(500);
      }
      // lower lift a little and drop cone
      motorSet(LIFT_MOTOR, -80);
      delay(100);
      motorSet(INTAKE_MOTOR, 100);
      motorSet(LIFT_MOTOR, 0);
      delay(100);
      if (joystickGetDigital(BTN_LIFT_UP)) {continue;} // somethings wrong restart while(1)

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine2, "LE=%4d AP=%4d", encoderGet(liftEncoder),analogRead(ARM_POT));
        lcdSetText(uart2, 1, "FS INC 5");
        lcdSetText(uart2, 2, lcdTextLine2);
        delay(500);
      }
      // raise lift
      // move arm to deployed position
      motorSet(LIFT_MOTOR, 50);
      delay(50);
      motorSet(LIFT_MOTOR, 80);
      delay(100);
      if (joystickGetDigital(BTN_LIFT_UP)) {continue;} // somethings wrong restart while(1)
      motorSet(LIFT_MOTOR,holdPowerAtHeight[coneCount]);
      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine2, "LE=%4d AP=%4d", encoderGet(liftEncoder),analogRead(ARM_POT));
        lcdSetText(uart2, 1, "FS INC 6");
        lcdSetText(uart2, 2, lcdTextLine2);
        delay(500);
      }
      motorSet(ARM_MOTOR,-80);
      while (analogRead(ARM_POT) > ARM_DECEL_POINT) {
        delay(10);
        if (joystickGetDigital(BTN_LIFT_UP)) {break;} // somthings wrong abort this loop
      }
      motorSet(INTAKE_MOTOR, 0);
      if (joystickGetDigital(BTN_LIFT_UP)) {continue;} // somethings wrong restart while(1)

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine2, "LE=%4d AP=%4d", encoderGet(liftEncoder),analogRead(ARM_POT));
        lcdSetText(uart2, 1, "FS INC 7");
        lcdSetText(uart2, 2, lcdTextLine2);
        delay(500);
      }
      // move lift down
      motorSet(LIFT_MOTOR, -80);
      if (joystickGetDigital(BTN_LIFT_UP)) {continue;} // somethings wrong restart while(1)
      delay(100);
      motorSet(LIFT_MOTOR, 0);
      motorSet(ARM_MOTOR, 0);

      // incrament cone count
      coneCount++;

      if (LCD_DEBUG_LEVEL == LCD_DEBUG_FASTACK) {
        sprintf(lcdTextLine1, "FS CONES = %2d", coneCount);
        sprintf(lcdTextLine2, "LE=%4d AP=%4d", encoderGet(liftEncoder),analogRead(ARM_POT));
          lcdSetText(uart2, 1, lcdTextLine1);
          lcdSetText(uart2, 2, lcdTextLine2);
          delay(500);
      }
    } // end if(FASTACK)

    delay(20);
  } // end while(1)
}
