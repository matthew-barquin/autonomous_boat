#include "motor.h"
#include <Arduino.h>

// --- annwaykara ---
// Pin Definitions
const int leftMotorPin  = 5;   // PWM pin for left motor
const int rightMotorPin = 6;   // PWM pin for right motor

// Direction pins (optional, if using H-bridge motor drivers)
const int leftDirPin  = 7;
const int rightDirPin = 8;

// Speed settings (0-255 for Arduino PWM)
const int DEFAULT_SPEED = 180;
const int TURN_SPEED    = 150;

// --- Initialization ---
void initMotors() {
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(leftDirPin, OUTPUT);
  pinMode(rightDirPin, OUTPUT);
  // Set initial state
  stopMotors();
}

// --- Movement Functions ---
void driveForward(int speed = DEFAULT_SPEED) {
  digitalWrite(leftDirPin, HIGH);   // Forward direction
  digitalWrite(rightDirPin, HIGH);
  analogWrite(leftMotorPin, speed);
  analogWrite(rightMotorPin, speed);
}

void driveBackward(int speed = DEFAULT_SPEED) {
  digitalWrite(leftDirPin, LOW);    // Backward direction
  digitalWrite(rightDirPin, LOW);
  analogWrite(leftMotorPin, speed);
  analogWrite(rightMotorPin, speed);
}

void turnLeft(int speed = TURN_SPEED) {
  digitalWrite(leftDirPin, LOW);    // Left motor backward
  digitalWrite(rightDirPin, HIGH);  // Right motor forward
  analogWrite(leftMotorPin, speed);
  analogWrite(rightMotorPin, speed);
}

void turnRight(int speed = TURN_SPEED) {
  digitalWrite(leftDirPin, HIGH);   // Left motor forward
  digitalWrite(rightDirPin, LOW);   // Right motor backward
  analogWrite(leftMotorPin, speed);
  analogWrite(rightMotorPin, speed);
}

void stopMotors() {
  analogWrite(leftMotorPin, 0);
  analogWrite(rightMotorPin, 0);
}

// --- Emergency Stop ---
void emergencyStop() {
  stopMotors();
  // Optionally add an LED or buzzer alert
}

// --- Example Usage ---
void setup() {
  initMotors();
  // Optionally initialize sensors here
}

void loop() {
  // Example pattern: forward, left, forward, right, stop
  driveForward();
  delay(2000);
  turnLeft();
  delay(1000);
  driveForward();
  delay(2000);
  turnRight();
  delay(1000);
  stopMotors();
  delay(3000);
  // Emergency stop trigger example (to be connected to a sensor or button)
  // if (digitalRead(emergencyPin) == HIGH) emergencyStop();
}