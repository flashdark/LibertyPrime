#ifndef ROBOT_H // this is a header guard used to avoid the problem of double inclusion
#define ROBOT_H

#include "main.h"

// analog ports
#define SELECT_MODE_POT 1
#define MOGO_POT 6
#define PWR_EXP_PORT 3
#define ARM_POT 4
#define SELECT_COLOR_POT 5

// digital ports
// Flip encoder top bottom to change the direciton of increasing counts
#define LEFT_DRIVE_ENCODER_TOP 6
#define LEFT_DRIVE_ENCODER_BOTTOM 5
#define LEFT_DRIVE_ENCODER_REVERSE 0
#define LEFT_DRIVE_ENCODER LEFT_DRIVE_ENCODER_TOP,LEFT_DRIVE_ENCODER_BOTTOM,LEFT_DRIVE_ENCODER_REVERSE

#define RIGHT_DRIVE_ENCODER_TOP 2
#define RIGHT_DRIVE_ENCODER_BOTTOM 1
#define RIGHT_DRIVE_ENCODER_REVERSE 0
#define RIGHT_DRIVE_ENCODER RIGHT_DRIVE_ENCODER_TOP,RIGHT_DRIVE_ENCODER_BOTTOM,RIGHT_DRIVE_ENCODER_REVERSE

#define LIFT_ENCODER_TOP 3
#define LIFT_ENCODER_BOTTOM 4
#define LIFT_ENCODER_REVERSE 0
#define LIFT_ENCODER LIFT_ENCODER_TOP,LIFT_ENCODER_BOTTOM,LIFT_ENCODER_REVERSE

// split motors across the 3 PTC's 1-5, 6-10, and Pwr Exp.
// motor port definitions
#define LEFT_DRIVE_FRONT_MOTOR 2    // via Power Expander
#define LEFT_DRIVE_REAR_MOTOR 3     // Y-Cable
#define RIGHT_DRIVE_FRONT_MOTOR 6   // via Power Expander
#define RIGHT_DRIVE_REAR_MOTOR 7    // Y-Cable

#define LEFT_DRIVE_REVERSED 1       // 1=Not Reversed, -1=Reversed
#define RIGHT_DRIVE_REVERSED -1     // 1=Not Reversed, -1=Reversed

#define MOGO_MOTOR 1                // Mobile Goal

#define ARM_MOTOR   4 // Y-Cable
#define INTAKE_MOTOR  9 //
#define LIFT_MOTOR  8 // Y-Cable via Power Expander

// define readable names for joystick buttons
#define JOY_MASTER 1          // the main controller
#define JOY_SLAVE 2           // the partner controller
#define STK1_RIGHT_X 1        // returns values of -127 to 127 (Back to Forward)
#define STK2_RIGHT_Y 2        // returns values of -127 to 127 (Left to Right)
#define STK4_LEFT_X 4         // returns values of -127 to 127 (Back to Forward)
#define STK3_LEFT_Y 3         // returns values of -127 to 127 (Left to Right)
#define BTN5_LEFT_TRIGGER 5   // JOY_UP and JOY_DOWN
#define BTN6_RIGHT_TRIGGER 6  // JOY_UP and JOY_DOWN
#define BTN7_LEFT_THUMB 7     // JOY_LEFT, JOY_RIGHT, JOY_UP and JOY_DOWN
#define BTN8_RIGHT_THUMB 8    // JOY_LEFT, JOY_RIGHT, JOY_UP and JOY_DOWN

// All the controller button/stick assignments are grouped here.
// game friendly names are used to make readable code
// this also allows easy re-assignment of buttons

// define usage names for drive joystick buttons and thresholds
#define STICK_RIGHT_DRIVE JOY_MASTER,STK2_RIGHT_Y
#define STICK_LEFT_DRIVE  JOY_MASTER,STK3_LEFT_Y
#define STICK_THRESHOLD 15

// Trigger groups
#define BTN_LIFT_UP   JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_UP
#define BTN_LIFT_DOWN JOY_MASTER,BTN5_LEFT_TRIGGER,JOY_DOWN
#define BTN_ARM_UP    JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_UP
#define BTN_ARM_DOWN  JOY_MASTER,BTN6_RIGHT_TRIGGER,JOY_DOWN

// Button Group 7
#define BTN_INTAKE_INGRESS JOY_MASTER,BTN7_LEFT_THUMB,JOY_LEFT
#define BTN_INTAKE_EGRESS  JOY_MASTER,BTN7_LEFT_THUMB,JOY_RIGHT

