#include "main.h"

extern int ts;
extern int powerLeft;
extern int powerRight;
extern bool armup;
extern bool armdown;
extern bool liftup;
extern bool liftdown;
extern bool incone;
extern bool relcone;

void motorLeftDriveSet(int power)
{
  motorSet(LEFT_DRIVE_FRONT_MOTOR, LEFT_DRIVE_REVERSED * power);
  motorSet(LEFT_DRIVE_REAR_MOTOR, LEFT_DRIVE_REVERSED * power);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void motorRightDriveSet(int power)
{
  motorSet(RIGHT_DRIVE_FRONT_MOTOR, RIGHT_DRIVE_REVERSED * power);
  motorSet(RIGHT_DRIVE_REAR_MOTOR, RIGHT_DRIVE_REVERSED * power);
}


void readButtons()
{
  if(joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_LEFT)){ts = 2;} // check Button 8L is pressed
  if(joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_RIGHT)){ts = 1;}// check Button 8R is pressed
  if(joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_UP)){ts = 3;}
  powerLeft = joystickGetAnalog(JOY_MASTER, STK3_LEFT_Y);
  powerRight = joystickGetAnalog(JOY_MASTER, STK2_RIGHT_Y);
  armup = joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_UP);
  armdown = joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_DOWN);
  liftup = joystickGetDigital(JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_UP);//check if button 5U was pressed
  liftdown = joystickGetDigital(JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_DOWN);//check if button 5D was pressed
  relcone = joystickGetDigital(JOY_MASTER,BTN7_LEFT_THUMB,JOY_LEFT);
  incone = joystickGetDigital(JOY_MASTER,BTN7_LEFT_THUMB,JOY_RIGHT);
}
