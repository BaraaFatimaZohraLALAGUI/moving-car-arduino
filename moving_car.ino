#include <Servo.h>


// defining the motors (they are linked to the driver)
int left_motor1 = 3; // left avant
int right_motor1 = 5; // right avant
int left_motor2 = 6; // left arriere
int right_motor2 = 9; // right arriere

// defining servomotor and ultrasonic sensor
int echopin = A0;
int trigpin = A1;
int motor = 10;

int start = 103;

// variables
char value; // character you read from bluetooth controller
int distance; // the distance the ultrasonic sensor detects

int left;
int right;
int L = 0;
int R = 0;

Servo servo;


void setup() {
  Serial.begin(9600);
  
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, OUTPUT);
  servo.attach(motor);

  pinMode(left_motor1, OUTPUT);
  pinMode(right_motor1, OUTPUT);
  pinMode(left_motor2, OUTPUT);
  pinMode(right_motor2, OUTPUT);
    
}

void loop() {
  digitalWrite(left_motor1,HIGH);
  digitalWrite(right_motor1,LOW);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor2,LOW);
  delay(1000);

  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor2,LOW);
  delay(1000);

  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(left_motor2,HIGH);
  digitalWrite(right_motor2,LOW);
  delay(1000);

  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor2,HIGH);
  delay(1000);    
}


 
void backward()
{
  digitalWrite(left_motor1,HIGH);
  digitalWrite(right_motor1,LOW);
  digitalWrite(left_motor2,HIGH);
  digitalWrite(right_motor2,LOW);
}
 void forward()
{
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor2,HIGH);
}
 void stop()
{
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor2,LOW);
}
int moveleft()
{
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor2,HIGH);
}
int moveright()
{
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor2,LOW);
}


void obstacle(){
  distance = sense();
  if (distance <= 12){
    stop();
    backward();
    delay(100);
    stop();
    L = leftsee();
    delay(800);
    R = rightsee();
    if( L < R){
      moveright();
      delay(500);
      stop();
      delay(200);
    } else if (L > R){
      moveleft();
      delay(500);
      stop();
      delay(200);
    }
  } else {
      forward();
  }
}

int rightsee() {
  servo.write(20);
  delay(800);
  left = sense();
  servo.write(start);
  return left;
}
int leftsee() {
  servo.write(180);
  delay(800);
  right = sense();
  servo.write(start); // putting back the servomotor to its initial degree (sensor centering)
  return right;
}

int sense() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  long t = pulseIn(echopin, HIGH);
  long cm = t / 29 / 2; //time convert distance
  return cm;
}



// void voicecontrol() {
//   if (Serial.available() > 0) {
//     value = Serial.read();
//     Serial.println(value);
//     if (value == '^') {
//       forward();
//     } else if (value == '-') {
//       backward();
//     } else if (value == '<') {
//       L = leftsee();
//       servo.write(start);
//       if (L >= 10 ) {
//         left();
//         delay(500);
//         stop();
//       } else if (L < 10) {
//         stop();
//       }
//     } else if (value == '>') {
//       R = rightsee();
//       servo.write(start);
//       if (R >= 10 ) {
//         right();
//         delay(500);
//         stop();
//       } else if (R < 10) {
//         stop();
//       }
//     } else if (value == '*') {
//       stop();
//     }
//   }
// }