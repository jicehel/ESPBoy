/*

  Sketch to show how a Sprite can use a four-bit image with
  a palette to change the appearance of an image while rendering
  it only once.

  Example for library:   https://github.com/Bodmer/TFT_eSPI

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
#define DELAY 30

// Width and height of sprite
#define WIDTH  80
#define HEIGHT 30

#include "Image.h"
#include "ESPboyInit.h"

ESPboyInit myESPboy;       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&myESPboy.tft);  // Declare Sprite object "spr" with pointer to "tft" object

byte red = 31; // Red is the top 5 bits of a 16 bit colour value
byte green = 0;// Green is the middle 6 bits
byte blue = 0; // Blue is the bottom 5 bits
byte state = 0;

int rloop = 0;
int incr = 1;

int16_t cx, cy=0, dx=1, dy=1;
uint16_t cmap[16];

void setup()
{

 
  //Set up the display
  myESPboy.begin("Sprite_image_4bit");
  
  spr.setColorDepth(4);

  // Create a sprite of defined size
  spr.createSprite(WIDTH, HEIGHT);

  // Clear the TFT screen to black
  myESPboy.tft.fillScreen(TFT_BLACK);
  
  // push the image - only need to do this once.
  spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)Image);

  // set initial position of the sprite
  cx = (myESPboy.tft.width()- WIDTH) / 2;
  cy = (myESPboy.tft.height()- HEIGHT) / 2;

  // set move initial direction
  dx=1; 
  dy=1;

  cmap[0] = 0;
  for (int i = 1; i < 16; i++)
    cmap[i] = rainbow();
    
}


void loop(void)
{
  // create a palette with the defined colors and push it.  
  spr.createPalette(cmap);
  spr.pushSprite(cx, cy);
  
  // update the colors
  for (int i = 1; i < 15; i++) 
    cmap[i] = cmap[i + 1];
 
  if (incr == 2)
    (void)rainbow();  // skip alternate steps to go faster
  
  cmap[15] = rainbow();
  rloop += incr;
  if (rloop > 0xc0) {
    incr = incr == 2 ? 1 : 2;
    rloop = 0;
  }

  // update position
  cx+=dx;
  cy+=dy;
  if(cx > 128 - WIDTH  || cx < 1) dx=-dx;
  if(cy > 128 - HEIGHT || cy < 1) dy=-dy;
  
  delay(DELAY);

}

// #########################################################################
// Return a 16 bit rainbow colour
// #########################################################################
unsigned int rainbow()
{
    switch (state) {
      case 0:
        green ++;
        if (green == 64) {
          green = 63;
          state = 1;
        }
        break;
      case 1:
        red--;
        if (red == 255) {
          red = 0;
          state = 2;
        }
        break;
      case 2:
        blue ++;
        if (blue == 32) {
          blue = 31;
          state = 3;
        }
        break;
      case 3:
        green --;
        if (green == 255) {
          green = 0;
          state = 4;
        }
        break;
      case 4:
        red ++;
        if (red == 32) {
          red = 31;
          state = 5;
        }
        break;
      case 5:
        blue --;
        if (blue == 255) {
          blue = 0;
          state = 0;
        }
        break;
    }
    return red << 11 | green << 5 | blue;
}
