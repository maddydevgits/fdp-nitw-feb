// sensor is passing signal (data) to Arduino

int motion=8; // Digital
int buzzer=7;

void setup(){
  pinMode(motion,INPUT); 
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  
  for(int i=0;i<10;i++) {
  int m=digitalRead(motion);
  Serial.print("i: ");
  Serial.print(i);
  Serial.print(",m: ");
  Serial.println(m);
  if(m==1){
    digitalWrite(buzzer,1);
  } else {
    digitalWrite(buzzer,0);
  }
    delay(1000);
  }
}

void loop() {
  
}

