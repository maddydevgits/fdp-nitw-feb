#include <DHT.h>

DHT dht(D1,DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  // nan
  if(isnan(h) || isnan(t))
    return;

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(",Temperature: ");
  Serial.println(t);
  delay(4000);  
}
