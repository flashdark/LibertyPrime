/* ROBOTLIB.C generic functions used by both driver and auto*/
#include "main.h"

/* Task Handles for updating state*/
extern TaskHandle spd;
extern TaskHandle mat;
extern TaskHandle mlt;
extern TaskHandle amgt;
extern TaskHandle ait;

void TaskManager(TaskHandle th,int operation)//manages tasks
{
  switch(operation)
  {
    case 0:
          taskResume(th);//resume the task given by the task handle
          break;
    case 1:
          taskSuspend(th);//suspend the task given by the task handle
          break;
    case 2:
          taskDelete(th);//destroy the task given by the task handle
          break;
    default:
            break;
  }
}


void initializeLoopTasks() //initalize auton tasks
{
  spd = taskRunLoop(getSpeed,1);
  mat = taskRunLoop(movearm,15);
  mlt = taskRunLoop(movelift,16);
  amgt = taskRunLoop(autoMobileGoal,20);
  ait = taskRunLoop(intake,10);
}
//for LED's
// void configurePin(int pin)
// {
//   pinMode(pin, OUTPUT);
// }