#define BTN_FASTACK_CONE     JOY_MASTER,BTN7_LEFT_THUMB,JOY_UP
#define BTN_FASTACK_SUBTRACT JOY_MASTER,BTN7_LEFT_THUMB,JOY_DOWN

// Button Group 8
#define BTN_MOGO_INGRESS   JOY_MASTER,BTN8_RIGHT_THUMB,JOY_LEFT
#define BTN_MOGO_EGRESS    JOY_MASTER,BTN8_RIGHT_THUMB,JOY_RIGHT
#define BTN_MOGO_AUTOSCORE JOY_MASTER,BTN8_RIGHT_THUMB,JOY_UP

#define BTN_FASTACK_RESET JOY_MASTER,BTN8_RIGHT_THUMB,JOY_DOWN

// Lift position
#define LIFT_STOWED 0
#define LIFT_MAX_HEIGHT 1000

// Lift power values
#define LIFT_DOWN_POWER -127
#define LIFT_UP_POWER 127

// Arm position
#define ARM_STOWED 1200
#define ARM_DEPLOYED 3900
#define ARM_DECEL_POINT 1800
#define ARM_STACK 1225   // encoder value to stack a cone
#define ARM_PRESTACK 2200 //encoder value to hold at when raising lift

// Arm power values
#define ARM_DOWN_POWER -60
#define ARM_UP_POWER 127
#define ARM_DECEL_POWER 40
#define ARM_HOLD_POWER 50

// Intake power values
#define INTAKE_EGRESS_POWER 127
#define INTAKE_INGRESS_POWER -127
#define INTAKE_INGRESS_HOLD_POWER -15

// Mogo Lift Positions
#define MOGO_STOWED 5
#define MOGO_GRAVITY_POINT 950
#define MOGO_PLACE_POINT 1300
#define MOGO_DEPLOYED 1500

// Mogo Lift Power
#define MOGO_EGRESS_POWER -100
#define MOGO_INGRESS_POWER 127

// Autonomous Definitions for LCD Display
#define STRING_AUTON_1 "M1 Cone+SG"
#define STRING_AUTON_2 "#2 "
#define STRING_AUTON_3 "#3 "
#define STRING_AUTON_4 "#4 "
#define STRING_AUTON_5 "#5 "
#define STRING_AUTON_6 "#6 "
#define STRING_AUTON_7 "#7 "
#define STRING_AUTON_8 "#8 "
#define STRING_AUTON_9 "#9 "


#define LCD_DEBUG_OFF 0
#define LCD_DEBUG_OPCONTROL 1
#define LCD_DEBUG_FASTACK 2
#define LCD_DEBUG_MOGO 3
#define LCD_DEBUG_LIFT 4
#define LCD_DEBUG_ARM 5
#define LCD_DEBUG_AUTON1 6
#define LCD_DEBUG_LEVEL LCD_DEBUG_AUTON1
#define LCD_DEBUG_DELAY 3000

// Macros
// bit hacks from http://graphics.stanford.edu/~seander/bithacks.html#CopyIntegerSign
// sign(x) where x is an int and 8 is bits in a byte
#define sign(x) (+1 | (x >> (sizeof(int) * 8 - 1)))

// attempt to make the speed linear so the robot is easier to control
// from Jordan's mappings on vex forum
// first 11 locations are 0 for joystick threshold.
static const unsigned int trueSpeed[128] =
{
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0, 21, 21, 21, 22, 22, 22, 23, 24, 24,
 25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
 28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
 33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
 37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
 41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
 46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
 52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
 61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
 71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
 80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
 88, 89, 89, 90, 90,127,127,127
};

// variables declared in one file and used in others
extern unsigned g_selectedAutonomous; // getAutonMode is the only function that sets this global variable
extern Encoder liftEncoder;
extern Encoder leftDriveEncoder;
extern Encoder rightDriveEncoder;

// prototypes for functions
void getAutonMode();
void displayRobotStatus();
void auton1();
void auton2();
void auton3();
void auton4();
void auton5();
void auton6();
void auton7();
void auton8();
void auton9();

extern void fastack();

void lcdDebug(const char *str1, const char *str2, int lcdLevel, int lcdDelay);
int iemInches2Counts(float inches);
int encoderInches2Counts(float inches);
void motorLeftDriveSet(int speed);
void motorRightDriveSet(int speed);

#endif // ROBOT_H
