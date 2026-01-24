void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);   // Red LED
  pinMode(9, OUTPUT);   // Green LED
  pinMode(10, OUTPUT);   // Blue LED
}
void loop()
{
  if (Serial.available())
  {
    char val = Serial.read();
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);

    if (val == 'r')       
    {
      digitalWrite(8, HIGH);
    }
    else if (val == 'g')    
    {
      digitalWrite(9, HIGH);
    }
    else if (val == 'b')    
    {
      digitalWrite(10, HIGH);
    }
  }
}
