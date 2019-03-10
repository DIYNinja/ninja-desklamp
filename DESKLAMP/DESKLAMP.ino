
#include <ClickEncoder.h>
#include <TimerOne.h>
#include <EEPROM.h>

#define WARMPIN 6
#define COLDPIN 5

#define ENCODER_A A1
#define ENCODER_B A0
#define ENCODER_BTN A2
#define ENC_HALFSTEP
#define STEP_MULTIPLIER 5
#define BASE 100

bool settingMode = false;
bool switchON = true;

int brightnessValue = 0;
int whiteBalance = 0;
int last_brightnessValue, last_whiteBalance;

int coldValue, warmValue;

ClickEncoder *encoder;

void timerIsr() {
  encoder->service();
}




