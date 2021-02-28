// Test program: Minimal code

#include "ESPboyInit.h"


ESPboyInit myESPboy;       // Invoke custom library

void setup()   {
  //Set up the display
  myESPboy.begin("WriteOnScreen");
}

void loop() {

  //Display a simple splash screen
  myESPboy.tft.fillScreen(TFT_BLACK);
  myESPboy.tft.setTextSize(2);
  myESPboy.tft.setTextColor(TFT_WHITE);
  myESPboy.tft.setCursor(40, 5);
  myESPboy.tft.println(F("Test program"));

}
