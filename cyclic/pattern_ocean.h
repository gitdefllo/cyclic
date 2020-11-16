class PatternOcean {

private:
  const int _colors[3] = { 0, 0, 255 };
  const int _delay[3] = { 2, 10, 25 };
  Adafruit_NeoPixel _strip;
  int _neopixel_count;

  bool shouldStop() {
    return ChangePatternButton.isButtonPressed();
  }
  
  void setColors() {
    for (int i = 0; i < _neopixel_count; i++) {
      int r = _colors[0];
      int g = _colors[1];
      int b = _colors[2];
      _strip.setPixelColor(i, _strip.Color(r, g, b));
    }
    _strip.show();
  }
  
  void setAnimation() {
    int brightness = 255;
    int anim_delay = _delay[0];
    int anim_down = true;
    
    while (!shouldStop()) {
      if (brightness > 100 && anim_down) {
        brightness--;
        anim_delay = _delay[2];
        
      } else if (brightness > 10 && anim_down) {
        brightness--;
        anim_delay = _delay[1];
  
      } else if (brightness >= 254 && !anim_down) {
        anim_down = true;
        
      } else {
        anim_down = false;
        brightness++;
        anim_delay = _delay[0];
      }
      
      _strip.setBrightness(brightness);
      _strip.show();
  
      delay(anim_delay);
    }
  }

public:
  void setup(Adafruit_NeoPixel strip, int neopixel_count) {
    _strip = strip;
    _neopixel_count = neopixel_count;
  }

  void show() {
    setColors();
    setAnimation();
  }
};
PatternOcean PatternOcean;
