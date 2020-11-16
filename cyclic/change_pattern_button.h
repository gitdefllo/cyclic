class ChangePatternButton {

private:
  int _button_pin;
  bool _old_button_state = HIGH;
  
public:
  void setup(int button_pin) {
    _button_pin = button_pin;
    
    pinMode(_button_pin, INPUT_PULLUP);
  }
  
  bool isButtonPressed() {
    bool new_button_state = digitalRead(_button_pin);
    
    if (new_button_state == LOW && _old_button_state == HIGH) {
      delay(80);
      
      new_button_state = digitalRead(_button_pin);
      if (new_button_state == LOW) {
        return true;
      }
    }
    
    _old_button_state = new_button_state;
    
    return false;
  }
  
};
ChangePatternButton ChangePatternButton;
