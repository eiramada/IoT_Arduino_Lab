// Define the pins for the RGB LED

const int redPin = 13;//D7, RED
const int greenPin = 14; //D5 //GREEN
const int bluePin = 12; //D6 //BLUE

void setup() {
  // Set the RGB pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Turn on red
  setColor(255, 0, 0);  // Red
  delay(1000);          // Wait for 1 second

  // Turn on green
  setColor(0, 255, 0);  // Green
  delay(1000);          // Wait for 1 second

  // Turn on blue
  setColor(0, 0, 255);  // Blue
  delay(1000);          // Wait for 1 second

  // Turn on yellow
  setColor(255, 255, 0);  // Yellow
  delay(1000);            // Wait for 1 second

  // Turn on cyan
  setColor(0, 255, 255);  // Cyan
  delay(1000);            // Wait for 1 second

  // Turn on magenta
  setColor(255, 0, 255);  // Magenta
  delay(1000);            // Wait for 1 second

  // Turn on white
  setColor(255, 255, 255);  // White
  delay(1000);              // Wait for 1 second

  // Turn off LED
  setColor(0, 0, 0);  // Off
  delay(1000);        // Wait for 1 second
}

// Function to set the color of the RGB LED
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
