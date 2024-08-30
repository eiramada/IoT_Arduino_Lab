// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "c4cc2959-2cab-401a-8845-39d4b94b3242";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onLight1Change();
void onLight2Change();

CloudSwitch light_1;
CloudSwitch light_2;
CloudTemperatureSensor wemos_hum;
CloudTemperatureSensor wemos_temp;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(light_1, READWRITE, ON_CHANGE, onLight1Change);
  ArduinoCloud.addProperty(light_2, READWRITE, ON_CHANGE, onLight2Change);
  ArduinoCloud.addProperty(wemos_hum, READ, 10 * SECONDS, NULL);
  ArduinoCloud.addProperty(wemos_temp, READ, 10 * SECONDS, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);