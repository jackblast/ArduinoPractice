// Automatic Door Opener based on number of knocks

#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(10);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (locked == false){
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box in locked!");
      delay(1000);
    }
  }
  if (locked == true){
    knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > 0){
      if (checkForKnock(knockVal) == true){
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println("More knocks to go");
    }
    if (numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked!");
      numberOfKnocks = 0;
    }
  }
}

boolean checkForKnock(int value){
  if (value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed ,HIGH);
    delay(20);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }else{
    Serial.print("Bad Knock value");
    Serial.println(value);
    return false;
  }
}
