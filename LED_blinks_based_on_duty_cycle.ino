
int t = 1000;
float dc = 0.0;
int ton = 0;
int toff = 0;
void setup() {
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available()) {
    dc = Serial.parseFloat();
    ton = dc * t;
    toff = t - ton;
    Serial.println(ton); 
    Serial.println(toff);
  }
  digitalWrite(6, HIGH);
  delay(ton);
  digitalWrite(6, LOW);
  delay(toff);
}