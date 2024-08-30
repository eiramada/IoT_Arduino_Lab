const int ledOnePin = 12;  //D6
const int ledTwoPin = 13;  //D7

const int switchOnePin = 4;  //D2
const int switchTwoPin = 5;  //D1

boolean switch1_state = true;
boolean switch2_state = true;

void setup() {
  pinMode(ledOnePin, OUTPUT);
  pinMode(ledTwoPin, OUTPUT);
  pinMode(switchOnePin, INPUT_PULLUP);
  pinMode(switchTwoPin, INPUT_PULLUP);

  digitalWrite(ledOnePin, switch1_state);
  digitalWrite(ledTwoPin, switch2_state);

  Serial.begin(9600);
}

void loop() {
  SwitchPush(switchOnePin, ledOnePin, switch1_state);
  SwitchPush(switchTwoPin, ledTwoPin, switch2_state);
}

void SwitchPush(int switchPin, int ledPin, boolean &state) {
  if (digitalRead(switchPin) == LOW) {
    if (digitalRead(switchPin) == LOW) {  // Check if still LOW after debounce
      state = !state;                     // Toggle the state
      digitalWrite(ledPin, state);        // Update the LED
      while (digitalRead(switchPin) == LOW) {
      }
    }
  }
}
