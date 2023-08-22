#include <NewPing.h>
#include <Servo.h>



#define TRIGGER_PIN 10
#define ECHO_PIN 12
#define MAX_DISTANCE 400

void train();
float getResult(float, float);

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


Servo myservo;  // create servo object to control a servo

int pos = 0; // servo position


int frontMotor1pin1 = 2;
int frontMotor1pin2 = 3;

int frontMotor2pin1 = 4;
int frontMotor2pin2 = 5;

int rearMotor1pin1 = 6;
int rearMotor1pin2 = 7;

int rearMotor2pin1 = 8;
int rearMotor2pin2 = 9;

int speedControlPin = 11;



float distance;

void setup(){

    Serial.begin (9600);

    pinMode(frontMotor1pin1, OUTPUT);
    pinMode(frontMotor1pin2, OUTPUT);
    pinMode(frontMotor2pin1, OUTPUT);
    pinMode(frontMotor2pin2, OUTPUT);

    pinMode(rearMotor1pin1, OUTPUT);
    pinMode(rearMotor1pin2, OUTPUT);
    pinMode(rearMotor2pin1, OUTPUT);
    pinMode(rearMotor2pin2, OUTPUT);

    pinMode(speedControlPin, OUTPUT);

    myservo.attach(13);


    randomSeed(analogRead(53));

    train();
    

}

// servo 0 = right ahead
// servo 90 = straight 
// servo 180 = left

void loop(){


    int v1[2];

    float dir = 0;
    int obsDistance = 0.00;
    unsigned int distance = 0;

    delay(500);
    
    distance = ping();
    Serial.println(distance);
    
    /*if(distance >= 40){
      forward();
    }*/
    while(distance >= 40){
      distance = ping();
    }//drive forward as long as there is no obstacle
    stop();
    delay(500);

    lookLeft();
    delay(1500);
    obsDistance = 0;
    while(obsDistance == 0){
      obsDistance = ping();
      v1[0] = obsDistance; // add the distance to dist vector
    }
    lookRight();
    delay(1500);    
    obsDistance = 0;
    while(obsDistance == 0){
      obsDistance = ping();
      v1[1] = obsDistance;
    }

    lookStraight();
    delay(1500);

    dir = getResult(v1[0], v1[1]);
    Serial.println(dir);
    
    if(getResult > 0.5){
      leftTurn();
      delay(460);
    }
    else{
      rightTurn();
      delay(460);
    }

    /*if (v1[0] > v1[1]){
      leftTurn();
      delay(460);
    }
    else{
      rightTurn();
      delay(460);
    }

     stop();
     delay(500);*/
}

unsigned int ping(){

    delay(5);
    unsigned int uS = sonar.ping();
    pinMode(ECHO_PIN,OUTPUT);
    digitalWrite(ECHO_PIN,LOW);
    pinMode(ECHO_PIN,INPUT);
    uS = uS / US_ROUNDTRIP_CM;
    delay(5);
    return uS;
}

// Drive forward function
void forward(){

   analogWrite(speedControlPin, 150);
   digitalWrite(frontMotor1pin1, HIGH);
   digitalWrite(frontMotor1pin2, LOW);

   digitalWrite(frontMotor2pin1, HIGH);
   digitalWrite(frontMotor2pin2, LOW);
   
   digitalWrite(rearMotor1pin1, HIGH);
   digitalWrite(rearMotor1pin2, LOW);

   digitalWrite(rearMotor2pin1, HIGH);
   digitalWrite(rearMotor2pin2, LOW);

}

// Reverse function
void reverse(){

    //pins 2&3, back left
    digitalWrite(frontMotor1pin1, LOW);
    digitalWrite(frontMotor1pin2, HIGH);
    //pins 4&5, back right
    digitalWrite(frontMotor2pin1, LOW);
    digitalWrite(frontMotor2pin2, HIGH);
    //pins 6&7, front left
    digitalWrite(rearMotor1pin1, LOW);
    digitalWrite(rearMotor1pin2, HIGH);
    //pins 8&9, front right
    digitalWrite(rearMotor2pin1, LOW);
    digitalWrite(rearMotor2pin2, HIGH);
}

// Turn left function?
void leftTurn(){

    analogWrite(speedControlPin, 150);
    //pins 2&3, back left
    digitalWrite(frontMotor1pin1, LOW);
    digitalWrite(frontMotor1pin2, HIGH);
    //pins 4&5, back right
    digitalWrite(frontMotor2pin1, HIGH);
    digitalWrite(frontMotor2pin2, LOW);
    //pins 6&7, front left
    digitalWrite(rearMotor1pin1, LOW);
    digitalWrite(rearMotor1pin2, HIGH);
    //pins 8&9, front right
    digitalWrite(rearMotor2pin1, HIGH);
    digitalWrite(rearMotor2pin2, LOW);
}


// Turn right function?
void rightTurn(){

    analogWrite(speedControlPin, 150);
    //pins 2&3, back left
    digitalWrite(frontMotor1pin1, HIGH);
    digitalWrite(frontMotor1pin2, LOW);
    //pins 4&5, back right
    digitalWrite(frontMotor2pin1, LOW);
    digitalWrite(frontMotor2pin2, HIGH);
    //pins 6&7, front left
    digitalWrite(rearMotor1pin1, HIGH);
    digitalWrite(rearMotor1pin2, LOW);
    //pins 8&9, front right
    digitalWrite(rearMotor2pin1, LOW);
    digitalWrite(rearMotor2pin2, HIGH);
}

void stop(){
    //pins 2&3, back left
    digitalWrite(frontMotor1pin1, LOW);
    digitalWrite(frontMotor1pin2, LOW);
    //pins 4&5, back right
    digitalWrite(frontMotor2pin1, LOW);
    digitalWrite(frontMotor2pin2, LOW);
    //pins 6&7, front left
    digitalWrite(rearMotor1pin1, LOW);
    digitalWrite(rearMotor1pin2, LOW);
    //pins 8&9, front right
    digitalWrite(rearMotor2pin1, LOW);
    digitalWrite(rearMotor2pin2, LOW);
}

void lookLeft(){

  myservo.write(180);
}

void lookStraight(){

  myservo.write(90);

}

void lookRight(){

  myservo.write(0);

}