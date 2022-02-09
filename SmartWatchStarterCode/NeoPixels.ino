// NeoPixel Functions

void initNeopixels(){
  strip.begin();
  strip.clear();
  strip.show();
  strip.setBrightness(15);
}

void allNeopixels(int c){
  for (int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, Wheel(c));
  }
  strip.show();
  mode = -1;
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
