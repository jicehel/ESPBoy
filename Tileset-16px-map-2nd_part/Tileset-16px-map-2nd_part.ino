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

#include "image.h"
#include "ESPboyInit.h"

ESPboyInit myESPboy;       // Invoke custom library

typedef struct {
 uint8_t  x;
 uint8_t  y;
 bool     passable;
} TileProperties;

typedef struct {
   uint8_t      WIDTH_TILE, HEIGHT_TILE;
   uint16_t     X_TILES_WORLD, Y_TILES_WORLD;
   uint8_t      X_TILES_SHOWN, Y_TILES_SHOWN;
   TFT_eSprite  tileset = TFT_eSprite(&myESPboy.tft);     // Declare Sprite object "tileset" with pointer to "tft" object
   uint16_t     TILESET_SIZE;
   TileProperties* props;
   char**       level;
} Map;

Map* m;


uint16_t bit4palette[] = {TFT_BLACK, TFT_GREEN, TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_BROWN, TFT_BLUE, TFT_PURPLE, TFT_DARKGREY, TFT_WHITE, TFT_CYAN, TFT_MAGENTA, TFT_MAROON, TFT_DARKGREEN, TFT_NAVY, TFT_PINK};

char* table[] = {
  "12132111",
  "11231121",
  "44452662",
  "11239887",
  "21132AA1",
  "62131121",
  "87232112",
  "A1231111",
};

bool tile_passable[] = {true,true,true,true,true,true,true,false,true,true};



void drawmap() {
  uint8_t nb;
  for(uint8_t i = 0; i < m->Y_TILES_SHOWN; i++) {
    for(uint8_t j = 0; j < m->X_TILES_SHOWN; j++) { 
      nb = m->level[i][j] - '0';
      if (nb > 10) nb = nb - 7;
      m->tileset.pushSprite(j * m->WIDTH_TILE, i * m->HEIGHT_TILE, (nb - 1) * m->WIDTH_TILE, 0, m->WIDTH_TILE, m->HEIGHT_TILE);
    } 
  } 
}



void setup(){
  uint8_t temp;
  m->TILESET_SIZE = 160;
  m->WIDTH_TILE   = 16;
  m->HEIGHT_TILE  = 16;
  m->X_TILES_WORLD = 8;
  m->Y_TILES_WORLD = 8;
  m->X_TILES_SHOWN = 8;
  m->Y_TILES_SHOWN = 8;

  for(uint8_t i = 0; i < m->Y_TILES_WORLD; i++) {
    for(uint8_t j = 0; j < m->X_TILES_WORLD; j++) { 
      m->level[i][j] = table[i][j];
    } 
  } 

  temp = m->TILESET_SIZE / m->WIDTH_TILE;

  for(uint8_t i = 0; i < temp; i++) {
    
  }
  
  myESPboy.begin("Tile mapping");   //Set up the display
  m->tileset.setColorDepth(4);
  m->tileset.createPalette(bit4palette); 
  m->tileset.createSprite(m->TILESET_SIZE, m->HEIGHT_TILE); // Create a sprite of defined size
  m->tileset.pushImage(0, 0, m->TILESET_SIZE, m->HEIGHT_TILE, (uint16_t *)tileset, 16);
  
  // spr.pushSprite(0,0);
}



void loop(void){

  drawmap();
  delay(DELAY*100);
}   
