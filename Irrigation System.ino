#include <Servo.h>
#include <LowPower.h>

const int soilMoisturePin = A0;
const int pumpPin = 9;
const int potPin = A1; // Added potentiometer pin
const int buttonPin = 2; // Added button pin
const int buzzerPin = 11; // Added buzzer pin
const int ledPin = 12; // Added LED pin

Servo servoMotor;

int threshold = 300; // Initial threshold

void setup() {
  pinMode(soilMoisturePin, INPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(potPin, INPUT); // Set potentiometer pin as input
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  servoMotor.attach(10);

  attachInterrupt(digitalPinToInterrupt(buttonPin), wakeUp, FALLING); // Attach interrupt to wake up
}

void loop() {
  threshold = map(analogRead(potPin), 0, 1023, 0, 1023); // Adjust threshold using potentiometer
  
  int soilMoisture = analogRead(soilMoisturePin);
  
  if (soilMoisture < threshold) {
    digitalWrite(pumpPin, HIGH);
    servoMotor.write(90);
    feedback(true); // Provide feedback when watering starts
    delay(5000); // Watering duration
    digitalWrite(pumpPin, LOW);
    servoMotor.write(0);
    feedback(false); // Provide feedback when watering stops
  }
  
  delay(1000); // Check soil moisture every second

  enterSleepMode(); // Enter sleep mode to conserve power
}

void feedback(bool watering) {
  if (watering) {
    digitalWrite(ledPin, HIGH); // Turn on LED
    tone(buzzerPin, 1000, 100); // Short beep
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED
    tone(buzzerPin, 500, 100); // Short beep
  }
  delay(100);
}

void enterSleepMode() {
  // Power down everything and enter sleep mode
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

void wakeUp() {
 
}

