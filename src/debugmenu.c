// #include "main.h"
// /* Debug Menu for auton and driver testing*/
//
//
//
// void showdebugmenu()
// {
//
//   char buffer1[16];
//   char buffer2[16];
//   static int dbgstate = 0;
//   static int runnum = 0;
//   //while(1)
//   {
//
//   //lcdClear(uart2);
//     if(joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_DOWN) && joystickGetDigital(JOY_MASTER,BTN8_RIGHT_THUMB,JOY_UP)  && runnum > 9)
//     {
//       lcdSetBacklight(uart2,1);
//
//
//         switch(dbgstate)
//
//         {
//             case 0:
//               sprintf(buffer1,"Arm: %d",encoderGet(ArmEncoder));
//               sprintf(buffer2,"Lift: %d",encoderGet(LiftEncoder));
//               lcdSetText(uart2,1,buffer1);
//               lcdSetText(uart2,2,buffer2);
//               dbgstate++;
//               break;
//             case 1:
//               sprintf(buffer1,"LDrive: %d",encoderGet(LeftDriveEncoder));
//               sprintf(buffer2,"RDrive: %d",encoderGet(RightDriveEncoder));
//               lcdSetText(uart2,1,buffer1);
//               lcdSetText(uart2,2,buffer2);
//               dbgstate++;
//               break;
//             case 2:
//               sprintf(buffer1,"GoalPot: %d",analogRead(MOBILE_GOAL_POT));
//               sprintf(buffer2,"Mobile State: %d",readmgs());
//               lcdSetText(uart2,1,buffer1);
//               lcdSetText(uart2,2,buffer2);
//               dbgstate++;
//               break;
//             default:
//               dbgstate = 0;
//               break;
//         } //switch
//         runnum = 0;
//     }//if
//     else {runnum++;}
//       delay(30);
//
//   }//end while
// }//end func
