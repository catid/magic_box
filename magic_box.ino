// Copyright 2021 Christopher A. Taylor

#include <Servo.h>

enum PinId {
    PinIdServoMotorInput = 13,
    PinIdPhotoresistor = A0,
};

enum ServoMotorInputAngle {
    ServoMotorInputAngleMin = 0,
    ServoMotorInputAngleMax = 179,
};

// Min/max that the photoresistor can read
int photoresistorMinValue;
int photoresistorMaxValue;

bool flip;
bool triggered;

Servo servoMotor;


void setup() {
  servoMotor.attach(PinIdServoMotorInput);

  Serial.begin(9600);
  Serial.println("Magic Box");

  calibratePhotoresistor(&photoresistorMinValue, &photoresistorMaxValue);

  Serial.print("Photoresistor min=");
  Serial.print(photoresistorMinValue);
  Serial.print(" max=");
  Serial.println(photoresistorMaxValue);

  flip = false;
  triggered = false;
  servoMotor.write(ServoMotorInputAngleMin);
}

/**
Calibrate the photoresistor bounds
param int minValue Minimum value to set
param int maxValue Maximum value to set
*/
void calibratePhotoresistor(int *minValue, int *maxValue) {
    
    // Set the min/max photoresistor bounds to their opposive value. 
    *minValue = 1023;
    *maxValue = 0;
    
    // Calibrate for a period of time 
    const int calibrationPeriodMs = 5000;
    while (millis() < calibrationPeriodMs) {
        
        const int photoresistorValue = analogRead(PinIdPhotoresistor);
        
        if (photoresistorValue > *maxValue) {
            *maxValue = photoresistorValue;
        }
        if (photoresistorValue < *minValue) {
            *minValue = photoresistorValue;
        }
    }
}


void loop() {
    // Catch the light and translate it in an appropriate pitch
    const int photoresistorValue = analogRead(PinIdPhotoresistor);
    const int percent = map(photoresistorValue, 
                               photoresistorMinValue, photoresistorMaxValue,
                               0, 100);

    if (percent <= 0) {
      if (!triggered) {
        flip = !flip;
        triggered = true;
        if (flip) {
          servoMotor.write(ServoMotorInputAngleMax - 5);
        } else {
          servoMotor.write(ServoMotorInputAngleMin);
        }
  
        delay(2000);
      }
    } else {
      triggered = false;
    }

    delay(10);
}
