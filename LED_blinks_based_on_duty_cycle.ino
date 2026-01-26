int t = 1000;
float dc = 0.0;
int ton = 0;
int toff = 0;

void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

bool valid = false;

void loop() {

  if (Serial.available()) {
    dc = Serial.parseFloat();
    valid = true;

    ton = dc * t;
    toff = t - ton;
    Serial.println(dc);
    Serial.println(ton);
    Serial.println(toff);
  }

  if (!valid) {
    digitalWrite(8, LOW);
    return;
  }

  digitalWrite(8, HIGH);
  delay(ton);
  digitalWrite(8, LOW);
  delay(toff);
}
