#include <driver/dac.h>

#define rest 0

int melody[] = {
  130, 100,
  rest, 100,
  130, 100,
  rest, 100,
  500, 100,
  rest, 200,
  300, 100,
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;

void setup() {
  // Serial.begin(9600);
  // pinMode(DAC_CHANNEL_1, pinMode);
  dac_output_enable(DAC_CHANNEL_1);
  dac_cw_generator_enable();
}

int musicCounter = 0;
void loop() {
  if (musicCounter >= notes) {
    musicCounter == 0;
  }

  int noteDuration = melody[musicCounter*2+1];
 
  playTone(melody[musicCounter*2], noteDuration * 0.9);
  playTone(0, noteDuration * 0.1);

  musicCounter += 1;
}

void playTone(uint32_t freq, uint32_t duration) {
  setFrequency(freq);
  dac_cw_generator_enable();
  delay(duration);
  dac_cw_generator_disable();
}

void setFrequency(uint32_t freq) {
  dac_cw_config_t cfg = {
    en_ch: DAC_CHANNEL_1,
    scale: DAC_CW_SCALE_8,
    phase: DAC_CW_PHASE_0,
    freq: freq,
    offset: 0,
  };

  dac_cw_generator_config(&cfg);
}