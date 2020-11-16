class PatternReset {

private:
  Adafruit_NeoPixel _strip;
  int _neopixel_count;
  const int _turn_off_colors[3] = { 0, 0, 0 };
  const int _turn_off_delay = 28;

public:
  void setup(Adafruit_NeoPixel strip, int neopixel_count) {
    _strip = strip;
    _neopixel_count = neopixel_count;
  }

  void show() {
    for (int i = 0; i < _neopixel_count; i++) {
      _strip.setPixelColor(i, _strip.Color(_turn_off_colors[0], _turn_off_colors[1], _turn_off_colors[2]));
      _strip.setBrightness(200);
      _strip.show();
    }

    delay(_turn_off_delay);
  }
};
PatternReset PatternReset;
