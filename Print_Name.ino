String name;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter name");
}

void loop(){
  if(Serial.available()){
    name=Serial.readString();
    Serial.print("hello ");
    Serial.println(name);
  }
}