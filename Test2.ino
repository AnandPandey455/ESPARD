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
  int sens4 = digitalRead(IR_PIN4);
  int sens3 = digitalRead(IR_PIN3);
  int sens2 = digitalRead(IR_PIN2);
  int sens1 = digitalRead(IR_PIN1);
  
  if(sens1== HIGH ){
      analogWrite(speedPin, 128);
     // Move the motors forward
     digitalWrite(leftMotorForward, HIGH);
  }
}