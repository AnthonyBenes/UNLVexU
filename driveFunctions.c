/*
*These function support programmer to interact with cortex executer
*
*/

const float INCH_PER_TICK = ;
const float CHASSIS_LENGTH = ;// chassis length from center to center
												// of front wheel.
const float CHASSIS_WIDTH = ;

/*Function declaration */

/*
*This function set the speed of the 2 motorB
*@parameter  int rightSide
*					   int leftSide
*/
void setMotorSpeed(int rightSide, int leftSide){
	motor[driveBackLeft] = leftSide;
	motor[driveFrontLeft] = leftSide;
	motor[driveBackRight] = rightSide;
	motor[driveFrontRight] = rightSide;
}


/*
*this function move the robot foward to the requester distance in inches
*parameter:float dist (inches) (distance from the center of the chassis)
*						int speed (-100 , 100)
*Tick refer to one encoder unit.
*/
void goForward(float dist,int speed){

	// these two variables are set to the number of tick to turn relative
	// from the center of wheel to requested position
	float frontMotorTick = (dist- CHASSIS_LENGTH/2) / INCH_PER_TICK;
	float backMotorTick = (dist+ CHASSIS_LENGTH/2) / INCH_PER_TICK;


	//initialize all encoder value at 0
	motor[driveBackLeft] = 0;
	motor[driveFrontLeft] = 0;
	motor[driveBackRight] = 0;
	motor[driveFrontRight] = 0;

	// reset the encoder.
	resetMotorEncoder(motor[driveFrontLeft]);
	resetMotorEncoder(motor[driveFrontRight]);
	resetMotorEncoder(motor[driveBackLeft]);
	resetMotorEncoder(motor[driveBackRight]);

	//set the encoder and motor to requested distance
	setMotorTarget(motor[driveBackLeft],backMotorTick,speed);
	setMotorTarget(motor[driveBackRight],backMotorTick,speed);
	setMotorTarget(motor[driveFrontLeft],frontMotorTick,speed);
	setMotorTarget(motor[driveFrontRight],frontMotorTick,speed);


	// wait until motor stop
 	waitUntilMotorStop(motor[driveBackLeft]);
	waitUntilMotorStop(motor[driveBackRight]);
	waitUntilMotorStop(motor[driveFrontLeft]);
	waitUntilMotorStop(motor[driveFrontRight]);

}// end forward

/*
*This function will rotate the robot relative to it front drive
*constrain axis

		|||-----|||
			|	 ^  |
      |  |  |
			|	 |  |
		|||-----|||
*/
void headRotation(int degree, int power){

}// end headRotate()


/*
*This function will rotate the robot relative to it front drive
*constrain axis

		|||-----|||
			|	 |  |
      |  |  |
			|	 _  |
		|||-----|||
				 ^(axis of rotation)
*/
void tailRotation(int degree, int power){

}// end tailRotation
