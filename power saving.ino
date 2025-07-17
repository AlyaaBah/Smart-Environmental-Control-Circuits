int sensorPin = A0;
int systemLed = 9;
int sensorLed = 10;

bool systemOn = true;
unsigned long lightStartTime = 0;
const unsigned long lightTimeout = 5000; 
int threshold = 300;

void setup() {
  pinMode(systemLed, OUTPUT);
  pinMode(sensorLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("LDR Value: ");
  Serial.println(sensorValue);

 
  if (sensorValue < threshold) {
    digitalWrite(sensorLed, HIGH);
    systemOn = true; 
  } else {
   
    digitalWrite(sensorLed, LOW);

  
    if (lightStartTime == 0) {
      lightStartTime = millis();
    }

    if (millis() - lightStartTime >= lightTimeout) {
      systemOn = false;
    }
  }

  
  if (sensorValue < threshold) {
    lightStartTime = 0;
  }


  digitalWrite(systemLed, systemOn ? HIGH : LOW);
}
