#define trigPin 10
#define echoPin 13
#include <Servo.h>

Servo myservo;

int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo.attach(A0);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  for(pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);

    digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.print(" cm, Position = ");
    Serial.println(pos);
    delay(150);
  }
  delay(150);
  }

  for(pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);

    digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.print(" cm, Position = ");
    Serial.println(pos);
    delay(150);
  }
  delay(150);
  }
}
