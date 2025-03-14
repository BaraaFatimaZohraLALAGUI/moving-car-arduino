

// defining the motors (they are linked to the driver)
int left_motor1 = 3; // left avant
int right_motor1 = 5; // right avant
int left_motor2 = 6; // left arriere
int right_motor2 = 9; // right arriere


void setup() {
  Serial.begin(9600);

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
    
}

