#define pinB 9
#define pinR 10
#define pinG 11

#include <Wire.h>
#include "ds3231.h"
#include "RTC.h"
#include "Lights.h"

LightArea lights("Main", pinR, pinG, pinB);

void setup() {
  RTC::init();
}

// the loop routine runs over and over again forever:
void loop() {
  lights.setRGB(96, 255, 255);
}
