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

int ts = 0;

void operatorControl() {
	initializeLoopTasks();
	suspendautotasks();
	enabledrivertasks();
	while (1)
{

	readButtons();
	delay(20);
	}
}
