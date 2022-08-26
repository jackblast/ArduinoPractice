
// Blinks two red LEDs with a delay of 100 ms when switch is on, When switch is off green BLUE LED turns on always

int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW){
    digitalWrite(3, HIGH); // Green LED
    digitalWrite(4, LOW); // Red LED
    digitalWrite(5, LOW); // Red LED
  }
  else{
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    delay(100);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(100);
    
  }
  

}
