/*
  *Author UNL vex U
  *Date feb 13th 2018
  *Version : 1.8
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

/* loop 1*/
   // initialize sensor  value
   SensorValue[leftEncoder] = 0;
   SensorValue[rightEncoder] = 0;
   frontMobileLift('D');
   innerMobileLift('D');

   while(SensorValue[mobleGoalHigher] != 0 &&
         getDistanceTraveled(SensorValue[rightEncoder] < 36 ){ // 36 5 blocks revlative to init distnave
     motor[rightDrive] = 100 ;
     motor[leftDrive]  = 100 ;
    }

    frontMobileLift('U');

    while(SensorValue[mobleGoalLower] != 0 &&
          getDistanceTraveled(SensorValue[rightEncoder] < 36 ){ // 36 5 blocks revlative to init distnave
      motor[rightDrive] = 100 ;
      motor[leftDrive]  = 100 ;
     }

     innerMobileLift('U');

     // lower front mobile lift // lower potential energy
     frontMobileLift('M');

    while(SensorValue[rightLine] != 1  || SensorValue[leftLine] != 1){
      motor[rightDrive] = 90;
      motor[leftDrive] = 90;
    }

    motor[rightDrive] = -5;
    motor[leftDrive] = -5;

    drive(DIST_FROM_LINE_SENSOR_TO_MIDPOINT,50 );
    SensorValue[leftEncoder] = 0;
    SensorValue[rightEncoder] = 0;

    rotate(900, 90);
    drive(17.68,80);
    SensorValue[leftEncoder] = 0;
    SensorValue[rightEncoder] = 0;
    rotate(-900,90);

    drive(21,110);
    innerMobileLift('D');

    while(SensorValue[rightLine] != 1  || SensorValue[leftLine] != 1){
      motor[rightDrive] = -90;
      motor[leftDrive] = -90;
    }

    /* TODO: adjust position alignment code go here*/

    /*Loop1 end here */

    /*Lopp 2 start */
    drive(DIST_FROM_LINE_SENSOR_TO_MIDPOINT,50 );// align robot mid pointer with the white line
    rotate(900,80);
    drive(17.68,80);
    rotate(900,80);

    // initialize sensor  value
    SensorValue[leftEncoder] = 0;
    SensorValue[rightEncoder] = 0;
    frontMobileLift('D');
    innerMobileLift('D');

    while(SensorValue[mobleGoalHigher] != 0 &&
          getDistanceTraveled(SensorValue[rightEncoder] < 36 ){ // 36 5 blocks revlative to init distnave
      motor[rightDrive] = 100 ;
      motor[leftDrive]  = 100 ;
     }

     frontMobileLift('U');

     while(SensorValue[mobleGoalLower] != 0 &&
           getDistanceTraveled(SensorValue[rightEncoder] < 36 ){ // 36 5 blocks revlative to init distnave
       motor[rightDrive] = 100 ;
       motor[leftDrive]  = 100 ;
      }

      innerMobileLift('U');

      // lower front mobile lift // lower potential energy
      frontMobileLift('M');

     while(SensorValue[rightLine] != 1  || SensorValue[leftLine] != 1){
       motor[rightDrive] = 90;
       motor[leftDrive] = 90;
     }

     motor[rightDrive] = -5;
     motor[leftDrive] = -5;

     drive(DIST_FROM_LINE_SENSOR_TO_MIDPOINT,50 );
     SensorValue[leftEncoder] = 0;
     SensorValue[rightEncoder] = 0;




  }




   /*
   pseudo:
        go back a certain distance .
        rotate CCW then align along the all.
        straight while inner bump sensor != 1 then go straight and scoop middle goal

   // alignment from adjusting both line sensor




 }
