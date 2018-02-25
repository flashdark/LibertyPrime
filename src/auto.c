#include "main.h"

int dmp = 0;//drive motor power
int liftdist = 0;//how far to lift
int lmp = 0; //power to use when lifting
int armdist = 0;//dist to move arm
int amp = 0;//power to use to move arm
int mgs = 0;//mobile goal task state
int operation = 0;
unsigned g_selectedAutonomous = 0;

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

int readmgs()
{
  return mgs;
}

void writemgs(int op)
{
  mgs = op;
}

void getAutonMode() {
  lcdSetBacklight(uart2, true);
  int modePotValue = analogRead(SELECT_MODE_POT);
  // char buff[16];
  // sprintf(buff,"%d",modePotValue);
  // lcdSetText(uart2,2,buff);
  g_selectedAutonomous = 0;

  // 1st choice
  if (modePotValue <= 5) {
    lcdSetText(uart2, 1, STRING_AUTON_1);
    g_selectedAutonomous = 1;
  }
  // 2nd choice
  else if (modePotValue <= 345) {
    lcdSetText(uart2, 1, STRING_AUTON_2);
    g_selectedAutonomous = 2;
  }
  // 3rd choice
  else if (modePotValue <= 905) {
    lcdSetText(uart2, 1, STRING_AUTON_3);
    g_selectedAutonomous = 3;
  }
  // 4th choice
  else if (modePotValue <= 1410) {
    lcdSetText(uart2, 1, STRING_AUTON_4);
    g_selectedAutonomous = 4;
  }
  // 5th choice
  else if (modePotValue <= 1880) {
    lcdSetText(uart2, 1, STRING_AUTON_5);
    g_selectedAutonomous = 5;
  }
  // 6th choice
  else if (modePotValue <= 2430) {
    lcdSetText(uart2, 1, STRING_AUTON_6);
    g_selectedAutonomous = 6;
  }
  // 7th choice
  else if (modePotValue <= 3025) {
    lcdSetText(uart2, 1, STRING_AUTON_7);
    g_selectedAutonomous = 7;
  }
  // 8th choice
  else if (modePotValue <= 3685) {
    lcdSetText(uart2, 1, STRING_AUTON_8);
    g_selectedAutonomous = 8;
  }
  // 9th choice
  else if (modePotValue <= 4075) {
    lcdSetText(uart2, 1, STRING_AUTON_9);
    g_selectedAutonomous = 9;
  }
  // 10th choice
  else if (modePotValue > 4076) {
    lcdSetText(uart2, 1, STRING_AUTON_A);
    g_selectedAutonomous = 10;
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
    // TBD

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
suspenddrivertasks();
//enableautotasks();
auton5();

}
