// arduino is passing data to motor to move
// motor - o/p

int motor=5;

void setup() {
  pinMode(motor,OUTPUT);
}

void loop(){
  digitalWrite(motor,1);
}
