void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(115200);
}

//Ava Tools - Serial Monitor, vaheta baud 115200 peale. 
//Serial Monitor on hea mõte debugimiseks. 
void loop() {

Serial.println("Alustan, Low");
Serial.println(LOW);
digitalWrite(LED_BUILTIN, LOW); 
delay(1000); 

Serial.println("lõpetan"); 
digitalWrite(LED_BUILTIN, HIGH);
delay(1000); 
}
