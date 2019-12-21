#include <WS2811.h>
DEFINE_WS2811_FN(WS2811RGB, PORTB, 0)
RGB_t rgb[8] = { 0 }; //1 for 1 pixel

void ds(uint32_t seconds) { // delay some seconds
  for (uint32_t i = 0; i < seconds*2; i++) {
    delay(505);
  }
}

void setup() {                

  pinMode(0,OUTPUT);

  for (int i = 0; i < 8; i++) {
    // Blink all open
    for (int j = 0; j < 60; j += 1) {
      rgb[i].r = j;
      rgb[i].g = 0;
      rgb[i].b = j;

      updatePixels();
      blank(); blank(); blank();
    }
    blank(); blank();
  }

  delay(10);

  // Switch all off
  for (int j = 61; j != 0; j -= 1) {
    for (int i = 0; i < 8; i++) {
      rgb[i].r = j-1;
      rgb[i].b = j-1;
    }
    updatePixels();
    blank(); blank();
    delay(4);
  }


  // Set one led open as an indicator
  rgb[7] = {0,1,0};
  updatePixels();
  blank();

  // Wait ONE minute
  ds(53); // (actually fewer seconds to account for the initial delay)

  // Flash the BLUE light
  for (int j = 0; j < 60; j++) {
    rgb[0].b = j;

    updatePixels();
    blank();
  }

  // Reduce the brightness, it is too bright
  for (int j = 60; j >= 30; j--) {
    rgb[0].b = j;
    updatePixels();
    delay(10);
  }

  delay(500);

  // Reduce the brightness more, it is too bright
  for (int j = 30; j >= 1; j--) {
    rgb[0].b = j;
    updatePixels();
    delay(70);
  }

  ds(60-5); // WAIT another one minute

  // Flash the GREEN light
  for (int j = 0; j < 60; j++) {
    rgb[1].g = j;

    updatePixels();
    blank();
  }

  // Reduce the brightness, it is too bright
  for (int j = 60; j >= 30; j--) {
    rgb[1].g = j;
    updatePixels();
    delay(10);
  }

  delay(500);

  // Reduce the brightness more, it is too bright
  for (int j = 30; j >= 3; j--) {
    rgb[1].g = j;
    updatePixels();
    delay(70);
  }

  ds(60*3-5); // WAIT another 3 minutes

  // Flash the ORANGE light
  for (int j = 0; j < 255; j++) {
    rgb[2].r = j;
    rgb[2].g = j/4;
    rgb[3].r = j;
    rgb[3].g = j/4;

    updatePixels();
    blank();
  }

  // Flash once
  for (int f = 0; f < 5; f++) {
  for (int j = 255; j != 0; j--) {
    rgb[2].r = j;
    rgb[2].g = j/4;
    rgb[3].r = j;
    rgb[3].g = j/4;
    updatePixels();
    delay(2);
  }
  for (int j = 0; j <= 255; j++) {
    rgb[2].r = j;
    rgb[2].g = j/4;
    rgb[3].r = j;
    rgb[3].g = j/4;
    updatePixels();
    delay(2);
  }
  }
  for (int j = 255; j >= 20; j--) {
    rgb[2].r = j;
    rgb[2].g = j/4;
    rgb[3].r = j;
    rgb[3].g = j/4;
    updatePixels();
    delay(3);
  }
  delay(500);
  // Off the good lights
  rgb[0] = { 0,0,0 };
  rgb[1] = { 0,0,0 };
  updatePixels();
  blank();

  ds(60*10-6); // WAIT another 10 minutes

  // Flash once
  for (int f = 0; f < 3; f++) {
  for (int j = 255; j != 0; j--) {
    rgb[4].r = j;
    rgb[4].g = j/4;
    rgb[5].r = j;
    rgb[5].g = j/4;
    rgb[6].r = j;
    rgb[6].g = j/4;
    updatePixels();
    delay(5);
  }
  for (int j = 0; j <= 255; j++) {
    rgb[4].r = j;
    rgb[4].g = j/4;
    rgb[5].r = j;
    rgb[5].g = j/4;
    rgb[6].r = j;
    rgb[6].g = j/4;
    updatePixels();
    delay(5);
  }
  }
  for (int j = 255; j >= 60; j--) {
    rgb[4].r = j;
    rgb[4].g = j/4;
    rgb[5].r = j;
    rgb[5].g = j/4;
    rgb[6].r = j;
    rgb[6].g = j/4;
    updatePixels();
    delay(5);
  }

  // Last pixel is red
  rgb[7].r = 1;
  rgb[7].g = 0;
  updatePixels();
}

// Need to run this before every pixel update (reset pulse)
void blank() {
  for (volatile int t=0; t<50; t++) {}
}

void setPixel(uint8_t i, uint8_t r, uint8_t g, uint8_t b){
  rgb[i].r=r;
    rgb[i].g=g;
    rgb[i].b=b;
}

void updatePixels(){
  WS2811RGB(rgb, ARRAYLEN(rgb));
}


void loop() {
//  setPixel(0,255,0,0); //set first pixel (zero indexed) to red
//  setPixel(1,0,0,millis()); //set first pixel (zero indexed) to red
//  updatePixels(); //show the change


}
