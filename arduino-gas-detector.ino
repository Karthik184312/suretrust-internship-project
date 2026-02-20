#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int gasSensor = A0;
int greenLED = 8;
int redLED = 9;
int buzzer = 10;

int threshold = 650;   

void setup() {

  lcd.init();          
  lcd.backlight();     

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("Gas Detector");
  delay(2000);
  lcd.clear();
}

void loop() {

  int gasValue = analogRead(gasSensor);

  // Display gas value
  lcd.setCursor(0,0);
  lcd.print("Gas: ");
  lcd.print(gasValue);
  lcd.print("    ");   // Clear extra digits

  if (gasValue >= threshold) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0,1);
    lcd.print("Status: DANGER ");
  } 
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);

    lcd.setCursor(0,1);
    lcd.print("Status: SAFE   ");
  }

  delay(500);
}
