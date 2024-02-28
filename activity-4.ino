// arduino is passing data to buzzer to make it on

int buzzer=7;

void setup(){
  pinMode(buzzer,OUTPUT);
}

void loop(){
  digitalWrite(buzzer,1);
}
