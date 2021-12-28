#include <Servo.h>

//edit config values below to match desired servo paramaters

//Kneck Servo Config
Servo kneckServo;
int kneckPin = 9; // servo pin number of arduino board
int kneckPos = 0; // resting angualar position of servo
int kneckMin = 0; // min angular position of servo
int kneckMax = 180; // max angular position of servo
int kneckPeriod = 5; //time that servo will take to turn from min angle to max angle

//Left Arm Servo Config
Servo larmServo;
int larmPin = 10;
int larmPos = 0;
int larmMin = 0;
int larmMax = 180;
int larmPeriod = 5;

//Right Arm Servo Config
Servo rarmServo;
int rarmPin = 11;
int rarmPos = 0;
int rarmMin = 0;
int rarmMax = 180;
int rarmPeriod = 5;

//Hip Servo Config
Servo hipServo;
int hipPin = 12;
int hipPos = 0;
int hipMin = 0;
int hipMax = 180;
int hipPeriod = 5;

//Left Leg Servo Config
Servo llegServo;
int llegPin = 13;
int llegPos = 0;
int llegMin = 0;
int llegMax = 180;
int llegPeriod = 5;

//Right Leg Servo Config
Servo rlegServo;
int rlegPin = 14;
int rlegPos = 0;
int rlegMin = 0;
int rlegMax = 180;
int rlegPeriod = 5;


//end of user configurable code

//init array of servo paramaters
int servoParam[5][3] = {{kneckPos, kneckMin, kneckMax, kneckPeriod},{larmPos, larmMin, larmMax, larmPeriod},{rarmPos, rarmMin, rarmMax, rarmPeriod},
{hipPos, hipMin, hipMax, hipPeriod},{llegPos, llegMin, llegMax, llegPeriod},{rlegPos, rlegMin, rlegMax, rlegPeriod};
string servo[5] = {kneckServo, larmServo, rarmServo, hipServo, llegServo, rlegServo};

//init time counter

long time = 0;

void setup() {
  //attaches servos to pins as defined above
  kneckServo.attach(kneckPin);
  larmServo.attach(larmPin);
  rarmServo.attach(rarmPin);
  hipServo.attach(hipPin);
  llegServo.attach(llegPin);
  rlegServo.attach(rlegPin);
  //sets servos to default position
  for(int i=0; i<5; i++)
    {
      servo[i].write(servoParam[i][0])
    }
}


void loop() {

  for(int i=0; i<5; i++)
    {
      for{int j=0; j<3; j++}
        {
          servo[i].write(servoParam[i][j])
        }
    }

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
