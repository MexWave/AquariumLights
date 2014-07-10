#define pinB 9
#define pinR 10
#define pinG 11

#include <Wire.h>
#include <EEPROM.h>
#include "ds3231.h"
#include <Time.h>
#include "RTC.h"
#include "Lights.h"
#include "EEPROMAnything.h"

LightArea lights("Main", pinR, pinG, pinB);

void setup() {
  RTC::init();
}

void loop() {
  lights.setRGB(96, 255, 255);
}
