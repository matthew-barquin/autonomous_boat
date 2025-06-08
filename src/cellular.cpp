// 4G COMMUNICATION
// Matthew
#include <Arduino.h>
#include <Arduino_Cellular.h>
#include <ArduinoHttpClient.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

// SIM & APN
contentReference[oaicite:3]{index=3}
:contentReference[oaicite:4]{index=4}
:contentReference[oaicite:5]{index=5}
:contentReference[oaicite:6]{index=6}

// Cloud credentials
:contentReference[oaicite:7]{index=7}
:contentReference[oaicite:8]{index=8}

:contentReference[oaicite:9]{index=9}
:contentReference[oaicite:10]{index=10}
:contentReference[oaicite:11]{index=11}

// Cellular objects
Cellular cellular;
:contentReference[oaicite:12]{index=12}

:contentReference[oaicite:13]{index=13}
:contentReference[oaicite:14]{index=14}
:contentReference[oaicite:15]{index=15}

:contentReference[oaicite:16]{index=16}
void initCellular() {
  :contentReference[oaicite:17]{index=17}
  delay(1000);

  :contentReference[oaicite:18]{index=18}
    :contentReference[oaicite:19]{index=19}
    while(true);
  }

  :contentReference[oaicite:20]{index=20}
    :contentReference[oaicite:21]{index=21}
    while(true);
  }

  cellular.enableGPS();
  :contentReference[oaicite:22]{index=22}
}

:contentReference[oaicite:23]{index=23}
void initCloud() {
  :contentReference[oaicite:24]{index=24}
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  :contentReference[oaicite:25]{index=25}
  :contentReference[oaicite:26]{index=26}
}

:contentReference[oaicite:27]{index=27}
bool updateGPS() {
  :contentReference[oaicite:28]{index=28}
  :contentReference[oaicite:29]{index=29}
  :contentReference[oaicite:30]{index=30}
  :contentReference[oaicite:31]{index=31}
  :contentReference[oaicite:32]{index=32}\n", gpsLat, gpsLon);
  return true;
}
