#include <Arduino.h>
#include "RTC.h"


#define BUFF_MAX 128

// Globals (eurgh)
uint8_t time[8];
char recv[BUFF_MAX];
unsigned int recv_size = 0;
unsigned long prev, interval = 5000;

void RTC::init() {
  Wire.begin();
  DS3231_init(DS3231_INTCN);
  memset(recv, 0, BUFF_MAX);

  setSyncProvider(RTC::getTime);
}

time_t RTC::getTime() {
  ts t;
  DS3231_get(&t);
  return t.unixtime;
}
