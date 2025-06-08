#ifndef CELLULAR_H
#define CELLULAR_H

#include <string>  // Include the standard string header

void initCellular();            // Setup SIM, APN, etc.
void sendToCloud(std::string data);  // Send data via cellular network

#endif
