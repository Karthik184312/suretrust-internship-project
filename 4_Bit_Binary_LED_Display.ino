int leds[4] = {2, 3, 4, 5};
void setup() {
  for (int i = 0; i < 4; i++){
    pinMode(leds[i], OUTPUT);
  }
}
void loop() {
  for (int num = 0; num < 16; num++) {
    for (int bit = 0; bit < 4; bit++) {
      digitalWrite(leds[bit], (num >> bit) & 1);
    }
    delay(1000);
  }
}