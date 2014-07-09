#ifndef RTC_h
#define RTC_h

#include <Arduino.h>
#include <Wire.h>
#include "ds3231.h"

class RTC {
public:
  static void init();
};

#endif
