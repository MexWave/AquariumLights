#include <DS3231.h>

int pinB = 9;
int pinR = 10;
int pinG = 11;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(pinB, OUTPUT);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  analogWrite(pinB, 255);
  analogWrite(pinR, 96);
  analogWrite(pinG, 255);
}
