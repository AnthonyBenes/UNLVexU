#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    liftAngleRight, sensorPotentiometer)
#pragma config(Sensor, in2,    coneAngleLeft,  sensorPotentiometer)
#pragma config(Sensor, in3,    coneAngleRight, sensorPotentiometer)
#pragma config(Sensor, in4,    liftAngleLeft,  sensorPotentiometer)
#pragma config(Sensor, in5,    frontLeftLine,  sensorLineFollower)
#pragma config(Sensor, in6,    backRightLine,  sensorLineFollower)
#pragma config(Sensor, in7,    frontRightLine, sensorLineFollower)
#pragma config(Sensor, dgtl1,  extendConeLift, sensorDigitalOut)
#pragma config(Sensor, dgtl2,  pipeSensor,     sensorTouch)
#pragma config(Sensor, dgtl3,  coneGate,       sensorDigitalOut)
#pragma config(Sensor, dgtl4,  mobleGoalLower, sensorTouch)
#pragma config(Sensor, dgtl5,  mobleGoalHigher, sensorTouch)
#pragma config(Sensor, dgtl6,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl10, lowerMobileGoalLimitUP, sensorTouch)
#pragma config(Sensor, dgtl11, leftLowMGDown,  sensorTouch)
#pragma config(Sensor, dgtl12, rightLowMGDown, sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,            ,             tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           driveTrainRight, tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           liftMobileLowerRight, tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_4)
#pragma config(Motor,  port4,           liftMobileHigherRight, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           liftConeRight, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           liftConeLeft,  tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           liftMobileHigherLeft, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           driveTrainLeft, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           liftMobileLowerLeft, tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port10,          coneIntake,    tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma DebuggerWindows("Sensors")
#pragma DebuggerWindows("Motors")
#pragma DebuggerWindows("Locals")
#pragma DebuggerWindows("Globals")

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

//Skills Autonomous
#include "autonomous1.c"

//Match Autonomous Blue
#include "autonomous2.c"

//Match Autonomous Red
#include "autonomous3.c"

//Match Autonomous Red
#include "autonomous4.c"

int Program = 1;

