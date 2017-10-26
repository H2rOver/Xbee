#include <XBee.h> // import XBee library

XBee xbee = XBee(); // provides functions for sending and receiving packets
uint8_t payload[] = { '3', '4', '5', 'A' }; // array for transmit data ...research ROS X,Y,Z, thing...?

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xbee.setSerial(Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  XBeeAddress64 addr64 = XBeeAddress64(0x0013a2004154ec07);
  //XBeeAddress64 addr64 = XBeeAddress64(0x0003a200, 0x4154ec07); // note: 0010 works and 0003 works but 0013 doesnot work and changes to 00 7d 33 (fixed with API 2)!
  ZBTxRequest tx = ZBTxRequest(0x0013a2004154ec07, payload, sizeof(payload)); // 64-bit addressing, packet, and packet length
  xbee.send(tx); // send packet to remote radio
}
