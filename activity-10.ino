#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h> // IoT Cloud Server

WiFiClient client; // client object to connect with server

int channelid=2451792; // thingspeak creds
char* apikey="M9D6RUBXIG4BQBYJ";

const char* ssid="The WIFI"; // wifi creds
const char* password="123madhu";

DHT dht(D1,DHT11);

// IEEE 802.15.4 - WiFi Transceiver

void setup() {
  Serial.begin(9600);
  dht.begin();
  WiFi.mode(WIFI_STA); // STA (Station - Receiving), AP (Access Point - Transmit)
  delay(1000);
  WiFi.begin(ssid,password); // send a request to the wifi network
  while(WiFi.status()!=WL_CONNECTED) {
    Serial.print(".");
    delay(500); // 500ms we have to check the status
  }
  Serial.println("WiFi Connected");
  ThingSpeak.begin(client); // wifi chip is connected to thingspeak
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

  ThingSpeak.setField(1,h); // 1 - Field Number
  ThingSpeak.setField(2,t); // 2 - Field Number

  int statuscode=ThingSpeak.writeFields(channelid,apikey);
  if(statuscode==200){
    Serial.println("Data Uploaded to IoT Cloud");
  } else {
    Serial.println(statuscode);
  }
  
  delay(15000);  
}
