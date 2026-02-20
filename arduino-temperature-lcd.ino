#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {

  int sensorValue = analogRead(sensorPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperatureC = (voltage - 0.5) * 100.0;

  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Serial Output
  Serial.print("Temperature: ");
  Serial.print(temperatureF);
  Serial.println(" F");

  // LCD Output
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureF);
  lcd.print((char)223);
  lcd.print("F ");

  lcd.setCursor(0, 1);
  lcd.print("Volt: ");
  lcd.print(voltage);
  lcd.print("V ");

  delay(1000);
}
