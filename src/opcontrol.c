#include "main.h"

int mp = 0;
bool dforward = false;
bool dbackward = false;
bool armforward = false;
bool armbackward = false;
bool grab = false;
bool release = false;
int powerLeft = 0;
int powerRight = 0;
bool armup = false;
bool armdown = false;
bool liftup = false;
bool liftdown = false;
bool incone = false;
bool relcone = false;
bool shiftpressed = false;
bool dgoal = false;
bool rgoal = false;
bool sgoal = false;


void operatorControl() {
	// initializeLoopTasks();
	// suspendautotasks();
	//enabledrivertasks();
	TaskHandle as = taskCreate(fastack,TASK_DEFAULT_STACK_SIZE,NULL,TASK_PRIORITY_DEFAULT);
	while (1)
{
	char buffer[16];
	sprintf(buffer,"%d",shiftpressed);
	lcdSetText(uart2,1,buffer);

	delay(20);

	readButtons(); //read joystick and set values for operation
	MobileGoalControl(); //move mobile goal in or out
	IntakeControl();//control intake
	DriverControl();//control the drivetrain
	ArmControl(); //control the arm
	LiftControl(); //control the lift

	delay(20);
	}
}
