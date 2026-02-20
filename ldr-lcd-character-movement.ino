#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ldrPin = A0;
const int leftBtn = 6;
const int rightBtn = 7;
const int pauseBtn = 8;

int position = 0;
int direction = 1;  
bool autoMode = false;
bool paused = false;

unsigned long previousMoveTime = 0;
unsigned long pauseStartTime = 0;
const unsigned long moveInterval = 300;
const unsigned long pauseDuration = 60000;

int threshold = 500;

unsigned long lastDebounceTime[3] = {0, 0, 0};
const unsigned long debounceDelay = 40;
int lastButtonState[3] = {HIGH, HIGH, HIGH};
int buttonState[3] = {HIGH, HIGH, HIGH};

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(leftBtn, INPUT_PULLUP);
  pinMode(rightBtn, INPUT_PULLUP);
  pinMode(pauseBtn, INPUT_PULLUP);

  createCharacter();
  lcd.clear();
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  if (ldrValue >= threshold) {
    autoMode = true;
  } else {
    autoMode = false;
  }

  handleButtons();

  lcd.setCursor(0, 1);
  lcd.print("LDR:");
  lcd.print(ldrValue);
  lcd.print("   ");

  lcd.setCursor(10, 1);
  if (autoMode && !paused) {
    lcd.print("AUTO");
    automaticMovement();
  } else {
    lcd.print("MAN ");
  }

  if (paused) {
    if (millis() - pauseStartTime >= pauseDuration) {
      paused = false;
    }
  }
}


void handleButtons() {

  int reading[3];
  reading[0] = digitalRead(leftBtn);
  reading[1] = digitalRead(rightBtn);
  reading[2] = digitalRead(pauseBtn);

  for (int i = 0; i < 3; i++) {

    if (reading[i] != lastButtonState[i]) {
      lastDebounceTime[i] = millis();
    }

    if ((millis() - lastDebounceTime[i]) > debounceDelay) {

      if (reading[i] != buttonState[i]) {
        buttonState[i] = reading[i];

        if (buttonState[i] == LOW) {

          if (!autoMode) {
            if (i == 0 && position > 0) position--;
            if (i == 1 && position < 15) position++;
          }

          if (i == 2 && autoMode) {
            paused = true;
            pauseStartTime = millis();
          }
        }
      }
    }

    lastButtonState[i] = reading[i];
  }

  displayCharacter();
}

void automaticMovement() {

  if (millis() - previousMoveTime >= moveInterval) {
    previousMoveTime = millis();

    position += direction;

    if (position >= 15) direction = -1;
    if (position <= 0) direction = 1;

    displayCharacter();
  }
}

void displayCharacter() {

  lcd.setCursor(0, 0);
  lcd.print("                ");   

  lcd.setCursor(position, 0);
  lcd.write(byte(0));
}

void createCharacter() {

  byte customChar[8] = {
    B00100,
    B01110,
    B10101,
    B00100,
    B01110,
    B01010,
    B10001,
    B00000
  };

  lcd.createChar(0, customChar);
}
