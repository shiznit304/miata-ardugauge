#include "Arduino.h"
#include "Pages.h"
#include "Comms.h"
#include <Adafruit_SSD1306.h>
#include "splash.h"

Adafruit_SSD1306 OLED(128, 64, &Wire, -1);

void initDisplay()
{
  uint8_t i;
  
  OLED.begin(SSD1306_SWITCHCAPVCC, 60);
  OLED.setFont();
  OLED.setTextColor(INVERSE);

  OLED.clearDisplay();
  
  #ifndef TEST
    OLED.drawBitmap(0, 15, logoMazdaOutline, 128, 21, 1);
    OLED.display();
    delay(1000);
  #endif
}

void startPage(bool shiftLightOn)
{
  OLED.clearDisplay();

  //Drawing a white rectangle over the whole display will invert all graphics
  if(shiftLightOn)
    OLED.fillRect(0, 0, 128, 64, WHITE);
}

void endPage()
{
  OLED.display();
}

// Display CLT, OIL and IAT on the top row
void topRow_OIL_CLT_IAT(uint8_t oilT)
{
  char valString[8];

  // Print OIL
  OLED.setCursor(9,1);
  OLED.setTextSize(0);
  OLED.print(F("OIL"));
  OLED.setCursor(-1, 12);
  OLED.setTextSize(2);
  if(oilT == 0)
    OLED.print(F(" *"));  // Oil is cold (< 25)
  else if(oilT == 255)
    OLED.print(F("N/D")); // No sensor
  else
  {
    if(oilT < 100)
      OLED.print(" ");
    formatValue(valString, oilT, 0);
    OLED.print(valString);
  }
  
  // Print CLT
  int16_t clt = (int16_t)getByte(SPEEDUINO_CLT_BYTE) + SPEEDUINO_TEMPERATURE_OFFSET;
  OLED.setCursor(55,1);
  OLED.setTextSize(0);
  OLED.print(F("WATER"));
  OLED.setCursor(46, 12);
  OLED.setTextSize(2);
  if(abs(clt) < 10)
    OLED.print(" ");
  if(clt > 0)
    OLED.print(" ");
  formatValue(valString, clt, 0);
  OLED.print(valString);

  // Print IAT
  int16_t iat = (int16_t)getByte(SPEEDUINO_IAT_BYTE) + SPEEDUINO_TEMPERATURE_OFFSET;
  OLED.setCursor(108,1);
  OLED.setTextSize(0);
  OLED.print(F("AIR"));
  OLED.setCursor(92,12);
  OLED.setTextSize(2);
  if(abs(iat) < 10)
    OLED.print(" ");
  if(iat > 0 && iat < 100)
    OLED.print(" ");
  formatValue(valString, iat, 0);
  OLED.print(valString);
}


// Display IAT and BAT on the top row
void topRow_BAT_BARO_IAT()
{
  char valString[8];

  // Print Battery Voltage
  uint8_t bat = getByte(SPEEDUINO_VOLTAGE_BYTE);
  OLED.setCursor(3,1);
  OLED.setTextSize(0);
  OLED.print(F("BATTERY"));
  OLED.setCursor(-1,12);
  OLED.setTextSize(2);
  if(bat < 100)
    OLED.print(" ");
  formatValue(valString, bat, 1);
  OLED.print(valString);

  // Print BARO
  uint8_t baro = getByte(SPEEDUINO_BARO_BYTE);
  OLED.setCursor(62,1);
  OLED.setTextSize(0);
  OLED.print(F("BARO"));
  OLED.setCursor(50, 12);
  OLED.setTextSize(2);
  if(baro < 100)
    OLED.print(" ");
  formatValue(valString, baro, 0);
  OLED.print(valString);

  // Print IAT
  int16_t iat = (int16_t)getByte(SPEEDUINO_IAT_BYTE) + SPEEDUINO_TEMPERATURE_OFFSET;
  OLED.setCursor(108,1);
  OLED.setTextSize(0);
  OLED.print(F("AIR"));
  OLED.setCursor(92,12);
  OLED.setTextSize(2);
  if(abs(iat) < 10)
    OLED.print(" ");
  if(iat > 0 && iat < 100)
    OLED.print(" ");
  formatValue(valString, iat, 0);
  OLED.print(valString);
}

