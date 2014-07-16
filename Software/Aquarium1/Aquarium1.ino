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
#include "LCD.h"

byte macAddr[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 };
EthernetClient client;

LCD lcd;

LightArea lights("Main", pinR, pinG, pinB);

void setup() {
  RTC::init();
  
  lcd.printString("Init. ethernet");
  
  if (Ethernet.begin(macAddr) == 0) {
    lcd.printString("ERR: No DHCP    ");
    while(1);
  } else {
    IPAddress ip = Ethernet.localIP();
    lcd.printfString("IP Address: %u.%u.%u.%u", ip[0], ip[1], ip[2], ip[3]);
  }
}

void loop() {
  lights.setRGB(96, 255, 255);
}
