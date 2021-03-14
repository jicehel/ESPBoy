/*

  Sketch to show how a Sprite can use a four-bit image.

  A Sprite is notionally an invisible graphics screen that is
  kept in the processors RAM. Graphics can be drawn into the
  Sprite just as it can be drawn directly to the screen. Once
  the Sprite is completed it can be plotted onto the screen in
  any position. If there is sufficient RAM then the Sprite can
  be the same size as the screen and used as a frame buffer.

  A 16 bit Sprite occupies (2 * width * height) bytes in RAM.

  On a ESP8266 Sprite sizes up to 126 x 160 can be accomodated,
  this size requires 40kBytes of RAM for a 16 bit color depth.
  
  When 8 bit color depth sprites are created they occupy
  (width * height) bytes in RAM, so larger sprites can be
  created, or the RAM required is halved.

*/


// Set delay after plotting the sprite
#define DELAY 20

// Width and height of sprite
#define WIDTH  80
#define HEIGHT 30

#include "image.h"
#include "ESPboyInit.h"

ESPboyInit myESPboy;       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&myESPboy.tft);  // Declare Sprite object "spr" with pointer to "tft" object

uint16_t bit4palette[] = { TFT_DARKGREEN, TFT_WHITE, TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_BROWN, TFT_BLUE, TFT_PURPLE, TFT_DARKGREY, TFT_BLACK, TFT_CYAN, TFT_MAGENTA, TFT_MAROON, TFT_GREEN, TFT_NAVY, TFT_PINK};


void setup(){
  
  //Set up the display
  myESPboy.begin("Sprite 4bit demo");
  
  spr.setColorDepth(4);

  // Create a sprite of defined size
  spr.createSprite(WIDTH, HEIGHT);
  
  // push the image - only need to do this once.
  spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)image);
  
  spr.drawFastVLine(0, 0, HEIGHT, 9);
  spr.drawFastVLine(WIDTH-1, 0, HEIGHT, 9);
  spr.drawFastHLine(0, 0, WIDTH, 9);
  spr.drawFastHLine(0,HEIGHT-1, WIDTH, 9);  
 
  spr.createPalette(bit4palette); 

  // Clear the TFT screen to black
  myESPboy.tft.fillScreen(TFT_BLACK);
}


void loop(void){
  static int16_t cx=0, cy=0, dx=1, dy=1;
  
  spr.pushSprite(cx, cy);
  
  cx+=dx;
  cy+=dy;
  if(cx>128-WIDTH || cx<1) dx=-dx;
  if(cy>128-HEIGHT || cy<1) dy=-dy;

  delay(DELAY);
}
