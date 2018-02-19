#include "main.h"
extern int dmp;
extern int liftdist;
extern int lmp;
extern int armdist;
extern int amp;
void drivestraight(int counts)
{

  if( (encoderGet(LeftDriveEncoder) < counts) )//stop at mobile goal
  {
    //go straight algorithm
      static int offset = 0;
      if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 15  )
      {
        offset += 10;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 10  )
      {
        offset += 5;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) >= 5  )
      {
        offset += 2;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -5  )
      {
        offset -= 2;
      }
      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -10  )

      {
        offset -= 5;
      }

      else if ( (encoderGet(RightDriveEncoder) - encoderGet(LeftDriveEncoder)) <= -15  )
      {
        offset -= 10;
      }


      else if ( (encoderGet(LeftDriveEncoder) >= -5) && (encoderGet(LeftDriveEncoder) <= 5) )
      {
        offset = 0;
      }

      if ( (offset > 500))
      {
        offset = 500;
      }
      else if (offset < -500)
      {
        offset = -500;
      }
      // char buffer[16];
      // sprintf(buffer,"%d D>",offset);
      // lcdSetText(uart2, 1,buffer);
    motorRightDriveSet(dmp-offset/50);

  }
}

void movelift()
{
  if (encoderGet(LiftEncoder) <= liftdist)
  {
  motorSet(LIFT_MOTOR,lmp);
  }

  else
  {
    motorSet(LIFT_MOTOR,0);
  }
}

void movearm()
{
if (encoderGet(ArmEncoder) <= armdist)
{
  motorSet(ARM_MOTOR,amp);
}
else
{
  motorSet(ARM_MOTOR,0);
}
}
