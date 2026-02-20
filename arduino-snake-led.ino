int led[]={2,3,4,5,6};
int n=5;

void setup(){
  for(int i=0;i<n;i++){
    pinMode(led[i],OUTPUT);
  }
}
void loop(){
  for(int i=0;i<n;i++){
    digitalWrite(led[i],HIGH);
    delay(200);
    digitalWrite(led[i],LOW);
  }
  for(int i=n-2;i>0;i--){
    digitalWrite(led[i],HIGH);
    delay(200);
    digitalWrite(led[i],LOW);
  }
}
