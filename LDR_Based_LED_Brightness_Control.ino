int ldrPin=A0;
int led1=8;
int led2=9;
void setup(){
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
Serial.begin(9600);
}
void loop(){
int ldrValue=analogRead(ldrPin);
Serial.print("LDR Value:");
Serial.println(ldrValue);
if(ldrValue<500){
digitalWrite(led1,HIGH);
Serial.println("LED1 ON");
}
else{
digitalWrite(led1,LOW);
Serial.println("LED1 OFF");
}
int brightness=map(ldrValue,0,1023,255,0);
analogWrite(led2,brightness);
Serial.print("LED2 Brightness:");
Serial.println(brightness);
delay(1000);
}