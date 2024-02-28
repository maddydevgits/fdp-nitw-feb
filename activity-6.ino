int sensor=A5;

void setup(){
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop(){
  float m=analogRead(sensor);
  float voltage=(m/1023)*5.0;
  Serial.print("V: ");
  Serial.print(voltage);
  Serial.print(",Analog: ");
  Serial.println(m);
  delay(400);
}
