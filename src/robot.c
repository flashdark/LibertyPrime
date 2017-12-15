#include <API.h>
#include "robot.h"


/*---------------------------------------------------------------------------*/
/*                          Robot Specific Functions                         */
/*                          Used by All Code                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/

///////////////////////////////////////////////////////////////////////////////
// Convert Inches to Counts of the integrated encoder module
// Integrated Encoder has 627.2 counts per revolution
// Circumference of wheel is 12.56637
// used to move robot in auton
///////////////////////////////////////////////////////////////////////////////
int iemInches2Counts(float inches)
{
	// divide one revolution of counts by the circumference of the wheel
	return (int)(627.2/12.56637 * inches);
}

///////////////////////////////////////////////////////////////////////////////
// Convert Counts to Inches of the integrated encoder module
// Integrated Encoder has 627.2 counts per revolution
// Circumference of wheel is 12.56637
// TBD: used to calibrate drive on different fields, but need a button to hit
// fence so we know robot has moved full distance. Get count then from move,
// convert to inches, calibrate distance for next move.
///////////////////////////////////////////////////////////////////////////////
//int iemCounts2Inches(int counts)
//{
//  // divide the circumference of the wheel by one revolution of counts
//	return 12.56637/627.2 * counts;
//}

///////////////////////////////////////////////////////////////////////////////
// Convert Inches to Counts of the optical encoder module
// Optical Encoder has 360 counts per revolution
// Circumference of wheel is 4*3.14=12.56637
// used to move robot in auton
///////////////////////////////////////////////////////////////////////////////
int encoderInchesToCounts(float inches)
{
 return (int)(360/12.56637 * inches);
}

///////////////////////////////////////////////////////////////////////////////
// Convert Counts to Inches of the integrated encoder module
// Optical Encoder has 360 counts per revolution
// Circumference of wheel is 12.56637
// TBD: used to calibrate drive on different fields, but need a button to hit
// fence so we know robot has moved full distance. Get count then from move,
// convert to inches, calibrate distance for next move.
///////////////////////////////////////////////////////////////////////////////
//int encoderCounts2Inches(int counts)
//{
//  // divide the circumference of the wheel by one revolution of counts
//	return 12.56637/360 * counts;
//}
///////////////////////////////////////////////////////////////////////////////
// TBD comment 
///////////////////////////////////////////////////////////////////////////////
void motorLeftDriveSet (int speed)
{
 // TBD code
}

///////////////////////////////////////////////////////////////////////////////
// TBD comment 
///////////////////////////////////////////////////////////////////////////////
void motorRightDriveSet (int speed)
{
 // TBD code
}
