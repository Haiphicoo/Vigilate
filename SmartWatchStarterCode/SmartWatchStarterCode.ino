
// States
#include "tinysnore.h"  // Include TinySnore Library
int mode = -1;          // -1: Sleep || 0 - Red || 1 - Green || 2 - Blue || 3 - Pink

// NeoPixels
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(12, 0, NEO_GRB + NEO_KHZ800);

// Buttons
#include <Bounce2.h>
int buttonPins[4] = {1, 2, 3, 4};
Bounce * buttons = new Bounce[4];

// Time
int curHours = 0;
int curMinutes = 0;
int curSeconds = 0;
int timeWarp = 100; // Normally 1, Increase by 100x for demonstration purposes
int increaseMinutes = 0;
int increaseHours = 0;
boolean isButton1; 

void setup() {
  initButtons();
  initNeopixels();
}

void loop() {
  updateTime();
  updateButtons();
 // displayTime();
  setTime();
//  goFast();

  switch (mode) {
    case -1: fallAsleep(); break;
    case 0: displayTime(); break;
    case 1: changeTime(); break;
    case 2: flashLight(); break;
    case 3: jumpRope(); break;
  }
}
