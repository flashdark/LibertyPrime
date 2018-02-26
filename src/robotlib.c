/* ROBOTLIB.C generic functions used by both driver and auto*/
#include "main.h"

/* Task Handles for updating state*/
extern TaskHandle spd;
extern TaskHandle mat;
extern TaskHandle mlt;
extern TaskHandle amgt;
extern TaskHandle ait;
void TaskManager(TaskHandle th,int operation)
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

void suspendautotasks() //suspend auton tasks at the end of auton
{
  TaskManager(mat,1);
  TaskManager(mlt,1);
  TaskManager(amgt,1);
}

void enableautotasks()//enable auton tasks
{
  TaskManager(mat,0);
  TaskManager(mlt,0);
  TaskManager(amgt,0);
}


void suspendalltasks()//suspend all tasks
{

  TaskManager(mat,1);
  TaskManager(mlt,1);

}

void initializeLoopTasks()
{
  spd = taskRunLoop(getSpeed,1);
  mat = taskRunLoop(movearm,15);
  mlt = taskRunLoop(movelift,16);
  amgt = taskRunLoop(autoMobileGoal,20);
  ait = taskRunLoop(intake,10);
}

void configurePin(int pin)
{
  pinMode(pin, OUTPUT);
}
