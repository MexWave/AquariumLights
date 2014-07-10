#ifndef RTC_h
#define RTC_h

#define CONFIG_UNIXTIME

#include <Arduino.h>
#include <Wire.h>
#include "ds3231.h"
#include <Time.h>

class RTC {
public:
  static void init();
  static time_t getTime();
  
};

#endif
