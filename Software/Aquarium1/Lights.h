#ifndef Lights_h
#define Lights_h

#include <Arduino.h>

class LightArea {
public:
  LightArea(char* areaName, int rPin, int gPin, int bPin);
  ~LightArea();
  
  const char* getName() const;
  
  void setR(unsigned int level) const;
  void setG(unsigned int level) const;
  void setB(unsigned int level) const;
  void setRGB(unsigned int levelR, unsigned int levelG, unsigned int levelB) const;

private:
  char* _areaName;
  
  int _r;
  int _g;
  int _b;
};

#endif
