#include <Adafruit_NeoPixel.h>
#include "change_pattern_button.h"
#include "pattern_k2000.h"
#include "pattern_thunderbolt.h"
#include "pattern_pacman.h"
#include "pattern_ocean.h"
#include "pattern_french.h"
#include "pattern_reset.h"

#define BUTTON_PIN 6
#define NEOPIXEL_PIN 9
#define NEOPIXEL_COUNT 30

// Lights patterns
const byte _k2000 = 0x0; // bouncy red lights
const byte _thunderbolt = 0x1; // green flashing lights
const byte _pacman = 0x2; // three animated yellow points
const byte _ocean = 0x3; // fading blue light
const byte _french = 0x4; // french flag lights
const byte _reset = 0x5; // screen off

// Neopixels
Adafruit_NeoPixel _strip = Adafruit_NeoPixel(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
int _state_pattern = 0;
byte _current_pattern = _k2000;

/*************************
  Main section
*************************/
void setup() {
  ChangePatternButton.setup(BUTTON_PIN);
  
  PatternK2000.setup(_strip, NEOPIXEL_COUNT);
  PatternThunderbolt.setup(_strip, NEOPIXEL_COUNT);
  PatternPacman.setup(_strip, NEOPIXEL_COUNT);
  PatternOcean.setup(_strip, NEOPIXEL_COUNT);
  PatternFrench.setup(_strip);
  PatternReset.setup(_strip, NEOPIXEL_COUNT);

  _strip.begin();
  for (int i = 0; i < NEOPIXEL_COUNT; i++) {
    _strip.setPixelColor(i, _strip.Color(0, 0, 0));
  }
  _strip.show();
}

void loop() {
  checkPatternState();
  showPatternMode();
}

void checkPatternState() {
  bool shouldChange = ChangePatternButton.isButtonPressed();
  if (shouldChange) {
    PatternReset.show();

    changePatternMode();
  }
}

void changePatternMode() {
  _state_pattern++;

  if (_state_pattern > 5) {
    _state_pattern = 0;
  }

  switch (_state_pattern) {
    case 0:
      _current_pattern = _k2000;
      break;
    case 1:
      _current_pattern = _thunderbolt;
      break;
    case 2:
      _current_pattern = _pacman;
      break;
    case 3:
      _current_pattern = _ocean;
      break;
    case 4:
      _current_pattern = _french;
      break;
    default:
      _current_pattern = _reset;
      break;
  }
}

void showPatternMode() {
  switch (_current_pattern) {
    case _k2000:
      PatternK2000.show();
      break;
    case _thunderbolt:
      PatternThunderbolt.show();
      break;
    case _pacman:
      PatternPacman.show();
      break;
    case _ocean:
      PatternOcean.show();
      break;
    case _french:
      PatternFrench.show();
      break;
    default:
      PatternReset.show();
      break;
  }
}
