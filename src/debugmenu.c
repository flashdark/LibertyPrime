#include "main.h"
/* Debug Menu for auton and driver testing*/
extern int dbgstate;

void showdebugmenu(void * params)
{
  while(1)
  {
  char buffer1[16];
  char buffer2[16];
  if(joystickGetDigital(JOY_SLAVE,BTN8_RIGHT_THUMB,JOY_DOWN))
  {



  switch(dbgstate)

  {
    case 0:
            sprintf(buffer1,"Arm: %d",encoderGet(ArmEncoder));
            sprintf(buffer2,"Lift: %d",encoderGet(LiftEncoder));
            lcdSetText(uart2,1,buffer1);
            lcdSetText(uart2,2,buffer2);
            break;
    case 1:
            sprintf(buffer1,"LDrive: %d",encoderGet(LeftDriveEncoder));
            sprintf(buffer2,"RDrive: %d",encoderGet(RightDriveEncoder));
            lcdSetText(uart2,1,buffer1);
            lcdSetText(uart2,2,buffer2);
            break;
   case 2:
            sprintf(buffer1,"GoalPot: %d",analogRead(MOBILE_GOAL_POT));
            sprintf(buffer2,"Mobile State: %d",readmgs());
            lcdSetText(uart2,1,buffer1);
            lcdSetText(uart2,2,buffer2);
            break;
  default:
          dbgstate = 0;
          break;
  }
}
  }
}
