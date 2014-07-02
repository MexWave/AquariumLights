#include <Dhcp.h>
#include <Ethernet.h>

#include <config.h>
#include <ds3231.h>

byte ethernetMac[] {
  0xFE, 0xED, 0xDE, 0xAD, 0xBE, 0xEF
};

EthernetServer server(80);

void setup() {
  Ethernet.begin(mac);
  
  server.begin();
}

void loop() {
  EthernetClient client = server.available();
  
  if (client) {
    boolean EOR = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n' && EOR) {
          
        }
      }
    }
  }
}
