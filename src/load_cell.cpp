// TRASH WEIGHT SENSING
// Darsh
#include "load_cell.h"
#include <HX711.h>

// Pin definitions
#define DOUT 2
#define CLK 3

HX711 scale;

// Calibration factor — change this after you calibrate
// Put a known weight on the load cell and note the raw reading from the HX711. 
// Then divide that raw reading by the known weight in grams to get calibration factor,
//calibration_factor = raw_reading_with_weight / known_weight_in_grams
#define CALIBRATION_FACTOR 2280.0 // temp value

void initLoadCell() {
  scale.begin(DOUT, CLK);
  scale.set_scale(CALIBRATION_FACTOR);  // Set real value after testing
  scale.tare();  // Zero the scale at start
}

float readPlasticWeight() {
  if (scale.is_ready()) {
    return scale.get_units(3);  // Average of 3 samples
  } else {
    return -1.0;  // Return error if not ready
  }
}

