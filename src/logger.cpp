#include "logger.h"
#include "cellular.h"
#include <Arduino.h>
#include "gps.h" // Include the header file where GPSLocation is defined

void initLogger() {
  // Optional: start log file or cloud session
}

void logData(float distance, bool plasticFound, float weight, GPSLocation location) {
  String message = "DIST=" + String(distance) +
                   ", PLASTIC=" + String(plasticFound) +
                   ", WEIGHT=" + String(weight) +
                   ", LAT=" + String(location.latitude) +
                   ", LNG=" + String(location.longitude);
  sendToCloud(std::string(message.c_str()));
}
