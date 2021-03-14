/*



*/


// Set delay after plotting the sprite
#define DELAY 20

// Width and height of sprite
#define WIDTH  16
#define HEIGHT 16

#include "image.h"
#include "ESPboyInit.h"

// Define direction values
#define DOWN  1
#define UP    2
#define LEFT  3
#define RIGHT 4
#define NO_MOVE 0

ESPboyInit myESPboy;       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&myESPboy.tft);  // Declare Sprite object "spr" with pointer to "tft" object

uint16_t bit4palette[] = { TFT_DARKGREEN, TFT_WHITE, TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_BROWN, TFT_BLUE, TFT_PURPLE, TFT_DARKGREY, TFT_BLACK, TFT_CYAN, TFT_MAGENTA, TFT_MAROON, TFT_GREEN, TFT_NAVY, TFT_PINK};
uint8_t moveSprite, animSprite;

void setup(){
  
  //Set up the display
  myESPboy.begin("Anim sprite");
  
  spr.setColorDepth(4);

  // Create a sprite of defined size
  spr.createSprite(WIDTH, HEIGHT);
  
  // push the image - only need to do this once.
  spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)bottom_1);
  moveSprite = NO_MOVE;
  animSprite = 0;
 
  spr.createPalette(bit4palette); 

  // Clear the TFT screen to black
  myESPboy.tft.fillScreen(TFT_BLACK);
}


void loop(void){
  static int16_t cx=0, cy=0, dx=0, dy=0;
  uint8_t keypressed;

  // No move if no key pressed
  dx=0;
  dy=0;

 if (keypressed) {
    if (keypressed&PAD_LEFT){
      if (moveSprite == NO_MOVE){
        moveSprite = LEFT;
        animSprite = 0;
      } else {
          if (moveSprite == LEFT){
             switch (animSprite) {

                case 0:
                    animSprite = 1;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)left_1);
                    break;
                    
                case 1:
                    animSprite = 0;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)left_2);
                    break;
             }
             if (cx > 0) dx = -2; 
                else dx = 0;
          } else {
              moveSprite = NO_MOVE;  
          }
      }
    }
    if (keypressed&PAD_RIGHT){
      if (moveSprite == NO_MOVE){
        moveSprite = RIGHT;
        animSprite = 0;
      } else {
          if (moveSprite == RIGHT){
             switch (animSprite) {

                case 0:
                    animSprite = 1;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)left_1);
                    break;
                    
                case 1:
                    animSprite = 0;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)left_2);
                    break;
             }
             if (cx > 1) dx = -2; 
                else dx = 0;
          } else {
              moveSprite = NO_MOVE;  
          }
      }
    }
    
    if (keypressed&PAD_UP){
      if (moveSprite == NO_MOVE){
        moveSprite = UP;
        animSprite = 0;
      } else {
          if (moveSprite == UP){
             switch (animSprite) {

                case 0:
                    animSprite = 1;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)up_1);
                    break;
                    
                case 1:
                    animSprite = 0;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)up_2);
                    break;
                    
                case 2:
                    animSprite = 0;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)up_3);
                    break;
             }
             if (cy > 1) dy = -2; 
                else dy = 0;
          } else {
              moveSprite = NO_MOVE;  
          }
      }
    }
    if (keypressed&PAD_DOWN){
      if (moveSprite == NO_MOVE){
        moveSprite = DOWN;
        animSprite = 0;
      } else {
          if (moveSprite == DOWN){
             switch (animSprite) {

                case 0:
                    animSprite = 1;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)bottom_1);
                    break;
                    
                case 1:
                    animSprite = 2;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)bottom_2);
                    break;
                    
                case 2:
                    animSprite = 0;
                    spr.pushImage(0, 0, WIDTH, HEIGHT, (uint16_t *)bottom_3);
                    break;
             }
             if (cy > 127 - HEIGHT) dy = 2; 
                else dy = 0;
          } else {
              moveSprite = NO_MOVE;  
          }
      }
    }
 }
  
  cx+=dx;
  cy+=dy;
  spr.pushSprite(cx, cy);

  delay(DELAY);
}
