

/*
 *This function convert distance request the robot to travel
 *to number of ticks
 * @ parameter ( float inch, int power of motor)
 * EX: goForward(2.8, 50);
 * Go foward 28 inches with 50 power of the motor.
 */
void goForward(float inch,int power);


  /**
  *This function rotate the robot relative to where the axis of the robot orientation
  *void rotate(int degree, int power)
  *@parameter degree - degree to turn relative to front of robot [0,3600]
  *                    power - rate of Turn
  *void
  *example: rotate(-30,100);// the bot will turn 30 degree CW with 100 powe
  */

void rotate(int degree, int power);

  /**
  *this function actiavate front motor lift.
  *@parameter char position, 'L' (low) 'M'(middle) 'H'(high)
  *return void
  *Ex: frontMobileLift('M');
  * this function will activate the motor to lift up the mobile joint. to the middle
  * position.
  */
void frontMobileLift(char position);

  /**
  *innerMobileLift(char position)
  *@parameter 'U' up, 'D' Down
  *return void
  *This function need to be edit. we are planning put limit switch instead of
  *using encoder to stop the inner lift motor
  *
  */
void innerMobileLift(char position);

  /*
  *This function activate the cone lift position.
  * as well as the pneumatic lift
  * @parameter char jointPos('R'(ready),'L'(lift),
  *'LL'(local load),'R'(rest), bool extender . true = out. false = in
  ***** This is a WOP function, need to be edit and modifi. .
  */
void coneJoint(char jointPos, bool extender);

  /**
   *This function convert number of ticks to distance traveled .
   *relative to the current position of the wheel axis
   *double getDistanceTraveled(int tick);
   *@parameter int tick (number of tick that you would like to convert)
   *return double distanceTraveled
   */
double getDistanceTraveled(int tick)
