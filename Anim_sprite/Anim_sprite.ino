/*

  Anim sprite demo for
       ESPBoy
     by Jicehel
  
   Thanks to Roman,
 FManga, tuxinator2009
   for their help

*/


// Set delay after plotting the sprite
#define DELAY 20

// Width and height of sprite
#define WIDTH  16
#define HEIGHT 16
#define ANIM_FRAME_DELAY 5


#include "image.h"
#include "ESPboyInit.h"

ESPboyInit myESPboy;       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&myESPboy.tft);  // Declare Sprite object "spr" with pointer to "tft" object
TFT_eSprite eraser = TFT_eSprite(&myESPboy.tft);  // Declare Sprite object "eraser" with pointer to "tft" object to clean black background

uint16_t bit4palette[] = {TFT_BLACK, TFT_GREEN, TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_BROWN, TFT_BLUE, TFT_PURPLE, TFT_DARKGREY, TFT_WHITE, TFT_CYAN, TFT_MAGENTA, TFT_MAROON, TFT_DARKGREEN, TFT_NAVY, TFT_PINK};

uint16_t* framesUp[] = {(uint16_t *)up_1, (uint16_t *)up_2, (uint16_t *)up_3};
uint16_t* framesDown[] = {(uint16_t *)bottom_1,(uint16_t *)bottom_2,(uint16_t *)bottom_3};
uint16_t* framesLeft[] = {(uint16_t *)left_1, (uint16_t *)left_2};
uint16_t* framesRight[] = {(uint16_t *)right_1, (uint16_t *)right_2};


void setup(){
  myESPboy.begin("Anim sprite");   //Set up the display
  spr.setColorDepth(4);
  spr.createSprite(WIDTH, HEIGHT); // Create a sprite of defined size
  eraser.createSprite(WIDTH, HEIGHT); // Create a sprite of defined size
  spr.createPalette(bit4palette); 
  eraser.createPalette(bit4palette); 
  spr.pushImage(0,0,WIDTH, HEIGHT,framesDown[0]);
  eraser.fillSprite(TFT_BLACK);
  
  myESPboy.tft.fillScreen(TFT_BLACK); // Clear the TFT screen to black
}


void loop(void){
 static int16_t cx=0, cy=0, dx=0, dy=0;
 static uint8_t keypressed, frameno, framecount;
  
 dx=0; dy=0;

 keypressed = myESPboy.getKeys();

 if (keypressed) {
    if (framecount > ANIM_FRAME_DELAY){
      framecount=0;
      frameno++;
    }
    else framecount++;
    
    if (keypressed&PAD_LEFT && cx>0) {
      dx=-1;
      if (frameno >= sizeof(framesLeft)/sizeof(uint16_t*)) frameno=0;
      spr.pushImage(0,0,WIDTH, HEIGHT,framesLeft[frameno]);
    }
    
    if (keypressed&PAD_RIGHT && cx<128-WIDTH) {
      dx=1;
      if (frameno >= sizeof(framesRight)/sizeof(uint16_t*)) frameno=0;
      spr.pushImage(0,0,WIDTH, HEIGHT,framesRight[frameno]);
    }
    
    if (keypressed&PAD_UP && cy>0) {
      dy=-1;
      if (frameno >= sizeof(framesUp)/sizeof(uint16_t*)) frameno=0;
      spr.pushImage(0,0,WIDTH, HEIGHT,framesUp[frameno]);
    }
    
    if (keypressed&PAD_DOWN && cy<128-HEIGHT) {
      dy=1;
      if (frameno >= sizeof(framesDown)/sizeof(uint16_t*)) frameno=0;
      spr.pushImage(0,0,WIDTH, HEIGHT,framesDown[frameno]);
    }
  }
 else framecount=0;
  eraser.pushSprite(cx, cy, 10);
  cx+=dx;
  cy+=dy;
  spr.pushSprite(cx, cy, 10);

  delay(DELAY);
}
