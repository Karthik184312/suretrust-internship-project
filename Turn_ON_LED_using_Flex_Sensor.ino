int  led = 7;
int  flex = A0;
void setup (){
pinMode(led,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  
  int sensorValue=analogRead(flex);
  int v=map(sensorValue,2,11,0,255);//v=brightness
  Serial.println(v);
  if (v>30){
    digitalWrite(7,LOW);
  }
  else{
  digitalWrite(7,HIGH);
  }
  delay(500);
}