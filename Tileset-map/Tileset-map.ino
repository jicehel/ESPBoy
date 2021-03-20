/*

     Tile mapping demo for
           ESPBoy
         by Jicehel

 --------------------------------

  This prog will display a map
  on the screen (128 x 128 pixels)
  composed of a combination
  of 10 tiles of 16 x 16 pixels
  
*/


// Set delay after plotting the sprite
#define DELAY 20

// Width and height of tile (an element of the map)
#define WIDTH_TILE  16
#define HEIGHT_TILE 16

// Define the number of blocs used
#define BLOCS_USED_FOR_WIDTH 7
#define BLOCS_USED_FOR_HEIGHT 7

// Animation delay between two frames
#define ANIM_FRAME_DELAY 5

#include "image.h"
#include "ESPboyInit.h"

ESPboyInit myESPboy;       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&myESPboy.tft);     // Declare Sprite object "spr" with pointer to "tft" object

uint16_t bit4palette[] = {TFT_BLACK, TFT_GREEN, TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_BROWN, TFT_BLUE, TFT_PURPLE, TFT_DARKGREY, TFT_WHITE, TFT_CYAN, TFT_MAGENTA, TFT_MAROON, TFT_DARKGREEN, TFT_NAVY, TFT_PINK};

char* table[] = {
  "1213211",
  "1123112",
  "4445161",
  "1123789",
  "21132A1",
  "6213112",
  "8923121"
};

void drawmap() {
  uint8_t i,j;
  uint8_t nb;
  
  for(i=0;i<BLOCS_USED_FOR_WIDTH;i++) 
    { 
        for(j=0;j<BLOCS_USED_FOR_HEIGHT;j++) 
        { 
            nb = table[j][i] - '0';
            if (nb > 34) nb = nb - 25;
            spr.pushImage(-16, 0, nb * 16, 16, tileset);
            spr.pushSprite(i*1,j°16,16);
        } 
    } 
}

void setup(){
  myESPboy.begin("Tile mapping");   //Set up the display
  spr.setColorDepth(4);
  spr.createSprite(WIDTH_TILE, HEIGHT_TILE); // Create a sprite of defined size
  spr.createPalette(bit4palette); 
}

void nextSetp(void){
  // nothing to do at the moment
}


void draw(void){
  drawmap();
}

void loop(void){

  draw();
  delay(DELAY);
}
