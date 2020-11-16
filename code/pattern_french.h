class PatternFrench {

#define PATTERN_NEOPIXEL_SIZE 3

private:
  const int _colors[PATTERN_NEOPIXEL_SIZE][3] = {
    { 0, 0, 255 }, { 255,255,255 }, { 255, 0, 0 }
  };
  const int _delay = 10;
  Adafruit_NeoPixel _strip;
  
public:
  void setup(Adafruit_NeoPixel strip) {
    _strip = strip;
  }
  
  void show() {
    int r = _colors[0][0];
    int g = _colors[0][1];
    int b = _colors[0][2];

    for (int i = 0; i < 10; i++) {
      _strip.setPixelColor(i, _strip.Color(r, g, b));
    }

    r = _colors[1][0];
    g = _colors[1][1];
    b = _colors[1][2];

    for (int i = 10; i < 20; i++) {
      _strip.setPixelColor(i, _strip.Color(r, g, b));
    }
    
    r = _colors[2][0];
    g = _colors[2][1];
    b = _colors[2][2];

    for (int i = 20; i < 30; i++) {
      _strip.setPixelColor(i, _strip.Color(r, g, b));
    }

    _strip.show();
    delay(_delay);
  }
};
PatternFrench PatternFrench;
