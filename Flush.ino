#include <Servo.h>
int LED = 13; // Use the onboard Uno LED
int isObstaclePin = 2;  // This is our input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE
int servoPin = 3;
Servo Servo1;
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293

void smallFlush()
{
  tone(8, 2000);
  delay(300);
  Servo1.write(120);
  Serial.println("Opening");
  delay(500);
  noTone(8);
  delay(1500);        // ...for 1 sec
  Servo1.write(-120);
  Serial.println("Closing");
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void bigFlush()
{
  tone(8, 2000);
  delay(300);
  Servo1.write(90);
  Serial.println("Opening");
  delay(500);
  noTone(8);
  delay(300);
  tone(8, 2000);
  delay(500);
  noTone(8);
  delay(5000);     
  Serial.println("Closing");
  Servo1.write(-90);
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
  Servo1.attach(servoPin);
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
    delay (1000);
    isObstacle = digitalRead(isObstaclePin);
    if (isObstacle == LOW)
    {
      delay (4000);
      isObstacle = digitalRead(isObstaclePin);
      if (isObstacle == HIGH)
      {
        Serial.println("clear");
        smallFlush();
      }
      else
      {
        while ( digitalRead(isObstaclePin) == LOW )
        {
          Serial.println("OBSTACLE!!, OBSTACLE!!");
        }
        bigFlush();
      }
    }
  }
  else
  {
    Serial.println("clear");
    digitalWrite(LED, LOW);
    delay (500);
  }
}
