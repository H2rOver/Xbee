        /*
          Xbee1
          S. Timpe
         
          Makes Arduino send 1 character via XBee wireless to another XBee connected
          to a computer via a USB cable.

          The circuit:
          * RX is digital pin 2
          * TX is digital pin 3
         
          Based on a sketch created by D. Thiebaut
         
        */

        #include <SoftwareSerial.h>

        SoftwareSerial xbee(2, 3); // TX, RX
        char c = 'A';
        char char1, char2, char3;
        char jon;
        int  pingPong = 1;
        int tripleAflag = 0;

        void setup()  {
           Serial.begin(9600);
           Serial.println( "Arduino started sending bytes via XBee" );

           // set the data rate for the SoftwareSerial port
           xbee.begin( 9600);
           pinMode(13, OUTPUT);
        }

        void loop()  {

          xbee.write('A');
          xbee.write('A');
          xbee.write('A');

          xbee.write('Y');
          xbee.write('O');
          xbee.write('U');
          xbee.write('R');
          xbee.write('C');
          xbee.write('O');
          xbee.write('D');
          xbee.write('E');
          xbee.write('S');
          xbee.write('U');
          xbee.write('C');
          xbee.write('K');
          xbee.write('S');
          
          xbee.write('X');
          xbee.write('X');
          xbee.write('X');

          xbee.write('T');
          xbee.write('E');
          xbee.write('S');
          xbee.write('T');
          
          //xbee.write( c );
          //jon = xbee.read();
         
//          //--- display the character just sent on console ---
//          Serial.print( "  sending: ");
//          Serial.println( c );
//          Serial.print( "receiving: ");
//          Serial.println( jon );
//         
//          //--- get the next letter in the alphabet, and reset to ---
//          //--- 'A' once we have reached 'Z'.
//          c = c + 1;
//          if ( c>'Z' )
//               c = 'A';
//         
//          //--- switch LED on Arduino board every character sent---
//          if ( pingPong == 0 ) {
//            digitalWrite(13, LOW);}
//          else {
//            digitalWrite(13, HIGH);}
//          
//          pingPong = 1 - pingPong;
//          delay( 1000 );
          
        }