// Display CLT, OIL and Target on the top row
void topRow_OIL_CLT_Target(uint8_t oilT)
{
  char valString[8];

  // Print OIL
  OLED.setCursor(9,1);
  OLED.setTextSize(0);
  OLED.print(F("OIL"));
  OLED.setCursor(-1, 12);
  OLED.setTextSize(2);
  if(oilT == 0)
    OLED.print(F(" *"));  // Oil is cold (< 25)
  else if(oilT == 255)
    OLED.print(F("N/D")); // No sensor
  else
  {
    if(oilT < 100)
      OLED.print(" ");
    formatValue(valString, oilT, 0);
    OLED.print(valString);
  }
  
  // Print CLT
  int16_t clt = (int16_t)getByte(SPEEDUINO_CLT_BYTE) + SPEEDUINO_TEMPERATURE_OFFSET;
  OLED.setCursor(48,1);
  OLED.setTextSize(0);
  OLED.print(F("WATER"));
  OLED.setCursor(40, 12);
  OLED.setTextSize(2);
  if(abs(clt) < 10)
    OLED.print(" ");
  if(clt > 0)
    OLED.print(" ");
  formatValue(valString, clt, 0);
  OLED.print(valString);

  // Print Target
  OLED.setCursor(92,1);
  OLED.setTextSize(0);
  OLED.print(F("TARGET"));
  OLED.setCursor(80,12);
  OLED.setTextSize(2);
  formatValue(valString, getByte(SPEEDUINO_AFRTARGET_BYTE), 1);
  OLED.print(valString);
}

// Display OIL and Target AFR on the top row + Display warning if CLT or OIL are overheating
void topRow_OIL_Target(uint8_t oilT)
{
  char valString[8];

  // Print OIL Temperature or Water/Oil Warning
  int16_t clt = (int16_t)getByte(SPEEDUINO_CLT_BYTE) + SPEEDUINO_TEMPERATURE_OFFSET;

  if(clt > WARNING_CLTTEMP)
  {
    // Show water temperature instead of oil, with a warning rectangle!
    OLED.fillRoundRect(0, 0, 36, 28, 2, INVERSE);
    OLED.setCursor(3,1);
    OLED.setTextSize(0);
    OLED.print(F("WATER"));
    OLED.setCursor(-1, 12);
    OLED.setTextSize(2);
    if(clt < 100)
    OLED.print(" ");
    formatValue(valString, clt, 0);
    OLED.print(valString);
  }
  else
  {
    // Water temperature is ok, show Oil temperature

    if(oilT < 255 && oilT > WARNING_OILTEMP) // Oil overheat!
      OLED.fillRoundRect(0, 0, 36, 28, 2, INVERSE);
    
    OLED.setCursor(9,1);
    OLED.setTextSize(0);
    OLED.print(F("OIL"));
    OLED.setCursor(-1,12);
    OLED.setTextSize(2);
    if(oilT == 0)
      OLED.print(F(" *"));  // Oil is cold (< 25)
    else if(oilT == 255)
      OLED.print(F("N/D")); // No sensor
    else
    {
      if(oilT < 100)
        OLED.print(" ");
      formatValue(valString, oilT, 0);
      OLED.print(valString);
    }
  }

  // Display AFR Target
  OLED.setCursor(55, 4);
  OLED.setTextSize(3);
  formatValue(valString, getByte(SPEEDUINO_AFRTARGET_BYTE), 1);
  OLED.print(valString);
}

// Display BAT and BARO on the bottom row
void bottomRow_BAT_BARO()
{
  char valString[8];
  
  // Print Battery Voltage
  uint8_t bat = getByte(SPEEDUINO_VOLTAGE_BYTE);
  OLED.setCursor(11,37);
  OLED.setTextSize(0);
  OLED.print(F("BATTERY"));
  OLED.setCursor(9,48);
  OLED.setTextSize(2);
  if(bat < 100)
    OLED.print(" ");
  formatValue(valString, bat, 1);
  OLED.print(valString);

  // Print Baro
  uint8_t baro = getByte(SPEEDUINO_BARO_BYTE);
  OLED.setCursor(84,37);
  OLED.setTextSize(0);
  OLED.print(F("BARO"));
  OLED.setCursor(73, 48);
  OLED.setTextSize(2);
  if(baro < 100)
    OLED.print(" ");
  formatValue(valString, baro, 0);
  OLED.print(valString);
}

