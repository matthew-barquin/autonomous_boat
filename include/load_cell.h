#ifndef LOAD_CELL_H
#define LOAD_CELL_H

void initLoadCell();          // Setup HX711 or other sensor
float readPlasticWeight();    // Return weight in grams

#endif
