#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//https://randomnerdtutorials.com/esp8266-0-96-inch-oled-display-with-arduino-ide/
//GD - ground - miinus
//VCC - pluss - kasutame 3,3V

#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
display.clearDisplay(); //igaks juhuks tehakse puhtaks
display.setTextColor(WHITE); 
display.setTextSize(1);
display.setCursor(20, 20); //asukoht ekraanil, kus kursor alustab kirjutamist. 20x20 pixlit
// display.println("My display");
display.drawLine(0, 0, 127, 20, WHITE);
display.display();
}

void loop() {
display.startscrollright(0x00, 0x0F);
/* delay(2000);
display.stopscroll();
delay(1000);
display.startscrollleft(0x00, 0x0F);
delay(2000);
display.stopscroll();
delay(1000);
display.startscrolldiagright(0x00, 0x07);
delay(2000);
display.startscrolldiagleft(0x00, 0x07);
delay(2000);
display.stopscroll();
delay(1000); */
}




