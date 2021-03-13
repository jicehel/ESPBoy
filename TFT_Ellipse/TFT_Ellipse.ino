/*
  Ellipse drawing example
  
  This sketch does not use any fonts.
*/

#include "ESPboyInit.h"

ESPboyInit myESPboy;       // Invoke custom library

int16_t h = 128;
int16_t w = 128;

void setup(void) {
  
  //Set up the display
  myESPboy.begin("TFT_Ellipse");
  
}

void loop() {

  myESPboy.tft.fillScreen(TFT_BLACK);

  // Draw some random filled elipses
  for (int i = 0; i < 20; i++)
  {
    int rx = random(40);
    int ry = random(40);
    int x = rx + random(w - rx - rx);
    int y = ry + random(h - ry - ry);
    myESPboy.tft.fillEllipse(x, y, rx, ry, random(0xFFFF));
  }

  delay(2000);
  myESPboy.tft.fillScreen(TFT_BLACK);

  // Draw some random outline elipses
  for (int i = 0; i < 20; i++)
  {
    int rx = random(40);
    int ry = random(40);
    int x = rx + random(w - rx - rx);
    int y = ry + random(h - ry - ry);
    myESPboy.tft.drawEllipse(x, y, rx, ry, random(0xFFFF));
  }

  delay(2000);
}
