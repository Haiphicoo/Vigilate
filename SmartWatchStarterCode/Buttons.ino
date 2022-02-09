// Button Functions

void initButtons() {
  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}

void updateButtons() {
  if (!isButton1) {
    for (int i = 0; i < 4; i++)  {
      buttons[i].update();
      if (buttons[i].rose()) {
        mode = i;
      }
      if (buttons[1].rose()) {
        isButton1 = true;
      }
    }
  }
  else {
    buttons[2].update();
    if (buttons[2].rose()) {
      //curHours = (curHours + 1) % 12;
      increaseHours ++;
    }
    buttons[3].update();
    if (buttons[3].rose()) {
      //curMinutes = (curMinutes + 5) % 60; //maybe go back later if you want to change it in incriments of 1 and 5
      increaseMinutes += 5;
    }
    buttons[0].update();
    if (buttons[0].rose()) {
      isButton1 = false;
      mode = 0;
    }
  }
}
