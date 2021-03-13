// Coulour_Test adapted by Jicehel from the TFT_eSPI examples

#include "ESPboyInit.h"

ESPboyInit myESPboy;       // Invoke custom library

void setup()   {
  //Set up the display
  myESPboy.begin("Colour_Test");
  myESPboy.tft.fillScreen(TFT_BLACK);
  // Set "cursor" at top left corner of display (0,0) and select font 1
  myESPboy.tft.setCursor(0, 0, 1);
  // myESPboy.tft.setCursor(0, 0);

  // Set the font colour to be white with a black background
  myESPboy.tft.setTextColor(TFT_WHITE, TFT_BLACK);

  // We can now plot text on screen using the "print" class
  myESPboy.tft.println("Intialised default\n");
  myESPboy.tft.println("White text");
  
  myESPboy.tft.setTextColor(TFT_RED, TFT_BLACK);
  myESPboy.tft.println("Red text");
  
  myESPboy.tft.setTextColor(TFT_GREEN, TFT_BLACK);
  myESPboy.tft.println("Green text");
  
  myESPboy.tft.setTextColor(TFT_BLUE, TFT_BLACK);
  myESPboy.tft.println("Blue text");

  delay(5000);

}

void loop() {

  myESPboy.tft.invertDisplay( false ); // Where i is true or false
  myESPboy.tft.fillScreen(TFT_BLACK);
  myESPboy.tft.setCursor(0, 0);
  myESPboy.tft.setTextColor(TFT_WHITE, TFT_BLACK);
  myESPboy.tft.println("Invert OFF\n");
  myESPboy.tft.println("White text"); 

  myESPboy.tft.setTextColor(TFT_RED, TFT_BLACK);
  myESPboy.tft.println("Red text");
  
  myESPboy.tft.setTextColor(TFT_GREEN, TFT_BLACK);
  myESPboy.tft.println("Green text");
  
  myESPboy.tft.setTextColor(TFT_BLUE, TFT_BLACK);
  myESPboy.tft.println("Blue text");

  delay(5000);


  // Binary inversion of colours
  myESPboy.tft.invertDisplay( true ); // Where i is true or false
  myESPboy.tft.fillScreen(TFT_BLACK);
  myESPboy.tft.setCursor(0, 0);
  myESPboy.tft.setTextColor(TFT_WHITE, TFT_BLACK);
  myESPboy.tft.println("Invert ON\n");
  myESPboy.tft.println("White text");
  
  myESPboy.tft.setTextColor(TFT_RED, TFT_BLACK);
  myESPboy.tft.println("Red text");
  
  myESPboy.tft.setTextColor(TFT_GREEN, TFT_BLACK);
  myESPboy.tft.println("Green text");
  
  myESPboy.tft.setTextColor(TFT_BLUE, TFT_BLACK);
  myESPboy.tft.println("Blue text");

  delay(5000);
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
