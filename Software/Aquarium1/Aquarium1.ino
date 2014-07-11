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
#include <SPI.h>
#include <Ethernet.h>
#include <LiquidCrystal.h>

byte macAddr[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };
EthernetClient client;

LiquidCrystal lcd(6, 5, 3, 2, 1, 0);

LightArea lights("Main", pinR, pinG, pinB);

void setup() {
  RTC::init();
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Init. ethernet");
  
  if (Ethernet.begin(macAddr) == 0) {
    lcd.setCursor(0, 0);
    lcd.print("ERR: No DHCP    ");
    while(1);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("IP Address:");
    
    for (byte n = 0; n < 4; n++) {
      if (n != 0) {
        lcd.setCursor((n * 4) - 1, 1);
        lcd.print(".");
      }
      lcd.setCursor(n * 4, 1);
      lcd.print(Ethernet.localIP()[n], 10);
    }
    
  }
}

void loop() {
  lights.setRGB(96, 255, 255);
}
