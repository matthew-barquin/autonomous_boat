#ifndef GPS_H
#define GPS_H

struct GPSLocation {
  float latitude;
  float longitude;
};

void initGPS();                      // Setup GPS module
GPSLocation getGPSLocation();        // Return current location

#endif
