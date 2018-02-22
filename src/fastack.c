#include "main.h"
#include "robot.h"

//constants
//should move to robot.h
#define ARM_STOWED 0
#define ARM_STACK 28 // encoder value to stack a cone
#define ARM_PICKUP 140 //encoder value to pick up a cone
#define ARM_PRESTACK 50 //encoder value to hold at when rasing lift

#define JOY_SLAVE 2


// hight of lift at number of cones stacked
int stackHeight[15] = {0,10,18,26,34, 42,50,58,66,74, 82,90,98,106,114};

int holdAtHeight[15] = {0,0,0,0,0, 20,20,20,20,20, 40,40,40,40,40};

int coneCount = 0;//track number of cones stacked

//once user has cone in intake fastack controsls the lift and arm to automaticly
//stack the cone and move back to intake the next
void fastack(/* arguments */) {
  /*
test joystick imput for fast stack
move lift up basted on stackHeight and coneCount
move arm to stack possition
lower lift a little and drop cone
raise lift
move arm to deploied position
move lift down
incrament cone count
   */


  while (1) {
    if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_DOWN)) {
      coneCount = 0;
    }
    if (joystickGetDigital(JOY_SLAVE , BTN7_LEFT_THUMB, JOY_DOWN)) {
      coneCount--;
    }

    //test joystick imput for fast stack
    if (joystickGetDigital(JOY_SLAVE , BTN7_LEFT_THUMB, JOY_UP)) {

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
        if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somthings wrong get out of while
        delay(25);
      }
      if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somthings wrong get out of while
      motorSet(LIFT_MOTOR,holdAtHeight[coneCount]);

      // move arm to stack possition
      motorSet(ARM_MOTOR, 80);
      while (encoderGet(ArmEncoder) < ARM_STACK) {
        delay(10);
      }
      motorSet(ARM_MOTOR, 0);
      if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somthings wrong get out of while

      // lower lift a little and drop cone
      motorSet(LIFT_MOTOR, -30);
      delay(10);
      motorSet(CLAW_MOTOR, -100);
      motorSet(LIFT_MOTOR, 0);
      delay(30);
      if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somethings wrong get out of while

      // raise lift
      // move arm to deploied position
      motorSet(LIFT_MOTOR, 50);
      delay(30);
      motorSet(LIFT_MOTOR, 80);
      delay(30);
      if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somethings wrong get out of while
      motorSet(LIFT_MOTOR,holdAtHeight[coneCount]);
      motorSet(ARM_MOTOR,-80);
      while (encoderGet(ArmEncoder) < ARM_PRESTACK) {
        delay(10);
      }
      motorSet(CLAW_MOTOR, 0);
      if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somethings wrong get out of while

      // move lift down
      motorSet(LIFT_MOTOR, -60);
      if (joystickGetDigital(JOY_SLAVE , BTN8_RIGHT_THUMB, JOY_UP)) {break;} // somethings wrong get out of while
      delay(50);
      motorSet(LIFT_MOTOR, 0);
      motorSet(ARM_MOTOR, 0);

      // incrament cone count
      coneCount++;
    } // End of fast stack if
    delay(50);
  }
}
