#include <Arduino.h>
#include "LCD.h"

FILE _lcdout = {0};
LiquidCrystal _lcd(6,5,3,2,1,0);

int lcd_putchar(char ch, FILE* stream) {
  _lcd.write(ch);
  return 0;
}

void LCD::init() {
  _lcd.begin(16, 2);
  fdev_setup_stream(&_lcdout, lcd_putchar, NULL, _FDEV_SETUP_WRITE);
}

void LCD::printString(const char* message) {
  _lcd.setCursor(0, 0);
  _lcd.print("Init. ethernet");
}

void LCD::printfString(const char* message, ...) {
  va_list argp;
  vfprintf(&_lcdout, message, argp);
}
