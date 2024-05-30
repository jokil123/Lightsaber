#include <Adafruit_NeoPixel.h>

// #define BUILTIN_LED 8

 

// the setup function runs once when you press reset or power the board
void setup() {
  // // Serial.begin(9600);
  // pinMode(BUTTON_0_PIN, INPUT);
  // pinMode(BUTTON_1_PIN, INPUT);
  // // pinMode(BUILTIN_LED, OUTPUT);
  // WS2812B.begin();
}

void loop() {
  // for (int i = 0; i < NUM_PIXELS; i += 3) {
  //   WS2812B.clear();
  //   WS2812B.fill(WS2812B.Color(255, 0, 0), i, 5);
  //   WS2812B.show();
  // }
  // WS2812B.fill(WS2812B.Color(255, 0, 0), 0, 287);
  // WS2812B.show();
  // WS2812B.fill(WS2812B.Color(0, 255, 0), 0, 287);
  // WS2812B.show();
  // WS2812B.fill(WS2812B.Color(0, 0, 255), 0, 287);
  // WS2812B.show();

  // digitalWrite(BUILTIN_LED, digitalRead(BUTTON_0_PIN));
  // // if button isn't pressed return
  // if (digitalRead(BUTTON_0_PIN) == LOW) return;
  // Serial.println("Toggled");
  // Serial.println(saberExtended);

  // // if saber is not extended, extend it.
  // if (!saberExtended) {
  //   Serial.println("Saber Extending");
  //   panColor(0, 1, saberColor, 0.25);
  //   Serial.println("Done");
  //   saberExtended = true;
  // } else {
  //   Serial.println("Saber Retracting");
  //   panColor(1, 0, SABER_OFF_COLOR, 0.25);
  //   Serial.println("Done");
  //   saberExtended = false;
  // }

  // delay(250);
}

// switches leds from to in the color over time seconds
void panColor(float from, float to, uint32_t color, float time) {
  int fromIndex = round((NUM_PIXELS - 1) * from);
  int toIndex = round((NUM_PIXELS - 1) * to);

  int deltaIndex = toIndex - fromIndex;
  int pixelCount = abs(deltaIndex);
  float deltaTime = time / pixelCount;
  int deltaTimeMicroS = round(deltaTime * 1000000);
  int stepDirection = sign(deltaIndex);

  // WS2812B.clear();

  for (int i = 0; i <= pixelCount; i++) {
    int ledIndex = fromIndex + i * stepDirection;
    WS2812B.setPixelColor(ledIndex, color);
    WS2812B.show();
    delayMicroseconds(deltaTimeMicroS);
  }

  // WS2812B.show();

  Serial.println("");
}

template<typename T> int sign(T val) {
  return (T(0) < val) - (val < T(0));
}
