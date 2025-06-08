#ifndef LOGGER_H
#define LOGGER_H

#include "gps.h"

void initLogger();
void logData(float distance, bool plasticFound, float weight, GPSLocation location);

#endif
