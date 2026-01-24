// C++ code
#define r 8
#define g 9
#define b 10
void setup()
{
  Serial.begin(9600);
  pinMode(r,OUTPUT);  
  pinMode(g,OUTPUT);  
  pinMode(b,OUTPUT);   
}
void loop()
{
  if (Serial.available())
  {
    char val=Serial.read();
    switch (val)
    {
      case'r':  
        digitalWrite(r,HIGH);
        digitalWrite(g,LOW);
        digitalWrite(b,LOW);
        break;
      case'g':   
        digitalWrite(r,LOW);
        digitalWrite(g,HIGH);
        digitalWrite(b,LOW);
        break;
      case'b':  
        digitalWrite(r,LOW);
        digitalWrite(g,LOW);
        digitalWrite(b,HIGH);
        break;
      case'o':
        digitalWrite(r,HIGH);
        digitalWrite(g,HIGH);
        digitalWrite(b,HIGH);
        break;
      default:
        digitalWrite(8,LOW);
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        break;
    }
  }
}
