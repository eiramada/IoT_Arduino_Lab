#include "DHT.h"

#define DHTPIN 14 //ehk GPIO14 ehk D5
#define DHTTYPE DHT21
DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600); //9600 baud, turvaline valik. 
//baud number - kui kiiresti ta liigub, sagedus.
dht.begin();
}

void loop() {
delay(2000);

float h = dht.readHumidity();
float t = dht.readTemperature(); 
Serial.print("Current humidity = ");
Serial.print(h);
Serial.print("% ");
Serial.print("temperature = ");
Serial.print(t); 
Serial.println(); 
}
