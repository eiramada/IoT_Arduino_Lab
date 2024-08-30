//https://support.arduino.cc/hc/en-us/articles/4403050020114-Troubleshooting-PIR-Sensor-and-sensitivity-adjustment

const int ledPin = 12;        // D6 // choose the pin for the LED
const int pirSensorPin = 13;  // D7 // choose the input pin (for PIR sensor)

// Constants for states
const int PIR_SENSOR_DETECTED = HIGH;
const int PIR_SENSOR_NOT_DETECTED = LOW;

// State variables
int pirSensorState = PIR_SENSOR_NOT_DETECTED;  // we start, assuming no motion detected
int pirSensorReading = 0;                      // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);       // declare LED as output
  pinMode(pirSensorPin, INPUT);  // declare sensor as input
  Serial.begin(9600);            // initialize serial communication
}

void loop() {
  pirSensorReading = digitalRead(pirSensorPin);   // read input value
  if (pirSensorReading == PIR_SENSOR_DETECTED) {  // check if the input is HIGH
    digitalWrite(ledPin, HIGH);                   // turn LED ON
    if (pirSensorState == PIR_SENSOR_NOT_DETECTED) {
      // we have just turned on
      Serial.println("Motion detected!");    // print on state change
      pirSensorState = PIR_SENSOR_DETECTED;  // update state to motion detected
    }
  } else {
    digitalWrite(ledPin, LOW);  // turn LED OFF
    if (pirSensorState == PIR_SENSOR_DETECTED) {
      // we have just turned off
      Serial.println("Motion ended!");           // print on state change
      pirSensorState = PIR_SENSOR_NOT_DETECTED;  // update state to no motion detected
    }
  }
}
