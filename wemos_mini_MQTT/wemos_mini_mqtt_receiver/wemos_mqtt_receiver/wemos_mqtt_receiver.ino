#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "arduino_secrets.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASS;

const char* mqtt_server = "192.168.8.175";
const int port = 1888;
const char* myTopic  = "test/releControlRA";
const char* myTopic2  = "test/releControlRA/temperature";

#define CLIENT_ID "Ada"

#define BUTTON1_PIN 4
#define BUTTON2_PIN 14
#define RELAY1_PIN 12
#define RELAY2_PIN 13

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;

  String tempValue = "0.00";
  String rel1Value = "off";
  String rel2Value = "off";

void setup_wifi() {
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";


  Serial.print("Message arrived: ");
  Serial.print(topic);
  Serial.print("/");


  for (int i = 0; i < length; i++) {
    message.concat((char)payload[i]);
  }

  Serial.print(message);
  Serial.println();

if (strcmp(topic,myTopic2)==0){
  tempValue=message;
}

  message=message.substring(0,2);
  
  //if ((char)payload[0] == '1') {
    if (message == "11") {
    digitalWrite(RELAY1_PIN, LOW);
    rel1Value="on";
 
  } else if (message == "10") {
    digitalWrite(RELAY1_PIN, HIGH);
    rel1Value="off";
   
  }
     else if (message == "21") {
    digitalWrite(RELAY2_PIN, LOW);
    rel2Value="on";
 
  } else if (message == "20") {
    digitalWrite(RELAY2_PIN, HIGH);
    rel2Value="off";
  
  }
updateScreen(tempValue, rel1Value, rel2Value);
}

void reconnect() {
  // Loop until we're reconnected
  digitalWrite(LED_BUILTIN, LOW);
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(CLIENT_ID, NULL, 0, true, "0")) {
      Serial.println("connected");
      //client.publish(willTopic, "1", true);
      client.subscribe(myTopic);
      client.subscribe(myTopic2);
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      Serial.print("failed");
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
 
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.display();

  
  Serial.begin(115200);
   delay(500);
  setup_wifi(); 
  client.setServer(mqtt_server, port);
  client.setCallback(callback);
  
  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(RELAY2_PIN, HIGH);

}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  
}

void updateScreen(String tempValue, String rel1Value, String rel2Value){
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,10);
  display.print("Temp ");
  display.print(tempValue);
  display.print(" C");
  
  display.setCursor(0,20);
  display.print("Relee1: ");
  display.print(rel1Value);

  display.setCursor(0,30);
  display.print("Relee2: ");
  display.print(rel2Value);
  display.display();

}