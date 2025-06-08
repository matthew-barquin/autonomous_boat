//GPS TRACKING
//madhumita

#include "gps.h"
#include <Arduino.h>

// GNSS module connected to Serial1
#define GPS_SERIAL Serial1

void initGPS() {
    GPS_SERIAL.begin(9600); // GNSS module usually runs at 9600 baud
    delay(2000);
    Serial.println("GNSS module initialized.");
}

// Parses NMEA sentence (very basic $GPRMC parser)
GPSLocation getGPSLocation() {
    GPSLocation loc;
    loc.latitude = 0.0;
    loc.longitude = 0.0;

    while (GPS_SERIAL.available()) {
        String nmea = GPS_SERIAL.readStringUntil('\n');
        if (nmea.startsWith("$GPRMC")) {
            // Example: $GPRMC,hhmmss.sss,A,llll.ll,a,yyyyy.yy,a,x.x,x.x,ddmmyy,x.x,a*hh
            char* token;
            char nmeaCopy[100];
            nmea.toCharArray(nmeaCopy, 100);
            token = strtok(nmeaCopy, ",");

            int index = 0;
            char latBuf[15], lonBuf[15];
            char latDir = 'N', lonDir = 'E';

            while (token != NULL) {
                if (index == 3) strcpy(latBuf, token);
                if (index == 4) latDir = token[0];
                if (index == 5) strcpy(lonBuf, token);
                if (index == 6) lonDir = token[0];
                token = strtok(NULL, ",");
                index++;
            }

            float lat = convertToDecimal(latBuf);
            float lon = convertToDecimal(lonBuf);
            if (latDir == 'S') lat = -lat;
            if (lonDir == 'W') lon = -lon;

            loc.latitude = lat;
            loc.longitude = lon;
            break;
        }
    }
    return loc;
}

// Helper function: converts "ddmm.mmmm" NMEA format to decimal degrees
float convertToDecimal(const char* nmeaCoord) {
    float raw = atof(nmeaCoord);
    int degrees = int(raw / 100);
    float minutes = raw - (degrees * 100);
    return degrees + (minutes / 60.0);
}

// Called when plastic is detected
void checkPlasticAndSendLocation(bool plasticDetected) {
    if (plasticDetected) {
        GPSLocation loc = getGPSLocation();
        sendLocationToServer(loc);  // Placeholder function to use 4G module
    }
}


#ifndef GPS_H
#define GPS_H

struct GPSLocation {
    float latitude;
    float longitude;
};

void initGPS();
GPSLocation getGPSLocation();
void checkPlasticAndSendLocation(bool plasticDetected);

#endif
