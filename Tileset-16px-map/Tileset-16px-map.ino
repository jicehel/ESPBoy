/*

     Tile mapping demo for
           ESPBoy
         by Jicehel
         and Roman

 --------------------------------

  This prog will display a map
  on the screen (128 x 128 pixels)
  composed of a combination
  of 8 tiles of 16 x 16 pixels
  
*/


// Set delay after plotting the sprite
#define DELAY 20

// Width and height of tile (an element of the map)
#define WIDTH_TILE  16
#define HEIGHT_TILE 16

// Define the number of blocs used
#define X_TILES 8
#define Y_TILES 8

#include "image.h"
#include "ESPboyInit.h"

#define Tileset_size 160

ESPboyInit myESPboy;       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&myESPboy.tft);     // Declare Sprite object "spr" with pointer to "tft" object

uint16_t bit4palette[] = {TFT_BLACK, TFT_GREEN, TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_BROWN, TFT_BLUE, TFT_PURPLE, TFT_DARKGREY, TFT_WHITE, TFT_CYAN, TFT_MAGENTA, TFT_MAROON, TFT_DARKGREEN, TFT_NAVY, TFT_PINK};

char* table[] = {
  "11121123",
  "21111214",
  "11111114",
  "11211O13",
  "O1111113",
  "56665567",
  "21112113",
  "11211113",
};


void drawmap() {
  for(uint8_t i = 0; i < Y_TILES; i++) 
    for(uint8_t j = 0; j < X_TILES; j++)  
      spr.pushSprite(j * WIDTH_TILE, i * HEIGHT_TILE, (table[i][j] - '0') * WIDTH_TILE, 0, HEIGHT_TILE, 16);
}


void setup(){
  myESPboy.begin("Tile mapping");   //Set up the display
  spr.setColorDepth(4);
  spr.createPalette(bit4palette);
  spr.createSprite(Tileset_size, HEIGHT_TILE); // Create a sprite of defined size
  spr.pushImage(0, 0, Tileset_size, HEIGHT_TILE, (uint16_t *)tileset, 4);
  
  spr.pushSprite(0,0);
  delay(DELAY*100);
}


void loop(void){
  drawmap();

  for(uint8_t i = 0; i < Y_TILES; i++)
    for(uint8_t j = 0; j < X_TILES; j++) 
      table[j][i] = random(9)+'0';

  delay(DELAY*100);
}  
  
