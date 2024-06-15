Tasks:
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


Solution Accomplished:
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
