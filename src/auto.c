#include "main.h"

int dmp = 0;//drive motor power
int liftdist = 0;//how far to lift
int lmp = 0; //power to use when lifting
int armdist = 0;//dist to move arm
int amp = 0;//power to use to move arm
int mgs = 0;//mobile goal task state
int volatile operation = 0;
int volatile intpwr = 0;
unsigned g_selectedAutonomous = 0;
bool volatile drivedone = false;

/*Task Handles used to change task states*/
extern TaskHandle mgt;
extern TaskHandle dt;
extern TaskHandle at;
extern TaskHandle lt;
extern TaskHandle it;
extern TaskHandle spd;
extern TaskHandle mat;
extern TaskHandle mlt;
extern TaskHandle ait;

int readmgs()//read mobile goal state
{
  return mgs;
}

void writemgs(int op)//update mobile goal state
{
  mgs = op;
}

void getAutonMode() {
  lcdSetBacklight(uart2, true);
  char buf[17];
  //sprintf(buf,"%d",analogRead(SELECT_MODE_POT));
  int modePotValue = analogRead(SELECT_MODE_POT);
  // char buff[16];
  // sprintf(buff,"%d",modePotValue);
  // lcdSetText(uart2,2,buff);
  g_selectedAutonomous = 0;

  // 1st choice
  if (modePotValue <= 5) {
    lcdSetText(uart2, 1, STRING_AUTON_1);
    //lcdSetText(uart2,2,buf);
    g_selectedAutonomous = 1;
  }
  // 2nd choice
  else if (modePotValue <= 345) {
    lcdSetText(uart2, 1, STRING_AUTON_2);
    g_selectedAutonomous = 2;
    //lcdSetText(uart2,2,buf);
  }
  // 3rd choice
  else if (modePotValue <= 905) {
    lcdSetText(uart2, 1, STRING_AUTON_3);
    g_selectedAutonomous = 3;
  //  lcdSetText(uart2,2,buf);
  }
  // 4th choice
  else if (modePotValue <= 1410) {
    lcdSetText(uart2, 1, STRING_AUTON_4);
    g_selectedAutonomous = 4;
    //lcdSetText(uart2,2,buf);
  }
  // 5th choice
  else if (modePotValue <= 1880) {
    lcdSetText(uart2, 1, STRING_AUTON_5);
    g_selectedAutonomous = 5;
    //lcdSetText(uart2,2,buf);
  }
  // 6th choice
  else if (modePotValue <= 2430) {
    lcdSetText(uart2, 1, STRING_AUTON_6);
    g_selectedAutonomous = 6;
    //lcdSetText(uart2,2,buf);
  }
  // 7th choice
  else if (modePotValue <= 3025) {
    lcdSetText(uart2, 1, STRING_AUTON_7);
    g_selectedAutonomous = 7;
    //lcdSetText(uart2,2,buf);
  }
  // 8th choice
  else if (modePotValue <= 3685) {
    lcdSetText(uart2, 1, STRING_AUTON_8);
    g_selectedAutonomous = 8;
    //lcdSetText(uart2,2,buf);
  }
  // 9th choice
  else if (modePotValue <= 4075) {
    lcdSetText(uart2, 1, STRING_AUTON_9);
    g_selectedAutonomous = 9;
    //lcdSetText(uart2,2,buf);
  }
  // 10th choice
  else if (modePotValue > 4076) {
    lcdSetText(uart2, 1, STRING_AUTON_A);
    g_selectedAutonomous = 10;
    //lcdSetText(uart2,2,buf);
  }
} // end getAutonMode

///////////////////////////////////////////////////////////////////////////////
// Use LCD buttons to display
// Battery Voltages
// Disable LCD Backlight
// Autonomous Selection
// called from initialize and opcontrol
///////////////////////////////////////////////////////////////////////////////
void displayRobotStatus() {
  char mainBattery[16], backupBattery[16];

  // When Left and Middle button pressed
  // display raw value from autonModePot for calibrating auton selection
  if ((lcdReadButtons(uart2) & LCD_BTN_LEFT) &&
      (lcdReadButtons(uart2) & LCD_BTN_CENTER)) {


    // Short delay for the LCD refresh rate
    taskDelay(100);
  } else if (lcdReadButtons(uart2) & LCD_BTN_LEFT) {
    lcdSetBacklight(uart2, true); // Turn on LCD Backlight

    // Display the Primary Robot battery voltage
    sprintf(mainBattery, "M:%1.2fV, E: %1.2fV", powerLevelMain() / 1000.0,
            analogRead(PWR_EXP_PORT) / 280.0);
    lcdSetText(uart2, 1, mainBattery);

    // Display the Backup battery voltage
    sprintf(backupBattery, "B:%1.2fV", powerLevelBackup() / 1000.0);
    lcdSetText(uart2, 2, backupBattery);

    // Short delay for the LCD refresh rate
    taskDelay(100);
  } else if (lcdReadButtons(uart2) & LCD_BTN_CENTER) {
    lcdSetBacklight(uart2, false); // Turn off LCD Backlight
    taskDelay(100);
  }
  // Right button calls this function from usercontrol() or during initialize.
  else if ((lcdReadButtons(uart2) & LCD_BTN_RIGHT) || !isEnabled()) {
    getAutonMode();
    taskDelay(100);
  }

} // end displayRobotStatus()


void autonomous() {

initializeLoopTasks();
getAutonMode();

  //lcdSetText(uart2,2,buf);
  switch (g_selectedAutonomous) {
  case 1:
    auton1();
    //sprintf(buf,"A1 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 2:
    auton2();
    //sprintf(buf,"A2 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 3:
    auton3();
    //sprintf(buf,"A3 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 4:
    auton4();
    //sprintf(buf,"A4 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 5:
    auton5();
    //sprintf(buf,"A5 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 6:
    auton6();

    break;
  case 7:
    auton7();
    //sprintf(buf,"A7 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 8:
    auton8();
    //sprintf(buf,"A8 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 9: // Skills Auton
    auton9();
    //sprintf(buf,"A9 Called");
    //lcdSetText(uart2,2,buf);
    break;
  case 10:
    autonA();
    //sprintf(buf,"A10 Called");
    //lcdSetText(uart2,2,buf);
    break;
  default:
    lcdSetText(uart2, 1, "No Valid Choice");
    lcdSetText(uart2, 2, "   Was Made");
    break;
  } // switch
}
