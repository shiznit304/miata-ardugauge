#include "Arduino.h"
#include "Comms.h"

bool requestData(uint16_t timeout) // Returns FALSE if timeout occurs or data is corrupted
{
  Serial.setTimeout(timeout);

  // flush input buffer

  Serial.write('n');

  // wait for data or timeout
  uint32_t start = millis();
  uint32_t end = start;
  while (Serial.available() < 3 && (end - start) < timeout)
  {
    end = millis();
  }

  // if within timeout, read data
  if (end - start < timeout)
  {
    // Check first two bytes for validation
    uint8_t check1 = Serial.read();
    uint8_t check2 = Serial.read();
    if(check1 != 0x6E || check2 != 0x32) // 0x6E = n, 0x32 is a check value
    {
      while(Serial.available())
        Serial.read();  // Empty the incoming buffer

      return true; // We keep the last valid dataset
    }

    uint8_t dataLen = Serial.read();
    Serial.readBytes(buffer, dataLen);

    return true;
  }
  else
    return false;
}

bool getBit(uint16_t address, uint8_t bit)
{
  return bitRead(buffer[address], bit);
}

uint8_t getByte(uint16_t address)
{
  return buffer[address];
}

uint16_t getWord(uint16_t address)
{
  return makeWord(buffer[address + 1], buffer[address]);
}