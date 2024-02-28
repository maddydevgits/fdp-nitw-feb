int led=3;

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  analogWrite(led,1023); // digitalWrite(led,1);
  delay(100);
  analogWrite(led,0); // digitalWrite(led,0);
  delay(100);
}

// 10-bit is 2^10 - 1 = 1024-1 = 1023 (MAX) , 0 (MIN)

// digitalWrite(led,1) - 1 as 5V
// digitalWrite(led,0) - 0 as 0V

// analogWrite(led,255) -  (255/1023)*5V = 1.25V
