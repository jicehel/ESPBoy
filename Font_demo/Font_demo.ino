/*
  This sketch is the same as the Font_Demo_1 example, except the fonts in this
  example are in a FLASH (program memory) array. This means that processors
  such as the STM32 series that are not supported by a SPIFFS library can use
  smooth (anti-aliased) fonts.
*/

/*
  There are four different methods of plotting anti-aliased fonts to the screen.

  This sketch uses method 1, using tft.print() and tft.println() calls.

  In some cases the sketch shows what can go wrong too, so read the comments!
  
  The font is rendered WITHOUT a background, but a background colour needs to be
  set so the anti-aliasing of the character is performed correctly. This is because
  characters are drawn one by one.
  
  This method is good for static text that does not change often because changing
  values may flicker. The text appears at the tft cursor coordinates.

  It is also possible to "print" text directly into a created sprite, for example using
  spr.println("Hello"); and then push the sprite to the screen. That method is not
  demonstrated in this sketch.
  
*/

//  A processing sketch to create new fonts can be found in the Tools folder of TFT_eSPI
//  https://github.com/Bodmer/TFT_eSPI/tree/master/Tools/Create_Smooth_Font/Create_font

#include "Smooth_font.h"
#include "ESPboyInit.h"

// Include fonts
#include "NotoSansBold15.h"
#include "NotoSansBold36.h"

// The font names are arrays references, thus must NOT be in quotes ""
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36

ESPboyInit myESPboy;       // Invoke custom library

void setup()   {
  //Set up the display
  myESPboy.begin("Colour_Test");
}

void loop() {

  myESPboy.tft.fillScreen(TFT_BLACK);  
  myESPboy.tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Set the font colour AND the background colour
                                                    // so the anti-aliasing works
  myESPboy.tft.setCursor(0, 0);                     // Set cursor at top left of screen

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Small font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  myESPboy.tft.loadFont(AA_FONT_SMALL);    // Must load the font first
  myESPboy.tft.println("Small 15pt font"); // println moves cursor down for a new line
  myESPboy.tft.println(); // New line
  myESPboy.tft.print("ABC"); // print leaves cursor at end of line
  myESPboy.tft.setTextColor(TFT_CYAN, TFT_BLACK);
  myESPboy.tft.println("1234"); // Added to line after ABC
  myESPboy.tft.setTextColor(TFT_YELLOW, TFT_BLACK);
 
  int ivalue = 1234;
  myESPboy.tft.println(ivalue);       // print as an ASCII-encoded decimal
  myESPboy.tft.println(ivalue, DEC);  // print as an ASCII-encoded decimal
  myESPboy.tft.println(ivalue, HEX);  // print as an ASCII-encoded hexadecimal
  myESPboy.tft.println(ivalue, OCT);  // print as an ASCII-encoded octal
  myESPboy.tft.println(ivalue, BIN);  // print as an ASCII-encoded binary

  myESPboy.tft.println(); // New line
  myESPboy.tft.setTextColor(TFT_MAGENTA, TFT_BLACK);
  
  float fvalue = 1.23456;
  myESPboy.tft.println(fvalue, 0);  // no decimal places
  myESPboy.tft.println(fvalue, 1);  // 1 decimal place
  myESPboy.tft.println(fvalue, 2);  // 2 decimal places
  myESPboy.tft.println(fvalue, 5);  // 5 decimal places

  delay(5000);

  // Get ready for the next demo while we have this font loaded
  myESPboy.tft.fillScreen(TFT_BLACK);
  myESPboy.tft.setCursor(0, 0); // Set cursor at top left of screen
  myESPboy.tft.setTextColor(TFT_WHITE, TFT_BLACK);
  myESPboy.tft.println("Wrong and right ways to");
  myESPboy.tft.println("print changing values...");

  myESPboy.tft.unloadFont(); // Remove the font to recover memory used


  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  myESPboy.tft.loadFont(AA_FONT_LARGE); // Load another different font

  //tft.fillScreen(TFT_BLACK);
  
  // Draw changing numbers - does not work unless a filled rectangle is drawn over the old text
  for (int i = 0; i <= 20; i++)
  {
    myESPboy.tft.setCursor(50, 50);
    myESPboy.tft.print("      "); // Overprinting old number with spaces DOES NOT WORK!
    myESPboy.tft.setTextColor(TFT_GREEN, TFT_BLACK);
    myESPboy.tft.setCursor(50, 50);
    myESPboy.tft.print(i / 10.0, 1);

    myESPboy.tft.fillRect (50, 90, 60, 40, TFT_BLACK); // Overprint with a filled rectangle
    myESPboy.tft.setTextColor(TFT_GREEN, TFT_BLACK);
    myESPboy.tft.setCursor(50, 90);
    myESPboy.tft.print(i / 10.0, 1);  
  }
  delay(5000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font text wrapping
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  myESPboy.tft.fillScreen(TFT_BLACK);
  myESPboy.tft.setTextColor(TFT_YELLOW, TFT_BLACK); // Change the font colour and the background colour
  myESPboy.tft.setCursor(0, 0); // Set cursor at top left of screen
  myESPboy.tft.println("Large font!");
  myESPboy.tft.setTextWrap(true); // Wrap on width
  myESPboy.tft.setTextColor(TFT_CYAN, TFT_BLACK);
  myESPboy.tft.println("Long lines wrap to the next line");
  myESPboy.tft.setTextWrap(false, false); // Wrap on width and height switched off
  myESPboy.tft.setTextColor(TFT_MAGENTA, TFT_BLACK);
  myESPboy.tft.println("Unless text wrap is switched off");
  myESPboy.tft.unloadFont(); // Remove the font to recover memory used
  delay(8000);  
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
