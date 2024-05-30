#define LED_UPDATE_SPEED 9 // Update Speed in ms, around 110fps

int lastDrawAt = 0; // when the last draw occured

void setup() {
  init();
}

void loop() {
  if (milis() > lastDrawAt + LED_UPDATE_SPEED) {
    lastDrawAt = milis();
    draw();
  }

  update();
}