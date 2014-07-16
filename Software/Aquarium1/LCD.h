#ifndef LCD_h
#define LCD_h

#include <Arduino.h>
#include <LiquidCrystal.h>

class LCD {
public:
  static void init();
  static void printString(const char* string);
  static void printfString(const char* message, ...);
};

#endif
