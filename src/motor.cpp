#include "motor.h"
#include <Arduino.h>

// Define motor control pins
const int motorPin = 5;

void initMotor() {
  pinMode(motorPin, OUTPUT);
  analogWrite(motorPin, 0);
}

void driveForward() {
  analogWrite(motorPin, 180); // PWM value depends on ESC
}

void stopMotors() {
  analogWrite(motorPin, 0);
}
