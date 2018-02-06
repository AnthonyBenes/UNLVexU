/*
*Author VEX
*Date: feb 2nd 2018
*version 1.2
*
*this .c extension file contain executable void funtion for mobileMode

*/

// User control code here, inside the loop
void mobileMode(){

  /*
  Lift Program
  This controls the 3 lift systems
  They will be split into 2 sections, the Mobile Goal Lifts and the Cone Lift
  */
  //Set Mobile Higher or Lower
  if(vexRT[Btn8U] == 1){
    mobileLowerIfTrue = true;
  }
  else if(vexRT[Btn8L] == 1){
    mobileLowerIfTrue = false;
  }
  //Mobile Goal Lift
  /*if(vexRT[Btn5U] == 1){
  //if(mobileLowerIfTrue && SensorValue[mobileLowerAngle] < 3600){

  //}
  else if(SensorValue[mobileHigherAngle] < 3600){
  motor[liftMobileHigherLeft] = 127;
  motor[liftMobileHigherRight] = 127;
  }
  motor[liftMobileLowerLeft] = 127;
  motor[liftMobileLowerRight] = 127;
  }
  else if(vexRT[Btn5D] == 1){
  if(mobileLowerIfTrue && SensorValue[mobileLowerAngle] > 360){
  motor[liftMobileLowerLeft] = -67;
  motor[liftMobileLowerRight] = -67;
  }
  else if(SensorValue[mobileHigherAngle] > 360){
  motor[liftMobileHigherLeft] = -67;
  motor[liftMobileHigherRight] = -67;
  }
  }
  else{
  motor[liftMobileLowerLeft] = 0;
  motor[liftMobileLowerRight] = 0;
  motor[liftMobileHigherLeft] = 0;
  motor[liftMobileHigherRight] = 0;
  }*/

  //low lift
  if(vexRT[Btn5U]){
    while(SensorValue[mobileLowerAngle] < 3100){
      //goes up
      motor[liftMobileLowerLeft] = 127;
      motor[liftMobileLowerRight] = 127;
    }
    }else if(vexRT[Btn5D]){
    while(SensorValue[mobileLowerAngle] > 2500){
      //goes down
      motor[liftMobileLowerLeft] = -127;
      motor[liftMobileLowerRight] = -127;
    }
    }else{
    motor[liftMobileLowerLeft] = 0;
    motor[liftMobileLowerRight] = 0;
  }// enc low lift



  //High lift
  if(vexRT[Btn6U]){
    //while(SensorValue[mobileHigherAngle] < 4100){
    //goes up
    motor[liftMobileHigherLeft] = 127;
    motor[liftMobileHigherRight] = 127;
    //}
    }else if(vexRT[Btn6D]){
    //while(SensorValue[mobileHigherAngle] > 700){
    //goes down
    motor[liftMobileHigherLeft] = -127;
    motor[liftMobileHigherRight] = -127;
    //	}
    }else{
    motor[liftMobileHigherLeft] = 0;
    motor[liftMobileHigherRight] = 0;
  }



  /*Cone Lift
  if(vexRT[Btn6U] == 1 && SensorValue[mobileHigherAngle] < 3600){
  motor[liftConeLeft] = 127;
  motor[liftConeRight] = 127;
  }
  else if(vexRT[Btn6D] == 1 && SensorValue[mobileHigherAngle] > 360){
  motor[liftConeLeft] = -127;
  motor[liftConeRight] = -127;
  }
  else{
  motor[liftConeLeft] = 0;
  motor[liftConeRight] = 0;
  }*/


} // end pneumatic lift systems


}// end void main .
