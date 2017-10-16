#include <Printers.h>
//#include <XBee.h>

        /*
          Xbee1
          S. Timpe
         
          Makes Arduino receive 1 character via XBee wireless to another XBee connected
          to a computer via a USB cable. Flashes pin 13 high when character received.

          The circuit:
          * RX is digital pin 0
          * TX is digital pin 1
         
          Based on a sketch created by D. Thiebaut
         
        */

        #include <SoftwareSerial.h>

        SoftwareSerial XBee(2,3); // TX, RX
        char c,test;
        int count = 0;
        
        void setup()  {
           Serial.begin(9600);
           Serial.println( "Arduino started receiving bytes via XBee" );

           // set the data rate for the SoftwareSerial port
           XBee.listen();
           XBee.begin( 9600 );
           pinMode(13,OUTPUT);
        }

        void loop()  {
          // recive character via XBee to other XBee
          // via USB cable

          c = XBee.read();
          if (c == 'A'){
            count++;
          } else {
            count = 0;
          }
          while(count > 2){
            c = XBee.read();
            Serial.print( c );
            if (c == 'X'){
              count = (count + 1)  % 6;
            } else {
              count = 3;
  
            }
          }
          Serial.println();
          //test = Serial.read();
          //XBee.write(test);

          
          
          //--- display the character just received on console ---
          //Serial.println( c );
          //Serial.println(XBee.available()); // to see queue
          
          
          //--- flash LED---
          if ( c >= char('A') && c <= char('Z') )
            digitalWrite(13, HIGH);
          else
            digitalWrite(13, LOW);
          delay( 1000 );
        }
