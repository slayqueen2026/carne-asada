#include <Servo.h>

Servo myservo;

// deja de usar el pin 9. Esta obstruido
int trigPinF = 11;    // frontal
int echoPinF = 12;    // frontal
int trigPinR = 13;    // right
int echoPinR = 14;    // right
int trigPinL = 8;    // left
int echoPinL = 10;    // left
long duration;

const int IN1 = 6;
const int IN2 = 4;
const int ENA = 5;

char side = ' ';
bool free_round = NULL;
short corners = 0;

bool run = false;

double Fdist = 300, Ldist = 300, Rdist = 300;

const int keyPin = 3; //the number of the key pin 12


void stop ()  //stop motors
{
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  ///coast - break - hold
}

void move (int speed)  //forward backward 255
{
  //return; //test line to avoid movement, comment this command "return"
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
  analogWrite(ENA,  abs(speed));
  if (speed >= 0)
      digitalWrite(IN1,  HIGH);
  else
      digitalWrite(IN2,  HIGH);
}

double dist (int pinT, int pinE)
{
  digitalWrite(pinT, LOW);
  delayMicroseconds(5);
  digitalWrite(pinT, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinT, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pinE, INPUT);
  duration = pulseIn(pinE, HIGH);
 
  // Convert the time into a distance
  return (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
}
 
 void turn(char opts)
{
  corners++;
  if (opts == 'l')
     myservo.write(40);
  else if (opts == 'r')
     myservo.write(140);
  else
     myservo.write(90);
  delay(500);
}

void setup() {
  Serial.begin (9600);
  pinMode(trigPinF, OUTPUT);// frontal
  pinMode(echoPinF, INPUT);// frontal

  pinMode(trigPinR, OUTPUT);// right
  pinMode(echoPinR, INPUT);// right

  pinMode(trigPinL, OUTPUT);// left
  pinMode(echoPinL, INPUT);// left

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);

  myservo.attach(7);//attachs the servo on pin 7 to servo object
  myservo.write(90);//back to 0 degrees

  pinMode(keyPin,INPUT);//initialize the key pin as inp
}
 
void loop() {

  while (!run)
  {
   // run = DigitalRead(bpin    
    stop();
    if(digitalRead(keyPin) ==HIGH )
      {
        run = true; //validate the starting button
      }
      Serial.write("\nWaiting button...");
  }
  run = false;
  delay(500);

  Ldist = dist(trigPinL, echoPinL);
  Rdist = dist(trigPinR, echoPinR);
  Fdist = dist(trigPinF, echoPinF);
  Serial.println("L");
  Serial.println(Ldist);
  Serial.println(Rdist);
  Serial.println(Fdist);

  if (Ldist < 30 || Rdist < 30)
    {
      free_round = true;
    }

  if (free_round)
    Serial.write("\n - Free Round");
  else
    Serial.write("\n - Not sure...");

  move(100);

  while (Fdist > 50)
    {
      Fdist = dist(trigPinF, echoPinF);
    }

  //stop();
  Ldist = dist(trigPinL, echoPinL);
  side = (Ldist > 300? 'l': 'r');
  turn(side);
  delay(230);
  turn('c');
  int base_delay = 125;
  while (corners <= 11)
  {
    //move(100);
    Fdist = dist(trigPinF, echoPinF);
    if (Fdist < 50)
    {
      turn(side);
      delay(base_delay);
      base_delay*=(4/5);
      turn('c');
    }
   
  }
  if (corners >= 12 )
    stop();

}