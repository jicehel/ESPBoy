// Test program: Minimal code

#include "ESPboyInit.h"

ESPboyInit myESPboy;       // Invoke custom library
static uint16_t count = 0;

void setup()   {
  //Set up the display
  myESPboy.begin("Minimal code");
  myESPboy.tft.setTextSize(2);
  myESPboy.tft.setTextColor(TFT_WHITE);
}

void loop() {
  
  // Display a counter
  myESPboy.tft.fillScreen(TFT_BLACK);
  char buf[10];
  count++;
  myESPboy.tft.setCursor(20, 5);
  myESPboy.tft.print(F("Test - "));
  dtostrf(count, 5, 0, buf); 
  myESPboy.tft.print(buf);
  delay(333);

}


/*
   The MIT License (MIT)

   Copyright (c) 2016 RuntimeProjects.com

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/