// Display AFR on the bottom row
void bottomRow_AFR()
{
  char valString[8];
  int8_t i;

  //OLED.setCursor(2, 53);
  //OLED.setTextSize(0);
  //OLED.print(F("AFR"));
  OLED.setCursor(32, 34);
  OLED.setTextSize(4);
  formatValue(valString, getByte(SPEEDUINO_AFR_BYTE), 1);
  OLED.print(valString);

  // EGO Correction indicators
  OLED.drawFastVLine(1, 48 - EGO_AUTHORITY * EGO_TICK_PIXELS, 2 * EGO_AUTHORITY * EGO_TICK_PIXELS + 1, INVERSE);
  for(i = -EGO_AUTHORITY; i <= EGO_AUTHORITY; i++)
    OLED.drawFastHLine(2, 48 + (i * EGO_TICK_PIXELS), 3, INVERSE);
  i = (getByte(SPEEDUINO_EGOCORR_BYTE) - 100) * EGO_TICK_PIXELS;
  OLED.fillTriangle(8, 48 - i, 12, 44 - i, 12, 52 - i, INVERSE);

  // TPS AE/DE indicator
  if(getByte(SPEEDUINO_TAECORR_BYTE) > 100)
    OLED.fillTriangle(20, 46, 24, 38, 28, 46, INVERSE);
  else if(getByte(SPEEDUINO_TAECORR_BYTE) < 100)
    OLED.fillTriangle(20, 50, 24, 58, 28, 50, INVERSE);
}

// Display Target and AFR on the bottom row
void bottomRow_Target_AFR()
{
  char valString[8];

  // Print Target
  OLED.setCursor(7,37);
  OLED.setTextSize(0);
  OLED.print(F("TARGET"));
  OLED.setCursor(1,48);
  OLED.setTextSize(2);
  formatValue(valString, getByte(SPEEDUINO_AFRTARGET_BYTE), 1);
  OLED.print(valString);

  // Print AFR
  OLED.setCursor(56,41);
  OLED.setTextSize(3);
  formatValue(valString, getByte(SPEEDUINO_AFR_BYTE), 1);
  OLED.print(valString);
}

// Display tuning values on 3 lines
void pageTuning()
{
  char valString[8];

  //Print Labels
  OLED.setTextSize(0);
  OLED.setCursor(50,32);
  OLED.print(F("T"));
  OLED.setCursor(40,56);
  OLED.print(F("CALC"));
  OLED.setCursor(76,56);
  OLED.print(F("VE"));

  OLED.setTextSize(2);

  // Print RPM
  uint16_t rpm = getWord(SPEEDUINO_RPM_WORD);
  OLED.setCursor(1,1);
  if(rpm < 1000)
    OLED.print(" ");
  formatValue(valString, rpm, 0);
  OLED.print(valString);

  // Print LOAD
  int16_t map = getWord(SPEEDUINO_MAP_WORD);
  OLED.setCursor(92,1);
  if(map < 100)
    OLED.print(" ");
  formatValue(valString, map, 0);
  OLED.print(valString);

  // Print Target
  OLED.setCursor(1,25);
  uint8_t tgt = getByte(SPEEDUINO_AFRTARGET_BYTE);
  formatValue(valString, tgt, 1);
  OLED.print(valString);

  // Print AFR
  OLED.setCursor(80,25);
  uint8_t afr = getByte(SPEEDUINO_AFR_BYTE);
  formatValue(valString, afr, 1);
  OLED.print(valString);

  // Print Current VE
  OLED.setCursor(92,49);
  uint16_t ve = getByte(SPEEDUINO_CURRENTVE_BYTE) * 100 / getByte(SPEEDUINO_GAMMAE_BYTE);
  if(ve < 100)
    OLED.print(" ");
  formatValue(valString, ve, 0);
  OLED.print(valString);

  // Print Suggested VE
  OLED.setCursor(1,49);
  uint32_t new_ve = ve * afr / tgt;
  if(new_ve < 100)
    OLED.print(" ");
  formatValue(valString, new_ve, 0);
  OLED.print(valString);
}

