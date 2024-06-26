#include <Wire.h>
#include <MPU6050.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// instances of the sensors
MPU6050 mpu;
TinyGPSPlus gps;
SoftwareSerial gpsSerial(4, 3); // RX, TX for GPS

// PID constants for balance control
float Kp = 1.0;
float Ki = 0.1;
float Kd = 0.01;
float setPoint = 0; 
float integral = 0, previous_error = 0;

// Motor control pins
int motorLeftPin1 = 9;
int motorLeftPin2 = 10;
int motorRightPin1 = 5;
int motorRightPin2 = 6;

// Variables to store sensor readings
int16_t ax, ay, az, gx, gy, gz;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing...");

  // Initialize sensors
  Wire.begin();
  mpu.initialize();
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful");
  } else {
    Serial.println("MPU6050 connection failed");
  }

  gpsSerial.begin(9600);
  Serial.println("GPS serial started");

  // Initialize motor pins
  pinMode(motorLeftPin1, OUTPUT);
  pinMode(motorLeftPin2, OUTPUT);
  pinMode(motorRightPin1, OUTPUT);
  pinMode(motorRightPin2, OUTPUT);
  Serial.println("Motor pins initialized");
}

void loop() {
  // Read MPU6050 data
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  float angle = atan2(ax, az) * 180 / PI; // Calculate tilt angle
  Serial.print("Angle: ");
  Serial.println(angle);

  // Calculate PID output
  float error = setPoint - angle;
  integral += error;
  float derivative = error - previous_error;
  float output = Kp * error + Ki * integral + Kd * derivative;
  Serial.print("PID output: ");
  Serial.println(output);

  // Control motors based on PID output
  if (output > 0) {
    analogWrite(motorLeftPin1, output);
    analogWrite(motorLeftPin2, 0);
    analogWrite(motorRightPin1, output);
    analogWrite(motorRightPin2, 0);
    Serial.println("Motors forward");
  } else {
    analogWrite(motorLeftPin1, 0);
    analogWrite(motorLeftPin2, -output);
    analogWrite(motorRightPin1, 0);
    analogWrite(motorRightPin2, -output);
    Serial.println("Motors backward");
  }

  previous_error = error;

  // Read GPS data
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  // Print GPS coordinates to the Serial Monitor
  if (gps.location.isUpdated()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.println("No GPS update");
  }

  delay(100); // Small delay to prevent overwhelming the microcontroller
}
