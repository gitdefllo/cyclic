class PatternPacman {

#define PATTERN_NEOPIXEL_SIZE 7

private:
  const int _colors[PATTERN_NEOPIXEL_SIZE][3] = {
    { 0, 0, 0 }, { 217, 225, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
    { 217, 225, 0 }, { 0, 0, 0 }, { 217, 225, 0 },
  };
  const int _delay = 10;
  Adafruit_NeoPixel _strip;
  int _neopixel_count;

  bool shouldStop() {
    return ChangePatternButton.isButtonPressed();
  }
  
  void animate(int i) {
    _strip.setPixelColor(i+9, _strip.Color(0, 0, 0));
    _strip.setPixelColor(i+10, _strip.Color(217, 225, 0));
    _strip.setPixelColor(i+7-_neopixel_count, _strip.Color(0, 0, 0));
    _strip.setPixelColor(i+8-_neopixel_count, _strip.Color(217, 225, 0));
  }

  void reverse(int i) {
    _strip.setPixelColor(_neopixel_count-i+1, _strip.Color(0, 0, 0));
    _strip.setPixelColor(_neopixel_count-i, _strip.Color(217, 225, 0));
  }

public:
  void setup(Adafruit_NeoPixel strip, int neopixel_count) {
    _strip = strip;
    _neopixel_count = neopixel_count;
  }

  void show() {
    for (int i = 0; i < _neopixel_count + 2; i++) {
      if (shouldStop()) {
        break;
      }
  
      animate(i);
      reverse(i);
      _strip.show();
      delay(_delay);
    }
  }
};
PatternPacman PatternPacman;
