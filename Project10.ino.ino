// Control speed on motor with potentiometer, one switch to control on/off, another switch to control direction

const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;


int motorEnabled = 0;
int motorSpeed = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  motorSpeed = analogRead(potPin)/4;
  if (onOffSwitchState != previousOnOffSwitchState){
    if (onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW);
 
  Serial.println(motorSpeed);

  if (motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }else{
    analogWrite(enablePin, 0);
  }
  previousOnOffSwitchState = onOffSwitchState;
}
