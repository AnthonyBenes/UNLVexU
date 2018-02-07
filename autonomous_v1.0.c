/*
*Author UNL vex U
*Date feb 2nd 2018
*Version : 1.0
*/

/* Define variables */
// constant
float INCH_PER_TICK
float TICK_PER_INCH

float WHEEL_DIAMETER

// relative to the center point to the two wheel
float CHASSIS_WIDTH
float CHASSIS_LENGTH

float ONE_RADIAN = PI/180;


/*
 *This function convert distance request the robot to travel
 *to number of ticks
 * @ parameter ( float inch, int power of motor)
 * EX: goForward(2.8, 50);
 * Go foward 28 inches with 50 power of the motor.
 */
void goForward(float inch,int power){

  int tickGoal = inch * TICK_PER_INCH ;

  // start encoder count at 0
  resetMotorEncoder(motor[port2]);
  resetMotorEncoder(motor[port8]);

  // go to requested ticks.
  while(getMotorEncoder(port8) < tickGoal){
    motor[port2] = power ;
    motor[port8] = power ;
  }

  // stop motor
  motor[port2] = 0;
  motor[port8] = 0;
}

/*
 *this function will rotate the robot
 *@parameter (char axis(L,C,R), int degree, int powe)
 *
          FL|---F---|FR
             |     |
             |  C  |
             |     |
        BL  |---B---|BR
EX: rotate('F',200,50);
  The robot will rotate at the F axis by 200 degrees(CW)
  with 50 power.

EX: rotate('C',-100,100);
  The robot will rotate at the C axis by 100 degrees(CCW)
  with 100 power.
  *
  *motor pre configuration*
  *frontRightDrive,frontLeftDrive, backLeftDrive,
  *backRightDrive;
  */
 void rotate(char axis, int degree, int power){

   // initilize motor at 0 ticks.
   resetMotorEncoder(frontRightDrive);
   resetMotorEncoder(frontLeftDrive);
   resetMotorEncoder(backRightDrive);
   resetMotorEncoder(backLeftDrive);

   if(axis == 'F'){
     while(getMotor)
     motor[port2] = power ;
     motor[port8] = power ;
   }

 }
 /*
  *main autonomous()
  */
 task autonomous(){

    // inititialize all motor to run with PID loop
    setPIDforMotor(liftMobileLowerLeft);
    setPIDforMotor(liftMobileLowerRight);
    setPIDforMotor(liftMobileHigherLeft);
    setPIDforMotor(liftMobileHigherRight);
    setPIDforMotor(liftConeLeft);
    setPIDforMotor(liftConeRight);
    setPIDforMotor(driveLeft);
    setPIDforMotor(driveRight);

 }
