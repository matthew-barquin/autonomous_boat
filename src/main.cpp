#include <Arduino.h>

void setup() {
  Serial.begin(115200); // Start serial monitor
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.println("Boat is running...");
  digitalWrite(LED_BUILTIN, HIGH); // Turn on LED
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);  // Turn off LED
  delay(500);
}
