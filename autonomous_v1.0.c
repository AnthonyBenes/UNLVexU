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
  motor[port2] = 0; //right
  motor[port8] = 0; // left
}

/*
 *this function will rotate the robot
 *@parameter (char axis(L,C,R), int degree, int powe)
 *
            |-------|
             |     |
             |  C  |
             |     |
            |-------|
EX: rotate('C',200,50);
  The robot will rotate at the C axis by 200 degrees(CW)
  with 50 power.

EX: rotate('C',-100,100);
  The robot will rotate at the C axis by 100 degrees(CCW)
  with 100 power.
  *
  */
 void rotate(char axis, int power){//

   // initilize motor at 0 ticks.
   resetMotorEncoder(frontRightDrive);
   resetMotorEncoder(frontLeftDrive);
   resetMotorEncoder(backRightDrive);
   resetMotorEncoder(backLeftDrive);

   if(axis == 'C'){
     motor[port2] = power ; // left
     motor[port8] = -power ;// right
   }else if(axis == 'L'){
     motor[port2] = -power ; // left
     motor[port8] = 0 ;// right
   }else if(axis == 'R'){
     motor[port2] = power ; // left
     motor[port8] = 0 ;// right
   }


 }

/**
 *this function actiavate front motor lift.
 *@parameter char position, 'L' (low) 'M'(middle) 'H'(high)
 *return void
 *Ex: frontMobileLift('M');
 * this function will activate the motor to lift up the mobile joint. to the middle
 * position.
 */
 void frontMobileLift(char position){
   if(position == 'H'){

   }
 }

 /**
  *innerMobileLift(char position)
  *@parameter 'U' up, 'D' Down
  *return void
  */
  void innerMobileLift(char position){
        //reset encoder for motor on both side
    resetMotorEncoder(liftMobileLowerRight);
    resetMotorEncoder(liftMobileLowerLeft);

    if(position == 'U'){
      while(getMotorEncoder(liftMobileLowerRight) < TICKGOAL_PLACEHOLDER){
        motor[liftMobileLowerLeft] = power ; // replace power with a number
        motor[liftMolbileLowerRight] = power ; // replace power with a number
      }
    }else if(position == 'D'){
      while(getMotorEncoder(liftMobileLowerRight)){
        motor[liftMobileLowerLeft] = -power ; // replace power with a number
        motor[liftMolbileLowerRight] = -power ; // replace power with a number
      }else{
        // error from programmer
      }
    }
  }// end innerMobileLift
  
 task autonomous(){

    // inititialize all motor to run with PID loop
    setPIDforMotor(liftMobileLowerLeft,true);
    setPIDforMotor(liftMobileLowerRight,true);

    setPIDforMotor(driveLeft,true);
    setPIDforMotor(driveRight,true);

    rotate('R',100);
    wait()

 }
