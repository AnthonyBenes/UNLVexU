/*
  *Author UNL vex U
  *Date feb 2nd 2018
  *Version : 1.0
  *Note:
  *need to be Add:
  *INCH_PER_TICK, TICK_PER_INCH,WHEEL_DIAMETER,.
  *edit: innerMobileLift() function
        rotate() function
        frontMobileLift() idea . have the potentiometer change to encoder motor

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
  SensorValue[leftEncoder] = 0;
  SensorValue[rightEncoder] = 0;

  // go to requested ticks.
  while(SensorValue[leftEncoder] < tickGoal){
    motor[leftDrive] = power ;
    motor[rightDrive] = power ;
  }
}

/*
 *this function will rotate the robot
 *@parameter (char axis(L,C,R), int degree, int powe)
 *
            |--------|
             |      |
             |  CM  |
             |      |
            |--------|
EX: rotate('C',200,50);
  The robot will rotate at the C axis by 200 degrees(CW)
  with 50 power.

EX: rotate('C',-100,100);
  The robot will rotate at the C axis by 100 degrees(CCW)
  with 100 power.
  *
  */
 void rotate(int degree,int power){//

   // start encoder count at 0
   SensorValue[leftEncoder] = 0;
   SensorValue[rightEncoder] = 0;




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
   int value = sensor(rightLine);
   if(position == 'L'){
     if(sensorValue(liftAngleRight) != -240 ){
       if(value > -240){
         motor[liftMobileHigherLeft] = -63;
        motor[liftMobileHigherRight] = -63;
      }else if(value < -240){
        motor[liftMobileHigherLeft] = 63;
        motor[liftMobileHigherRight] =63;
      }else{
        stopMotor(liftMobileHigherLeft);
        stopMotor(liftMobileHigherRight);
      }
     }
   }else if(position == 'H'){
     if(sensorValue(liftAngleRight) != 1200 ){
       if(value > 1200){
         motor[liftMobileHigherLeft] = -63;
        motor[liftMobileHigherRight] = -63;
      }else if(value < 1200){
        motor[liftMobileHigherLeft] = 63;
        motor[liftMobileHigherRight] =63;
      }else{
        stopMotor(liftMobileHigherLeft);
        stopMotor(liftMobileHigherRight);
      }
     }
   }
 }

 /**
  *innerMobileLift(char position)
  *@parameter 'U' up, 'D' Down
  *return void
  *This function need to be edit. we are planning put limit switch instead of
  *using encoder to stop the inner lift motor
  *
  */
  void innerMobileLift(char position){
        //reset encoder for motor on both side
    resetMotorEncoder(liftMobileLowerRight);
    resetMotorEncoder(liftMobileLowerLeft);

    if(position == 'U'){
      while(getMotorEncoder(liftMobileLowerRight) != 1250){ //  planning to change it to bumper switch to detect.
        if(getMotorEncoder(liftMobileLowerRight) > 1250){
        motor[liftMobileLowerLeft] = 50 ; // replace power with a number
        motor[liftMolbileLowerRight] = 50 ; // replace power with a number
      }else if(getMotorEncoder(liftMobileLowerRight) < 1250){
        motor[liftMobileLowerLeft] = -50 ; // replace power with a number
        motor[liftMolbileLowerRight] = -50 ; // replace power with a number
      }else{
        stopMotor(liftMolbileLowerRight);
        stopMotor(liftMobileLowerLeft;
      }
    }else if(position == 'D'){
      while(getMotorEncoder(liftMobileLowerRight) != 100 ){
        if(getMotorEncoder(liftMobileLowerRight) > 100){
        motor[liftMobileLowerLeft] = 50 ; // replace power with a number
        motor[liftMolbileLowerRight] = 50 ; // replace power with a number
      }else if(getMotorEncoder(liftMobileLowerRight) < 100){
        motor[liftMobileLowerLeft] = -50 ; // replace power with a number
        motor[liftMolbileLowerRight] = -50 ; // replace power with a number
      }else{
        stopMotor(liftMolbileLowerRight);
        stopMotor(liftMobileLowerLeft;
      }
      }else{
        // error from programmer
      }
    }
  }// end innerMobileLift

  /*
   *This function activate the cone lift position.
   * as well as the pneumatic lift
   * @parameter char jointPos('R'(ready),'L'(lift),
   *'LL'(local load),'R'(rest), bool extender . true = out. false = in .
   */
  void coneJoint(char jointPos, bool extender){
    if(jointPos == 'R'){

    }else if (jointPos == 'L'){

    }else if(jointPos == '')
  }

 task autonomous(){
 }
