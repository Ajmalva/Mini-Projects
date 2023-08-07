//mpile it to your Arduino.
// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //
#include <Servo.h>

Servo myservo;
Servo myserv;
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPinz 4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPinz 5 //attach pin D3 Arduino to pin Trig of HC-SR04


// defines variables
long duration; // variable for the duration of sound wave travel
long durationz; // variable for the duration of sound wave travel

int distance; // variable for the distance measurement
int distancedwn; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  
  pinMode(trigPinz, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPinz, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
   myservo.attach(9);
    myservo.write(0);
   myserv.attach(10);
    myserv.write(0);
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Clears the trigPin condition
  digitalWrite(trigPinz, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPinz, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinz, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationz = pulseIn(echoPinz, HIGH);
  // Calculating the distance
    distancedwn = durationz * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  // Displays the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.print(distance);
//  Serial.println(" cm");
//  Serial.print("Distance: ");
//  Serial.print(distancedwn);
//  Serial.println(" cm");


  if(distancedwn < 10)
  {
    Serial.println("one");
    myservo.write(0);
   delay(100);
    myservo.write(20);
    delay(100);
    myservo.write(0);
    delay(100);
//    //jump
    }
//     else
//    {
//      Serial.print("\t Normal");
//    }
     
    if(distance < 10)
  {
    Serial.println("two");
    myserv.write(0);
   delay(100);
    myserv.write(15);
    delay(100);
    myserv.write(0);
    delay(100);
    //duck
    }
//    else
//    {
//      Serial.print("\t Normal");
//    }
//    Serial.print("\n");
}
