#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "arduino_secrets.h"

#include <DHT.h>
#include <DHT_U.h>

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASS;

const char* mqtt_server = "192.168.8.175";
const int port = 1888;
const char* myTopic = "test/releControlRA";
#define CLIENT_ID "Raivo_t"

#define BUTTON1_PIN 4
#define BUTTON2_PIN 14
#define RELAY1_PIN 12
#define RELAY2_PIN 13

#define DHTPIN 5
#define DHTTYPE DHT21
DHT dht(DHTPIN, DHTTYPE);

boolean switch1_state = false;
boolean switch2_state = false;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;

void setup_wifi() {
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
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
  message = message.substring(0, 2);

  //if ((char)payload[0] == '1') {
  if (message == "11") {
    digitalWrite(RELAY1_PIN, LOW);

  } else if (message == "10") {
    digitalWrite(RELAY1_PIN, HIGH);


 } else if (message == "21") {
    digitalWrite(RELAY2_PIN, LOW);

  } else if (message == "20") {
    digitalWrite(RELAY2_PIN, HIGH);
  }
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
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      Serial.print("failed");
      //Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  dht.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  Serial.begin(115200);
  delay(1000);
  setup_wifi();
  client.setServer(mqtt_server, port);
  client.setCallback(callback);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);

  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(RELAY2_PIN, HIGH);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (digitalRead(BUTTON1_PIN) == LOW) {
    switch1_state = !switch1_state;

    onLight1Change();
    while (digitalRead(BUTTON1_PIN) == LOW) {}
  }

  if (digitalRead(BUTTON2_PIN) == LOW) {

    switch2_state = !switch2_state;
    onLight2Change();
    while (digitalRead(BUTTON2_PIN) == LOW) {}
  }

  long now = millis();
  if (now - lastMsg > 6000) {
    lastMsg = now;

    float t = dht.readTemperature();
    String stringTemp = String(t, 2);
    Serial.print("Sending temperature: ");
    Serial.print(stringTemp);
    Serial.println();
    client.publish("test/releControlRA/temperature", stringTemp.c_str(), true);
  }
}

void onLight1Change() {
  //digitalWrite(RELAY1_PIN, !switch1_state);
  if (switch1_state) {
    client.publish(myTopic, "11", true);
    Serial.println("Sending: test/11");
  } else {
    client.publish(myTopic, "10", true);
    Serial.println("Sending: test/10");
  }
}

void onLight2Change() {
  //digitalWrite(RELAY2_PIN, !switch2_state);

  if (switch2_state) {
    client.publish(myTopic, "21", true);
    Serial.println("Sending: test/21");
  } else {
    client.publish(myTopic, "20", true);
    Serial.println("Sending: test/20");
  }
}