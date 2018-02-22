
#include <driveFunction.h>
void drive(float inch,int power){

  double rev = (inch + 7.5) / circumference ;
  double tickGoal = rev * TICK_PER_REV;


  // go to requested ticks.
  while(abs(SensorValue[leftEncoder]) < abs(tickGoal)){
    motor[leftDrive] = power ;
    motor[rightDrive] = power ;
  }
}

 void rotate(int degree,int power){//

   // declare variables
   double theta = 0 ;
   double distanceTravel = 0 ;
   int tickGoal =0 ;
   int diff;
   // start encodr count at 0
   SensorValue[gyro] = 0;

   if(SensorValue[gyro] < degree){// spin CW
     while(SensorValue[gyro] < degree){
       diff = abs(SensorValue[gyro] - (degree * 10) );
       if(diff < 200){// if the difference between requested and current degree are 40 then slow down
         motor[leftDrive] = -(power - 5);
         motor[rightDrive] = (power - 5);
       }else{
         motor[leftMotor] = -power;
         motor[rightMotor] = power;
       }
     }
   }else if(SensorValue[gyro] > degree){ // if degree is negativen // then rotate CCW
     while(SensorValue[gyro] > degree){
       diff = abs(SensorValue[gyro] - degree);
       if(diff < 200){// if the difference between requested and current degree are 40 then slow down
         motor[leftDrive] = (power - 5);
         motor[rightDrive] = -(power - 5);
       }else{
         motor[leftMotor] = power;
         motor[rightMotor] = -power;
       }
   }
  }


  void coneJoint(char jointPos, bool extender){
    if(jointPos == 'R'){

    }else if (jointPos == 'L'){

    }else if(jointPos == '')
  }

 void frontMobileLift(char position){
   int value = sensor(rightLine);
   if(position == 'L'){
     while(sensorValue(liftAngleRight) != -240 ){
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
     while(sensorValue(liftAngleRight) != 1200 ){
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


   double getDistanceTraveled(int tick){
    return ((double)tick /TICK_PER_REV) * circumference) ;
   }
