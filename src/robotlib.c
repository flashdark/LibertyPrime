/* ROBOTLIB.C generic functions used by both driver and auto*/
#include "main.h"

extern TaskHandle mgt;
extern TaskHandle dt;
extern TaskHandle at;
extern TaskHandle lt;
extern TaskHandle it;
extern TaskHandle spd;
extern TaskHandle mat;
extern TaskHandle mlt;
extern TaskHandle amgt;

void TaskManager(TaskHandle th,int operation)
{
  switch(operation)
  {
    case 0:
          taskResume(th);
          break;
    case 1:
          taskSuspend(th);
          break;
    case 2:
          taskDelete(th);
          break;
    default:
            break;
  }
}

void suspenddrivertasks()
{
  TaskManager(mgt,1);
  TaskManager(dt,1);
  TaskManager(at,1);
  TaskManager(lt,1);
  TaskManager(it,1);
}

void suspendautotasks()
{
  TaskManager(mat,1);
  TaskManager(mlt,1);
  TaskManager(amgt,1);
}

void enableautotasks()
{
  TaskManager(mat,0);
  TaskManager(mlt,0);
  TaskManager(amgt,0);
}

void enabledrivertasks()
{
  TaskManager(mgt,0);
  TaskManager(dt,0);
  TaskManager(at,0);
  TaskManager(lt,0);
  TaskManager(it,0);
}

void suspendalltasks()
{
  TaskManager(mgt,1);
  TaskManager(dt,1);
  TaskManager(at,1);
  TaskManager(lt,1);
  TaskManager(it,1);
  TaskManager(mat,1);
  TaskManager(mlt,1);

}

void initializeLoopTasks()
{
  mgt = taskRunLoop(MobileGoalControl,10);
  dt = taskRunLoop(DriverControl,15);
  at = taskRunLoop(ArmControl,5);
  lt = taskRunLoop(LiftControl,20);
  it = taskRunLoop(IntakeControl,16);
  spd = taskRunLoop(getSpeed,1);
  mat = taskRunLoop(movearm,15);
  mlt = taskRunLoop(movelift,10);
  amgt = taskRunLoop(autoMobileGoal,20);
}

void configurePin(int pin)
{
  pinMode(pin, OUTPUT);
}