void pageAFRGraph()
{
  char valString[8];
  uint8_t i, x, y, y1 = getByte(SPEEDUINO_AFR_BYTE) - 100;
  static uint8_t afrData[100];
  static uint8_t afrIndex = 0;
  static uint8_t maxTPSDOT = 0;
  static uint32_t lastTPSDOT = millis();
  static uint8_t maxTAE = 100;
  static uint32_t lastTAE = millis();

  OLED.clearDisplay(); // Reset display to black (no shift light in this page)

  // Update max TPSdot value
  if(getByte(SPEEDUINO_TPSDOT_BYTE) >= maxTPSDOT)
  {
    maxTPSDOT = getByte(SPEEDUINO_TPSDOT_BYTE);
    lastTPSDOT = millis();
  }
  else if(millis() > lastTPSDOT + TPSDOT_PERSISTENCE_MS)
  {
    maxTPSDOT = 0;
    lastTPSDOT = millis();
  }

  // Update max TAE value
  if(getByte(SPEEDUINO_TAECORR_BYTE) >= maxTAE)
  {
    maxTAE = getByte(SPEEDUINO_TAECORR_BYTE);
    lastTAE = millis();
  }
  else if(millis() > lastTAE + TPSDOT_PERSISTENCE_MS)
  {
    maxTAE = 100;
    lastTAE = millis();
  }

  // Update AFR graph with last data
  afrData[afrIndex] = getByte(SPEEDUINO_AFR_BYTE) - 100;

  // Print Max TPSdot
  OLED.setCursor(0, 0);
  OLED.setTextSize(0);
  OLED.print(F("TPSdot "));
  formatValue(valString, maxTPSDOT * 10, 0);
  if(maxTPSDOT < 100)
    OLED.print(F(" "));
  if(maxTPSDOT < 10)
    OLED.print(F(" "));
  if(maxTPSDOT == 0)
    OLED.print(F(" "));
  OLED.print(valString); 

  // Print Max TAE
  OLED.print(F("   TAE "));
  formatValue(valString, maxTAE, 0);
  OLED.print(valString);

  // Print AFR Graph
  OLED.drawLine(14, 13, 17, 13, WHITE); // 20
  OLED.setCursor(0, 13);
  OLED.print(F("20"));
  OLED.drawLine(14, 38, 17, 38, WHITE); // 15
  OLED.setCursor(0, 35);
  OLED.print(F("15"));
  OLED.drawLine(14, 63, 17, 63, WHITE); // 10
  OLED.setCursor(0, 56);
  OLED.print(F("10"));
  
  i = afrIndex + 1;         // Start from the oldest data
  for(x = 0; x < 100; x++)
  {
    if(i > 99)
      i = 0;                // Overflow back to zero

    y1 = y;                 // Data i - 1
    y = afrData[i];         // Data i
    i++;

    OLED.drawLine(x + 21, (63 - y / 2) , x + 20, (63 - y1 / 2), WHITE); 
  }

  OLED.setCursor(104, 57);
  formatValue(valString, getByte(SPEEDUINO_AFR_BYTE), 1);
  OLED.print(valString);

  afrIndex++; // Next time we will write to the next data entry
  if(afrIndex > 99)
    afrIndex = 0;
}

void pageNoECU()
{
  OLED.drawBitmap(0, 15, logoMazdaOutline, 128, 21, 1);
  OLED.setCursor(25,45);
  OLED.setTextSize(1);
  OLED.print(F("NO CONNECTION"));
}

uint8_t formatValue(char *buf, int32_t value, uint8_t decimal)
{
  clearBuffer(buf);
  snprintf(buf, 22, "%d", value);
  uint8_t len = strlen(buf);

  if (decimal != 0)
  {
    uint8_t target = decimal + 1;
    uint8_t numLen = len - ((value < 0) ? 1 : 0);
    while (numLen < target)
    {
      for (uint8_t i = 0; i < numLen + 1; i++)
      // if negative, skip negative sign
      {
        buf[len - i + 1] = buf[len - i];
        buf[len - i] = '0';
      }
      buf[len + 1] = '\0';
      numLen++;
      len++;
    }
    // insert
    for (uint8_t i = 0; i < decimal + 1; i++)
    {
      buf[len - i + 1] = buf[len - i];
      buf[len - i] = '.';
    }
  }
  return strlen(buf);
}

void clearBuffer(char *buf, uint8_t bufLen)
{
  for (uint8_t i = 0; i < bufLen; i++)
  {
    buf[i] = '\0';
  }
}
