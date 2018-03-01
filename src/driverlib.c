#include "main.h"

//state variables
extern int ts;
extern int powerLeft;
extern int powerRight;
extern bool armup;
extern bool armdown;
extern bool liftup;
extern bool liftdown;
extern bool incone;
extern bool relcone;
extern bool dgoal;
extern bool rgoal;
extern bool sgoal;

void motorLeftDriveSet(int power)//chains motors together
{
  motorSet(LEFT_DRIVE_FRONT_MOTOR, LEFT_DRIVE_REVERSED * power);
  motorSet(LEFT_DRIVE_REAR_MOTOR, LEFT_DRIVE_REVERSED * power);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void motorRightDriveSet(int power) //chains motors together
{
  motorSet(RIGHT_DRIVE_FRONT_MOTOR, RIGHT_DRIVE_REVERSED * power);
  motorSet(RIGHT_DRIVE_REAR_MOTOR, RIGHT_DRIVE_REVERSED * power);
}


void readButtons()
{
  dgoal = joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_LEFT); // check Button 8L is pressed
  rgoal = joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_RIGHT);// check Button 8R is pressed
  sgoal = joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_UP); //check if button 8U was pressed
  powerLeft = joystickGetAnalog(JOY_MASTER, STK3_LEFT_Y);//get left joystick position
  powerRight = joystickGetAnalog(JOY_MASTER, STK2_RIGHT_Y);//get right joystick position
  armup = joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_UP);//check if button 6U was pressed
  armdown = joystickGetDigital(JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_DOWN);//check if button 6D was pressed
  liftup = joystickGetDigital(JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_UP);//check if button 5U was pressed
  liftdown = joystickGetDigital(JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_DOWN);//check if button 5D was pressed
  relcone = joystickGetDigital(JOY_MASTER,BTN7_LEFT_THUMB,JOY_LEFT);//check if button 7L was pressed
  incone = joystickGetDigital(JOY_MASTER,BTN7_LEFT_THUMB,JOY_RIGHT);//check if button 7R was pressed
}
