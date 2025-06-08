#ifndef CELLULAR_H
#define CELLULAR_H

void initCellular();            // Setup SIM, APN, etc.
void sendToCloud(String data);  // Send data via cellular network

#endif
