#include "ultrasonic.h"
#include <Arduino.h>

// Pin setup (update these with your actual wiring)
const int trigPin = 2;
const int echoPin = 3;

void initUltrasonic() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  float distance = duration * 0.0343 / 2;

  if (duration == 0) {
    return -1; // Timeout — no object detected
  }

  return distance; // in cm
}
