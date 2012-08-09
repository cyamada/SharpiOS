#include <SoftModem.h>
#include <ctype.h>

SoftModem modem;

int sharpPin = 0; // Sharp sensor is attached to analog pin 1
int triggerVal = 300; // Values above this will send a trigger to the phone
int sharpVal;
int sensorDelay = 10000; // 10 second delay

void setup() {
  Serial.begin(9600); 
}

void loop() {
   sharpVal = analogRead(sharpPin);
   
   if (sharpVal < triggerVal) { // Sharp remains untriggered  
     // Do nothing
   } else { // Sensor is triggered
     char h = '1';
     modem.write(h); //Send an ASCII 1 to the iOS device
     //delay(sensorDelay); //optional read delay
   }
}
