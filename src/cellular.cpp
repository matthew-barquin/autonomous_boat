// 4G COMMUNICATION
#include "cellular.h"
#include <Arduino.h>

void initCellular() {
  // Set up cellular modem, APN, etc.
}

void sendToCloud(String data) {
  // Send data via HTTP/MQTT/etc.
  Serial.println("Sending to cloud: " + data);
}
