class PatternK2000 {

#define PATTERN_NEOPIXEL_SIZE 14

private:
  const int _colors[PATTERN_NEOPIXEL_SIZE][3] = {
    { 255, 0, 0 }, { 235, 0, 0 }, { 200, 0, 0 }, { 160, 0, 0 },
    { 95, 0, 0 }, { 50, 0, 0 }, { 25, 0, 0 }, { 15, 0, 0 },
    { 10, 0, 0 }, { 8, 0, 0 }, { 4, 0, 0 }, { 0, 0, 0 },
    { 0, 0, 0 }, { 0, 0, 0 }
  };
  const int _delay = 24;
  const int _distance_to_end = PATTERN_NEOPIXEL_SIZE - 1;
  Adafruit_NeoPixel _strip;
  int _neopixel_count;
  int _first_pixel_on;
  int _last_pixel_on;
  int _end_pixel;

  bool shouldStop() {
    return ChangePatternButton.isButtonPressed();
  }
  
  bool start() {
    for (int i = _distance_to_end; i < _end_pixel; i++) {
      if (shouldStop()) {
        return false;
      }
  
      for (int k = 0; k < _distance_to_end; k++) {
        int r = _colors[k][0];
        int g = _colors[k][1];
        int b = _colors[k][2];
        _strip.setPixelColor(i - k, _strip.Color(r, g, b));
      }
  
      _strip.show();
      delay(_delay);
    }
    return true;
  }
  
  bool flipStart() {
    int real_end = _end_pixel + _distance_to_end;
  
    for (int i = _end_pixel; i < real_end; i++) {
      if (shouldStop()) {
        return false;
      }
  
      for (int k = 0; k < _distance_to_end; k++) {
        int r_start = _colors[k][0];
        int g_start = _colors[k][1];
        int b_start = _colors[k][2];
        _strip.setPixelColor(i - k, _strip.Color(r_start, g_start, b_start));
      }
  
      int iter = i - _end_pixel;
      int position = _end_pixel;
  
      for (int l = iter; l > 0; l--) {
        int r_reverse = _colors[l][0];
        int g_reverse = _colors[l][1];
        int b_reverse = _colors[l][2];
  
        _strip.setPixelColor(position, _strip.Color(r_reverse, g_reverse, b_reverse));
        position--;
      }
  
      _strip.show();
      delay(_delay);
    }
    return true;
  }
  
  bool reverse() {
    for (int i = _neopixel_count - PATTERN_NEOPIXEL_SIZE; i > 0; i--) {
      if (shouldStop()) {
        return false;
      }
  
      for (int k = _distance_to_end; k > 0; k--) {
        int r = _colors[k][0];
        int g = _colors[k][1];
        int b = _colors[k][2];
        _strip.setPixelColor(i + k, _strip.Color(r, g, b));
      }
  
      _strip.show();
      delay(_delay);
    }
    return true;
  }
  
  void flipReverse() {
    int real_start_pixel = -PATTERN_NEOPIXEL_SIZE;
  
    for (int i = 0; i > real_start_pixel; i--) {
      if (shouldStop()) {
        return;
      }
  
      for (int k = _distance_to_end; k > 0; k--) {
        int r_start = _colors[k][0];
        int g_start = _colors[k][1];
        int b_start = _colors[k][2];
        _strip.setPixelColor(i + k, _strip.Color(r_start, g_start, b_start));
      }
  
      int position = 0;
      for (int l = -i; l > 0; l--) {
        int r_reverse = _colors[l][0];
        int g_reverse = _colors[l][1];
        int b_reverse = _colors[l][2];
  
        _strip.setPixelColor(position, _strip.Color(r_reverse, g_reverse, b_reverse));
        position++;
      }
  
      _strip.show();
      delay(_delay);
    }
  }
  
public:
  setup(Adafruit_NeoPixel strip, int neopixel_count) {
    _strip = strip;
    _neopixel_count = neopixel_count;
    _end_pixel = _neopixel_count - 1;
  }

  void show() {
    if (start()) {
      if (flipStart()) {
        if (reverse()) {
          flipReverse();
        }
      }
    }
  }
};
PatternK2000 PatternK2000;
