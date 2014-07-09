#include <Arduino.h>
#include "Lights.h"

LightArea::LightArea(char* areaName, int rPin, int gPin, int bPin) {
  // Store the light area name
  _areaName = (char*)malloc(strlen(areaName));
  strcpy(_areaName, areaName);
  
  // Setup the output pins
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  
  // And store them
  _r = rPin;
  _g = gPin;
  _b = bPin;
}

LightArea::~LightArea() {
  free(_areaName);
}

const char* LightArea::getName() const {
  return _areaName;
}

void LightArea::setR(unsigned int level) const {
  analogWrite(_r, level);
}

void LightArea::setG(unsigned int level) const {
  analogWrite(_g, level);
}

void LightArea::setB(unsigned int level) const {
  analogWrite(_b, level);
}

void LightArea::setRGB(unsigned int levelR, unsigned int levelG, unsigned int levelB) const {
  analogWrite(_r, levelR);
  analogWrite(_g, levelG);
  analogWrite(_b, levelB);
}

