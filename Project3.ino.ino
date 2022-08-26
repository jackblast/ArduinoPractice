//Love - O - Meter, Sensor takes temperature Measurement and different LED blinks for different room temperature


const int sensorPin = A0;
const float baselineTemp = 24.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print("Volts: ");
  Serial.print(voltage);
  Serial.print("Degrees: ");
  float temperature = (voltage - 0.5)*100;
  Serial.println(temperature);

  if(temperature < baselineTemp){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp && temperature < baselineTemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp + 4){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }else if(temperature >= baselineTemp + 4){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
