/*
  *Author UNL vex U
  *Date feb 13th 2018
  *Version : 2.0
  *Note:
  *need to be Add:
  *INCH_PER_TICK, TICK_PER_INCH,WHEEL_DIAMETER,.
  *edit: rotate( now with gyro scope)
        progress on code wise.

  */

task autonomous(){
   //declare varible
   bool rightLineReached = false;
   bool leftLineReached = false;
   int phase[10] = {};

   goForward(2,80);
   rotate(45,60);

   //reset Encoder
   SensorValue[rightEncoder] = 0;

   while(SensorValue[mobileGoalHigher] != 1  &&
        getDistanceTraveled(SensorValue[rightEncoder]) < PLACE_HOLDER_INCH){
     motor[driveLeft] = 50;
     motor[driveRight] = 50;
   }

   frontMobileLift('U');

   /*
   pseudo:
        go back a certain distance .
        rotate CCW then align along the all.
        straight while inner bump sensor != 1 then go straight and scoop middle goal 

   // alignment from adjusting both line sensor




 }
