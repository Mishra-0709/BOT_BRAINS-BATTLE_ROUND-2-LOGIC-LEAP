For QUESTION 1:

//Overview
This project involves designing, building, and programming a Two Wheeled Self-Balancing Robot (TWSBR) that can deliver parcels to consumers' doorsteps. The robot uses a combination of sensors, motor control, and navigation algorithms to maintain balance, avoid obstacles, and deliver parcels efficiently.

//Features
Self-Balancing: Uses a gyroscope and accelerometer with a PID controller to maintain balance.
Obstacle Detection: Utilizes a LIDAR sensor for mapping surroundings and detecting obstacles.
Navigation: Implements path planning algorithms to navigate to the delivery location.
Communication: Equipped with WiFi/Bluetooth for remote control and status updates.
Modular Design: Easy to upgrade and modify with new features.

//Hardware Components:
1. Microcontroller:
   - Arduino Uno (or any similar microcontroller board)
2. Sensors:
   - IMU Sensor: MPU6050 (Inertial Measurement Unit)
   - GPS Module:A generic GPS module such as NEO-6M
3. Motors and Motor Drivers:
   - DC Motors: Two DC motors with encoders (optional but useful for precise control)
   - Motor Driver: L298N Motor Driver Module
4. Power Supply:
   - Battery Pack: A suitable battery pack (LiPo or similar) to power the motors and the microcontroller
5. Miscellaneous:
   - Wires: Jumper wires for connections
   - Breadboard: For prototyping the circuit
   - Connectors: Battery connectors, motor connectors
Circuit Diagram:
![CD](https://github.com/Mishra-0709/BOT_BRAINS-BATTLE_ROUND-2-LOGIC-LEAP/assets/143344990/26efefc5-4522-4c6e-99dc-064c4167c78b)



For QUESTION 3:
//Tasks:
1. Enhancement:

Allow the user to set a custom threshold using a potentiometer on analog pin A1.
Read potentiometer value and adjust the threshold.
2. Feedback Mechanism:

Add a buzzer and LED for feedback.
Buzzer emits a short beep, and LED blinks briefly when watering starts and stops.
3. Power Efficiency:

Integrate sleep mode to conserve power.
Use a button on digital pin 2 to manually activate the system.
Stop all operations in sleep mode and wake up when the button is pressed.


//Solution Accomplished:
1)Added const int potPin = A1; to define the potentiometer pin.
In setup, set pinMode(potPin, INPUT);
2)Feedback Mechanism Using Buzzer and LED:
Added const int buzzerPin = 11; and const int ledPin = 12; to define pins.
In setup, set pinMode(buzzerPin, OUTPUT); and pinMode(ledPin, OUTPUT);.
Added feedback function to control buzzer and LED.
Called feedback in loop for watering actions.
3)Sleep Mode:
Added const int buttonPin = 2; to define button pin.
Added enterSleepMode function for sleep mode.
Added wakeUp function as wake-up handler.
