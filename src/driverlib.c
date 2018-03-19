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
  rgoal = joystickGetDigital(JOY_MASTER,BTN_MGOAL,BTN_MGOAL_RETRACT); // check Button 8L is pressed
  dgoal = joystickGetDigital(JOY_MASTER,BTN_MGOAL,BTN_MGOAL_DEPLOY);// check Button 8R is pressed
  sgoal = joystickGetDigital(JOY_MASTER,BTN_MGOAL,BTN_MGOAL_AUTOSCORE); //check if button 8U was pressed
  powerLeft = joystickGetAnalog(JOY_MASTER, STICK_LEFT_DRIVE);//get left joystick position
  powerRight = joystickGetAnalog(JOY_MASTER, STICK_RIGHT_DRIVE);//get right joystick position
  armup = joystickGetDigital(JOY_MASTER,BTN_ARM,BTN_ARM_UP);//check if button 6U was pressed
  armdown = joystickGetDigital(JOY_MASTER,BTN_ARM,BTN_ARM_DOWN);//check if button 6D was pressed
  liftup = joystickGetDigital(JOY_MASTER,BTN_LIFT,BTN_LIFT_UP);//check if button 5U was pressed
  liftdown = joystickGetDigital(JOY_MASTER,BTN_LIFT,BTN_LIFT_DOWN);//check if button 5D was pressed
  relcone = joystickGetDigital(JOY_MASTER,BTN_CONE,BTN_CONE_OUT);//check if button 7L was pressed
  incone = joystickGetDigital(JOY_MASTER,BTN_CONE,BTN_CONE_IN);//check if button 7R was pressed
}
