class PatternThunderbolt {
  
private:
  const int _colors[3] = { 0, 180, 0 };
  const int _brightness[6] = { 21, 52, 95, 170, 180, 190 };
  const int _delay[8] = { 30, 60, 75, 90, 110, 190, 230, 255 };
  Adafruit_NeoPixel _strip;
  int _neopixel_count;
  
  void setColors() {
    for (int i = 0; i < _neopixel_count; i++) {
      int r = _colors[0];
      int g = _colors[1];
      int b = _colors[2];
      _strip.setPixelColor(i, _strip.Color(r, g, b));
    }
  }
  
  void setBrightness() {
    int brightness = _brightness[ random(0, 5) ];
    _strip.setBrightness(brightness);
  }
  
public:
  void setup(Adafruit_NeoPixel strip, int neopixel_count) {
    _strip = strip;
    _neopixel_count = neopixel_count;
  }

  void show() {
    setColors();
    setBrightness();
    _strip.show();
  
    int d = _delay[ random(0, 7) ];
    delay(d);
  }
};
PatternThunderbolt PatternThunderbolt;
