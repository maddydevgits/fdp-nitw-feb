int soil=A4;

void setup() {
  pinMode(soil,INPUT);
  Serial.begin(9600);
}

void loop() {
  int m=analogRead(soil);
  m=map(m,0,876,0,100);
  Serial.print(m);
  Serial.println("%");
}
