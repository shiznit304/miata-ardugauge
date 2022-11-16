#ifndef PAGES_H
#define PAGES_H

#define STRING_LENGTH 8

#define TPSDOT_PERSISTENCE_MS 1000

#define WARNING_OILTEMP 115
#define WARNING_CLTTEMP 90

#define SHIFTLIGHT_ON_RPM 6800                      // Activate shift light above this threshold
#define SHIFTLIGHT_OFF_RPM SHIFTLIGHT_ON_RPM - 100  // Turn off shift light under this threshold

#define SPEEDUINO_TEMPERATURE_OFFSET -40

#define strlen_PM(x) strlen_P(reinterpret_cast<const char *>(x))
#define Fstring const __FlashStringHelper *

#include "Comms.h"

void clearBuffer(char *buf, uint8_t bufLen = STRING_LENGTH);

#endif //PAGES_H
