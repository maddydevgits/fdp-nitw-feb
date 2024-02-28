int button=4;
int led=3;

void setup() {
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  
  Serial.begin(9600); // 9600bps - Baud Rate
}

void loop() {
  int m=digitalRead(button);
  Serial.println(m); // printing m + new line on monitor
  if(m==0){
  	digitalWrite(led,1);
  } else {
    digitalWrite(led,0);
  }
  
  // m is 1 (Release), m is 0 (Touch)
}

// think you as arduino - LED 
// Arduino wants to make LED ON - LED (O/P)
// Arduino is reading data from Button - Button (I/P)

// Light (O/P), AC (O/P), Robot (O/P)
// Sensor gives data to Arduino (I/P)

// If a peripheral is providing data to arduino - I/P
// If a peripheral is taking data from arduino - O/P


