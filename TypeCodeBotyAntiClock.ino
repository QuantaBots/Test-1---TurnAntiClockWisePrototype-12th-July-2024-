// Define ultrasonic sensor pins
const int trigPin = 3;
const int echoPin = 4;
#include <Servo.h>
int count = 0;
int count2 = 0;
Servo servo_pin_2;
#include <Wire.h>
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  count=0;
  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo_pin_2.attach(2);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  servo_pin_2.write( 48 );
  
  digitalWrite( 6 , LOW );
  digitalWrite( 7 , HIGH );
  digitalWrite( 8 , HIGH );
  digitalWrite( 9 , LOW );
}

void loop() {
  // Trigger ultrasonic sensor to send out a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse received by the echo pin
  long duration = pulseIn(echoPin, HIGH);
                                 
  // Convert the pulse duration to distance (in centimeters)
  // Speed of sound in air is approximately 343 meters per second or 0.0343 centimeters per microsecond
  // Divide by 2 because the pulse travels to the object and back
  float distance_cm = duration * 0.0343 / 2;
  
  // Limit the measured distance to a maximum of 500 cm
  distance_cm = min(distance_cm, 500.0);
  
  
  // Wait a short time before taking the next measurement
  //delay(500);
  if (( ( distance_cm < 30 ) && ( distance_cm > 25 ) )) {
    servo_pin_2.write( 56 );
    delay(400);
  }
  if (( ( distance_cm < 35 ) && ( distance_cm > 30 ) )) {
    servo_pin_2.write( 64 );
    delay(400);
  }
  if (( ( distance_cm < 40 ) && ( distance_cm > 35 ) )) {
    servo_pin_2.write( 72 );
    delay(400);
  }
  if (( ( distance_cm > 35 ) )) {
    servo_pin_2.write( 80 );
    delay(2500);
    count = ( count + 1 );
  }
  Serial.println(count2);
  if ((distance_cm <= 40 && distance_cm >= 25)){

    servo_pin_2.write( 48 );
  }
  if (( distance_cm <  25 && distance_cm >= 20 ))
  { 
    
    servo_pin_2.write( 40 );
    delay(300);
    servo_pin_2.write( 48 );
  }
  if (( distance_cm < 20 && distance_cm >= 15 ))
  { 
    
    servo_pin_2.write( 35 );
    delay(300);
    servo_pin_2.write( 48 );
  }
  if (( distance_cm < 15  ))
  { 
    
    servo_pin_2.write( 30 );
    delay(300);
    servo_pin_2.write( 48 );
  }
  if(count >= 8)
  {
    servo_pin_2.write(80);
    delay(1500);
    digitalWrite(13, HIGH);
  digitalWrite( 7 , HIGH );
  digitalWrite( 6 , HIGH );
  digitalWrite( 9 , HIGH );
  digitalWrite( 8 , HIGH );
    servo_pin_2.write(48);  
  }
  delay(40);
  
}