void pre_auton()
{

	SensorValue[leftEncoder] =0;
	SensorValue[rightEncoder] =0;

	bDisplayCompetitionStatusOnLcd = false;
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
	//Leave this value alone
	int lcdScreenMin = 1;
	//This keeps track of which program you want to run
	int lcdScreen = 1;
	//Change this value to be the maximum number of programs you want on the robot
	int lcdScreenMax = 4;
	//Turns on the Backlight
	bLCDBacklight = true;


	const short leftButton = 1;
	const short centerButton = 2;
	const short rightButton = 4;

	while (bIfiRobotDisabled == 1) { //Ensures this code will run ONLY when the robot is disabled
		if (nLCDButtons == leftButton) { //Scrolls to the left
			if (lcdScreenMin == lcdScreen) {
				lcdScreen = lcdScreenMax;
				wait1Msec(250);
				} else {
				lcdScreen --;
				wait1Msec(250);
			}
		}


		if (nLCDButtons == rightButton) { //cycles pnumatics
			if(SensorValue[extendConeLift] == 1){
				SensorValue[extendConeLift] = 0;
				}else{
				SensorValue[extendConeLift] = 1;
			}





		}




		if (lcdScreen == 1 && Program != 1) {
			displayLCDCenteredString (0, "Skills"); //Name the first program here
			displayLCDCenteredString (1, "1"); //Name the first program here

			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
			} else if (lcdScreen == 1 && Program == 1) {
			displayLCDCenteredString (0, "Skills"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[1]"); //So that while we're scrolling, we can have one marked




			} else if (lcdScreen == 2 && Program != 2) {
			displayLCDCenteredString (0, "Match Blue"); //Name the second program here
			displayLCDCenteredString (1, "2"); //Name the second program here

			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
			} else if (lcdScreen == 2 && Program == 2) {
			displayLCDCenteredString (0, "Match Blue"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[2]"); //So that while we're scrolling, we can have one marked




			} else if (lcdScreen == 3 && Program != 3) {
			displayLCDCenteredString (0, "Match Red"); //Name the third program here
			displayLCDCenteredString (1, "3"); //Name the third program here

			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
			} else if (lcdScreen == 3 && Program == 3) {
			displayLCDCenteredString (0, "Match Red"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[3]"); //So that while we're scrolling, we can have one marked





			} else if (lcdScreen == 4 && Program != 4) {
			displayLCDCenteredString (0, "Test"); //Name the fourth program here
			displayLCDCenteredString (1, "4"); //Name the fourth program here

			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
			} else if (lcdScreen == 4 && Program == 4) {
			displayLCDCenteredString (0, "Test"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[4]"); //So that while we're scrolling, we can have one marked
		}
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous(){

	if(Program == 1)        {	autonomous1();	}

		else if (Program == 2){	autonomous2();	}

		else if (Program == 3){	autonomous3();	}

	  else if (Program == 4){	autonomous4();	}

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{


	//logic variables


	bool coneGate = false;
	bool mobileForward = true;
	int highLiftPosition = 1;




	// User control code here, inside the loop

	while (true)
	{



		/*
		 *Drive Calls driveFunctions program to change motor speeds
		 * This snipet of code is not necessery
		if(mobileForward){
			motor[port8] = vexRT[Ch3];
			motor[port2] = vexRT[Ch2];
		}
		else{

			motor[port8] = -(vexRT[Ch2]);
			motor[port2] = -(vexRT[Ch3]);
		}
		*/

		// control robot drive
		motor[port8] = vexRT[Ch3];
		motor[port2] = vexRT[Ch2];




		if(vexRT[Btn7R] == 1 && mobileForward == true){
			mobileForward = false;
		}
		else if(vexRT[Btn7R] == 1 && mobileForward == false){
			mobileForward = true;
		}



		//low lift
		if(vexRT[Btn8U]){
			//goes up

			startTask(LowLiftUp);


			}else if(vexRT[Btn8R]){
			//goes down

			startTask(leftLowLiftDown);
			startTask(rightLowLiftDown);
		}



		//High lift
		if(vexRT[Btn7U]){ //Hight state
			highLift(3, 127);
		}
		else if(vexRT[Btn7D]){
			highLift(1, 127);
			}else if(vexRT(Btn7L)){
			highLift(2, 127);
		}


		/*if(vexRT[Btn7L] && highLiftPosition == 3){ //middle state going down
		motor[liftMobileHigherLeft] = -127;
		motor[liftMobileHigherRight] = -127;
		highLiftPosition = 2;
		if(SensorValue[liftAngleLeft] < 1940){
		motor[liftMobileHigherLeft] = 0;
		}
		if(SensorValue[liftAngleRight] > 1955){
		motor[liftMobileHigherRight] = 0;
		}
		}else if(vexRT[Btn7L] && highLiftPosition == 1){ //middle state going up
		motor[liftMobileHigherLeft] = 127;
		motor[liftMobileHigherRight] = 127;
		highLiftPosition = 2;
		if(SensorValue[liftAngleLeft] > 1940){
		motor[liftMobileHigherLeft] = 0;
		}
		if(SensorValue[liftAngleRight] < 1955){
		motor[liftMobileHigherRight] = 0;
		}
		}*/




		if(vexRT[Btn8L] == 1 && coneGate == false){
			//Activates Cone Lift Pneumatics
			SensorValue[dgtl3] = 0;
			coneGate = true;
		}
		if(vexRT[Btn8D] == 1 && coneGate == true){
			//Deactivates Cone Lift Pneumatics
			SensorValue[dgtl3] = 1;
			coneGate = false;
		}

		//Cone lift

		if(vexRT[Btn5D]){
			motor[liftConeLeft] = 127;
			motor[liftConeRight] = 127;

			}else if(vexRT[Btn5U]){
			motor[liftConeLeft]  = -127;
			motor[liftConeRight] = -127;
			}else{
			motor[liftConeLeft]  = 0;
			motor[liftConeRight] = 0;
		}

		//cone intake

		if(vexRT[Btn6U]){
			motor[coneIntake] = 127;

			}else if(vexRT[Btn6D]){
			motor[coneIntake]  = -127;
			}else{
			motor[coneIntake]  = 0;
		}
	}
}
