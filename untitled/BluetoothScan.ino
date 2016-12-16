#define trigPin 11
#define echoPin 12
char val;
//Right motor = enable A
int enA = 10;
int in1 = 9;
int in2 = 8;

//Left motor = enable B
int enB = 5;
int in3 = 7;
int in4 = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  if(Serial.available())
  {
    val = Serial.read();
  }

  //Standard Ping
  if(val == 'P')
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) * 0.0344;

    if (distance >= 400 || distance <= 2)
    {
    Serial.print("Distance = ");
    Serial.println("Out of range");
    }
    else {
    Serial.print("Distance = ");
    Serial.println(distance);
    delay(150);
    }
    delay(1500);
  }

  else if(val == 'O')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    start = 0;
  }
  //Performs sweep, rotates cart and scans
  else if(val == 'S')
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // set speed to 200 out of possible range 0~255
    analogWrite(enA, 225);
    // turn on motor B
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // set speed to 200 out of possible range 0~255
    analogWrite(enB, 225);

    //start sensor ping
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) * 0.0344;

    //delay(150);
    if (distance >= 400 || distance <= 2)
    {
      Serial.println(-1, DEC);
    }
    else {
      Serial.println(distance, DEC);
      //delay(150);
    }
    //delay(1500);
    //delay(150);
    // now change motor directions
    
    
    //delay(8100);
  }
  /*
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 225);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 225);
  delay(2000);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(2000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);*/
  // now turn off motors
  /*digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);*/
  
}
