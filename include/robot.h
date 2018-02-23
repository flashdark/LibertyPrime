#include <API.h>
#ifndef ROBOT_H // this is a header guard used to avoid the problem of double inclusion
#define ROBOT_H

// analog ports
#define SELECT_MODE_POT 1
#define MOBILE_GOAL_POT 6
#define PWR_EXP_PORT 3

#define DISPLAY_MODE_POT 4


// digital ports
#define LEFT_DRIVE_ENCODER_TOP 8 // should yield positive counts for forward motion
#define LEFT_DRIVE_ENCODER_BOTTOM 7
#define RIGHT_DRIVE_ENCODER_TOP 2
#define RIGHT_DRIVE_ENCODER_BOTTOM 1
#define LIFT_ENCODER_TOP 5
#define LIFT_ENCODER_BOTTOM 6
#define ARM_ENCODER_TOP 3
#define ARM_ENCODER_BOTTOM 4

//class object creation
Encoder ArmEncoder;
Encoder LiftEncoder;
Encoder LeftDriveEncoder;
Encoder RightDriveEncoder;

// split motors across the 3 PTC's 1-5, 6-10, and Pwr Exp.
// motor port definitions
#define LEFT_DRIVE_FRONT_MOTOR 2    // via Power Expander
#define LEFT_DRIVE_REAR_MOTOR 3     // Y-Cable
#define RIGHT_DRIVE_FRONT_MOTOR 6   // via Power Expander
#define RIGHT_DRIVE_REAR_MOTOR 7    // Y-Cable

#define LEFT_DRIVE_REVERSED 1       // 1=Not Reversed, -1=Reversed
#define RIGHT_DRIVE_REVERSED -1     // 1=Not Reversed, -1=Reversed

#define MOBILE_GOAL_MOTOR 1

#define ARM_MOTOR   4 // Y-Cable
#define CLAW_MOTOR  9 //
#define LIFT_MOTOR  8 // Y-Cable via Power Expander

// define readable names for joystick buttons
#define JOY_MASTER 1          // the main controller (not the partner controller)
#define STK1_RIGHT_X 1        // returns values of -127 to 127 (Back to Forward)
#define STK2_RIGHT_Y 2        // returns values of -127 to 127 (Left to Right)
#define STK4_LEFT_X 4         // returns values of -127 to 127 (Back to Forward)
#define STK3_LEFT_Y 3         // returns values of -127 to 127 (Left to Right)
#define BTN5_LEFT_TRIGGER 5   // JOY_UP and JOY_DOWN
#define BTN6_RIGHT_TRIGGER 6  // JOY_UP and JOY_DOWN
#define BTN7_LEFT_THUMB 7     // JOY_LEFT, JOY_RIGHT, JOY_UP and JOY_DOWN
#define BTN8_RIGHT_THUMB 8     // JOY_LEFT, JOY_RIGHT, JOY_UP and JOY_DOWN

// define usage names for joystick buttons and thresholds
#define STICK_RIGHT_DRIVE 2
#define STICK_LEFT_DRIVE 3
#define STICK_THRESHOLD 15

#define BTN_LIFT BTN5_LEFT_TRIGGER
#define BTN_ARM_UP  JOY_UP
#define BTN_ARM_DOWN JOY_DOWN
#define BTN_CLAW_OPEN JOY_LEFT
#define BTN_CLAW_CLOSE JOY_RIGHT
#define BTN_MGOAL JOY_RIGHT

// Autonomous Definitions for LCD Display
#define STRING_AUTON_1 "Cone+SG"
#define STRING_AUTON_2 "Mobile Goal 20"
#define STRING_AUTON_3 "20 Test"
#define STRING_AUTON_4 "30 Test"
#define STRING_AUTON_5 "#5 "
#define STRING_AUTON_6 "D Test 1"
#define STRING_AUTON_7 "T Steer Test "
#define STRING_AUTON_8 "D Test 3 "
#define STRING_AUTON_9 "D Test 4 "
#define STRING_AUTON_A "#A "


//driver related methods
void readButtons();
void MobileGoalControl();
void DriverControl();
void LiftControl();
void ArmControl();
void IntakeControl();
int iemInches2Counts(float inches);
int encoderInchesToCounts(float inches);
void motorLeftDriveSet(int power);
void motorRightDriveSet(int power);

//auto related methods
extern unsigned g_selectedAutonomous; // getAutonMode is the only function that sets this global variable
void getSpeed();
void stack();
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
void autonA();
void drivebackward();
void AccelerateBackward(int power);
void AccelerateForward(int power);
void driveforward(int counts, int power);
void driveBackward(int counts, int power);
void turnCclwise(int counts);
void turnClockwise(int counts);
void drivestraight();
void movelift();
void movearm();
void decelerate(int counts);
void autoMobileGoal();
void deploymobilegoal();
void retractmobilegoal();
void drivestraightBack();
void decelerateBack(int counts);
int readmgs();
void writemgs(int op);
void configurePin(int pin);

//task related methods
void suspenddrivertasks();
void suspendautotasks();
void enableautotasks();
void enabledrivertasks();
void TaskManager(TaskHandle th,int operation);
void suspendalltasks();
void initializeLoopTasks(); //PROS destroys tasks crated by taskRunLoop() when mode changes or disable occurs
#endif // ROBOT_H
