int tempSensor = A0;
int pirSensor = 2;
int fanLed = 9;

float temperature = 0.0;
int tempThreshold = 23; 

void setup() {
  pinMode(pirSensor, INPUT);
  pinMode(fanLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(tempSensor);
  temperature = (sensorValue * 5.0 / 1023.0 - 0.5) * 100.0;

 
  bool motionDetected = digitalRead(pirSensor);

 
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Motion: ");
  Serial.println(motionDetected ? "Yes" : "No");

 
  if (motionDetected && temperature > tempThreshold) {
    digitalWrite(fanLed, HIGH);
  } else {
    digitalWrite(fanLed, LOW);
  }

  delay(500);
}
