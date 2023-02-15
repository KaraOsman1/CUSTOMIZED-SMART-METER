#include <SoftwareSerial.h>
SoftwareSerial SIM800l(10, 11);

#define flowSensorPin 2
#define relayPin 3

volatile int flowPulseCount;
float flowRate;
float flowVolume;
unsigned long currentTime;
unsigned long previousTime;
unsigned long elapsedTime;

void setup() {
  pinMode(flowSensorPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  Serial.begin(9600);
  SIM800l.begin(9600);
  attachInterrupt(digitalPinToInterrupt(flowSensorPin), flowPulseInterrupt, RISING);
}

void loop() {
  currentTime = millis();
  elapsedTime = currentTime - previousTime;
  if (elapsedTime >= 1000) {
    detachInterrupt(digitalPinToInterrupt(flowSensorPin));
    flowRate = ((1000.0 / elapsedTime) * flowPulseCount) / 6.0;
    flowVolume = flowVolume + ((flowRate / 60.0) * elapsedTime);
    flowPulseCount = 0;
    previousTime = currentTime;
    attachInterrupt(digitalPinToInterrupt(flowSensorPin), flowPulseInterrupt, RISING);
    Serial.print("Flow rate: ");
    Serial.print(flowRate);
    Serial.print(" L/min, Flow volume: ");
    Serial.print(flowVolume);
    Serial.println(" L");
    if (flowVolume >= 10.0) {
      digitalWrite(relayPin, LOW);
      delay(1000);
      digitalWrite(relayPin, HIGH);
      sendSMS("Water limit exceeded!");
      flowVolume = 0.0;
    }
  }
}

void flowPulseInterrupt() {
  flowPulseCount++;
}

void sendSMS(String message) {
  SIM800l.println("AT+CMGF=1");
  delay(100);
  SIM800l.println("AT+CMGS=\"+1234567890\"");
  delay(100);
  SIM800l.println(message);
  delay(100);
  SIM800l.write(0x1A);
}

