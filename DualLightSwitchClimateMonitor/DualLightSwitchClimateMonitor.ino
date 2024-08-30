/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled 2"
  https://create.arduino.cc/cloud/things/520fa65e-2a6c-4026-b367-bb39fc84651f 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  CloudSwitch light_1;
  CloudSwitch light_2;
  CloudTemperatureSensor wemos_hum;
  CloudTemperatureSensor wemos_temp;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include <DHT.h>
#include <DHT_U.h>

#include "thingProperties.h"

#define DHTPIN 5     
#define DHTTYPE DHT21
DHT dht(DHTPIN, DHTTYPE);

const int reley1_pin = 12;   
const int reley2_pin = 13; 
const int switch1_pin = 4;
const int switch2_pin = 14; 

boolean switch1_state=false;
boolean switch2_state=false;

void setup() {
  dht.begin();
  
  pinMode(switch1_pin, INPUT_PULLUP);
  pinMode(switch2_pin, INPUT_PULLUP);
  
  pinMode(reley1_pin, OUTPUT);
  pinMode(reley2_pin, OUTPUT);

  digitalWrite(reley1_pin,switch1_state);
  digitalWrite(reley2_pin,switch2_state);
 
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  

  
setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  float h= dht.readHumidity();
  float t= dht.readTemperature(); 
  wemos_hum=h;
  wemos_temp=t;

if(digitalRead(switch1_pin)==LOW)
  {
    Serial.println("Switch 1 Pressed");
    light_1 =!light_1;
    onLight1Change();
    while(digitalRead(switch1_pin)==LOW){}
  }

  if(digitalRead(switch2_pin)==LOW)
  {
    Serial.println("Switch 2 Pressed");
    light_2 =!light_2;
    onLight2Change();
    while(digitalRead(switch2_pin)==LOW){}
  }
}

void onLight1Change()  {
 digitalWrite(reley1_pin,switch1_state);
 switch1_state= !switch1_state;
}

void onLight2Change()  {
  digitalWrite(reley2_pin,switch2_state);
 switch2_state= !switch2_state;
}


