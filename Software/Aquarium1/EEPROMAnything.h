#ifndef EEPROMAnything_h
#define EEPROMAnything_h

#include <EEPROM.h>
#include <Arduino.h>

unsigned int EEPROM_writeString(int ee, const char* value) {
  unsigned int i;
  char* p = (char*)value;
  
  for (i = 0; i < strlen(value); i++) {
    EEPROM.write(ee++, *p++);
  }
  
  return i;
}

unsigned int EEPROM_readString(int ee, char*& value) {
  unsigned int i, len;
  char c = 255;
  
  for (i = ee; c != 0; i++) {
    c = EEPROM.read(i);
  }
  
  len = i - ee;
  value = (char*)malloc(len);
  
  for (i = 0; i < len; i++) {
    *(value + i) = EEPROM.read(ee++);
  }
  
  return len;
}

template<class T> unsigned int EEPROM_writeAnything(int ee, const T& value) {
  const byte* p = (const byte*)(const void*)&value;
  unsigned int i;
  for (i = 0; i < sizeof(value); i++) {
    EEPROM.write(ee++, *p++);
  }
  return i;
}

template<class T> unsigned int EEPROM_readAnything(int ee, T& value) {
  byte* p = (byte*)(void*)&value;
  unsigned int i;
  for (i = 0; i < sizeof(value); i++) {
    *p++ = EEPROM.read(ee++);
  }
  
  return i;
}

#endif
