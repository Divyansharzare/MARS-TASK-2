
const int trigPin = 13;
const int echoPin =12;
int distance;
long duration;
int DIR = 10;
int PWM = 3;

void setup() {
   pinMode(DIR, OUTPUT);
  pinMode(PWM, OUTPUT);
  analogWrite(PWM,0);
  delay(50);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
   Serial.begin(9600);
   digitalWrite(trigPin, LOW);
   digitalWrite(echoPin, LOW);
  Serial.println("Distance measurement using Arduino Uno.");
  delay(500);
}

void loop() {
digitalWrite(trigPin, LOW);  
delayMicroseconds(2);  
digitalWrite(trigPin, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPin, LOW);  


   

duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.0344) / 2;
 
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
    if(distance<25){
      digitalWrite(DIR,HIGH);
  analogWrite(PWM,150);
    }
    else if(distance>25 && distance <50)
    {
      digitalWrite(DIR,HIGH);
  analogWrite(PWM,75);
    }
    else if(distance>50 && distance<75)
    {
       analogWrite(PWM,0);
    }
    else if(distance<100 && distance>75)
    {
      digitalWrite(DIR,LOW);
      analogWrite(PWM,75);
    }
    else if(distance>100)
    {
      digitalWrite(DIR,LOW);
      analogWrite(PWM,150);
    }
}


