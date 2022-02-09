// Modes

long sleepTimer = 0;
long sleepInterval = 5000;

////timer variables for personal functions
unsigned long startTime = millis();
unsigned long endTime;
int interval = 2000;

// index variable
int stripIndex = 0;


void fallAsleep() {
  if (millis() - sleepTimer > sleepInterval) {
    strip.clear(); strip.show();  // Clear out NeoPixel Display
    snore(5000);                 // Go to Sleep for 5 Seconds
    sleepTimer = millis();
  }
}

void updateTime() {
  curSeconds = (millis() / (1000 / timeWarp)) % 60;  //change the 1000 before Wednesday to a small #
  curMinutes = ((millis() / (60000 / timeWarp)) + (increaseMinutes)) % 60; // Normally 60000
  curHours = ((millis() / (3600000 / timeWarp)) + (increaseHours)) % 12;  // Normally 3600000
}


void displayTime() {
  int minLed = map(curMinutes, 0, 60, 0, 12);
  strip.clear();
  strip.setPixelColor(minLed, 0, 0, 255);
  strip.setPixelColor(curHours, 255, 0, 0);
  strip.show();
}


void setTime() {
  if (buttons[1].rose()) {
    mode = 1;
  }
}

void changeTime() {
  strip.clear();
  strip.show();
  int minLed = map(curMinutes, 0, 60, 0, 12);
  strip.clear();
  strip.setPixelColor(minLed, 255, 0, 255);
  strip.setPixelColor(curHours, 255, 165, 0);
  strip.show();
}


//ijumprope function
void jumpRope() {
  //update endTime
  endTime = millis();

  //timer if statement
  if (endTime - startTime >= interval) {

    strip.setPixelColor(stripIndex, 0, 255, 0);
    stripIndex += 1;
    strip.show();
    startTime = millis();
  }
  if (stripIndex > 12) {
    mode = -1;
    stripIndex = 0;
  }
}


void flashLight() {
  strip.clear();
  
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 255, 255);
    strip.setBrightness(15);
    strip.show();
    strip.show(); 
  }
  buttons[1].update();
  if (buttons[1].rose()) {
    mode = -1;
  }
}
