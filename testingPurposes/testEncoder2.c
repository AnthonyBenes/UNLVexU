/*
*Author(@Dat Nguuyen)
*Date ( jan 29th, 2018)
*
*this program test the encoder
*/

#define diameter

task main(){

  // find the circumference of the wheel
    float diameter = diameter ;
    float circumference = diameter * PI;

    int distanceToGo = 12; // 12 inches
    float rotations = distanceToGo/circumference;
    int degreesToTurn = rotation * 360 ;

    // start motor encoder count at 0
    nMotorEncoder[motorB] = 0;
    // tell the motor how many encoder counts// degrees to turn
    nMotorEncoderTarget[motorB] = degrees ;
    motor[motorB] = 100 ;
    motor[motorC] = 100 ;

    // now we need to check when motorB is finish
    while(nMotorRunState[motorB] != runStateIdle){
      // do nothing here while waiting
    }// end while

    motor [motorB] = 0 ; // turn off the motor
    motor [motorB] = 0 ;
}
