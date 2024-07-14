//#include <gpio_viewer.h>
//GPIOViewer gpio_viewer;

#define TRIGGER_PIN 23  // Pin for triggering the ultrasonic sensors
#define ECHO_PIN1 5   // Pin for echo of sensor 1
#define ECHO_PIN2 18   // Pin for echo of sensor 2
#define ECHO_PIN3 19   // Pin for echo of sensor 3
int distance1, distance2, distance3;
//global variables to store the values if ultrasonic sensors from readUltrasonic loop

// ir sensors following the quadrant locations
#define IR_PIN1 26
#define IR_PIN2 27
#define IR_PIN3 35
#define IR_PIN4 25

const int leftMotorForward = 15;  // Pin for left motor forward
const int leftMotorBackward = 2; // Pin for left motor backward
const int rightMotorForward = 13; // Pin for right motor forward
const int rightMotorBackward = 12; // Pin for right motor backward
const int speedPin = 14;   // Pin for speed control (ENA)


void setup() {
 // gpio_viewer.connectToWifi("samsung Galaxy", "Your WiFi Password");
  //gpio_viewer.begin();
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(ECHO_PIN3, INPUT);

  pinMode(IR_PIN1, INPUT);
  pinMode(IR_PIN2, INPUT);
  pinMode(IR_PIN3, INPUT);
  pinMode(IR_PIN4, INPUT);

  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(speedPin, OUTPUT);  
}

void loop() {
  int sensor[4];
  readIr(sensor);
  edgeAvoidance();
  readUltrasonic();
  
  if(distance1 && distance2 && distance3){
    
  }
  if(distance1 && distance2 && distance3){
    
  }
  if(distance1 && distance2 && distance3){
    
  }
}

void readUltrasonic() {
  // Trigger the sensors one by one
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Read the echo pins separately
  int duration1 = pulseIn(ECHO_PIN1, HIGH);
  int duration2 = pulseIn(ECHO_PIN2, HIGH);
  int duration3 = pulseIn(ECHO_PIN3, HIGH);

  // Calculate the distances
  distance1 = duration1 * 0.034 / 2;
  distance2 = duration2 * 0.034 / 2;
  distance3 = duration3 * 0.034 / 2;
}

void readIr(int sensor[4]) {
  sensor[0] = digitalRead(IR_PIN1);
  sensor[1] = digitalRead(IR_PIN2);
  sensor[2] = digitalRead(IR_PIN3);
  sensor[3] = digitalRead(IR_PIN4);
}


void linefollow(){
  int sensor[4];
  readIr(sensor);
   if(sensor[0] ==HIGH && sensor[1] ==HIGH){
     frontgo();
    }
   if(sensor[0]== HIGH && sensor[1]== LOW){
     turnLeft();
     delay(3000);
    }
    if(sensor[0]==HIGH && sensor[1]== LOW){
      turnRight();
      delay(3000);
    }
    if(sensor[0]== LOW && sensor[1] == LOW){
      stopMotors();
    }
}

void edgeAvoidance() {
  int sensor[4];
  readIr(sensor);
  if (sensor[0] == HIGH && sensor[1] == HIGH && sensor[2] == HIGH && sensor[3] == HIGH){frontgo();}
  else if (sensor[0] == HIGH && sensor[1] == LOW && sensor[2] == HIGH && sensor[3] == HIGH) { // Top-left edge detected
    turnRight();
  } else if (sensor[1] == HIGH && sensor[0] == LOW && sensor[2] == HIGH && sensor[3] == HIGH) { // Top-right edge detected
    turnLeft();
  } else if (sensor[0] == HIGH && sensor[1] == HIGH && sensor[2] == LOW && sensor[3] == HIGH ) { // Bottom-left edge detected
    frontgo();
    delay(100);
    turnLeft();
  } else if (sensor[0] == HIGH && sensor[1] == HIGH && sensor[2] == HIGH && sensor[3] == LOW) { // Bottom-right edge detected
    turnLeft();
  } else{
    stopMotors();
  }
  delay(50);
}


//______________________________________________________
void frontgo(){
  // Set the speed of the motors (0-255)
  analogWrite(speedPin, 128);

  // Move the motors forward
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}
void turnRight(){
  // Set the speed of the motors (0-255)
  analogWrite(speedPin, 128);

  // Turn right
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}
void turnLeft(){
  // Set the speed of the motors (0-255)
  analogWrite(speedPin, 128);

  // Turn left
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
}
void stopMotors(){
  // Stop the motors
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}
void backgo(){
  // backward motion of the motors
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}