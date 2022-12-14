/*
  Link product: 
  - https://hshop.vn/products/mach-chuyen-giao-tiep-uart-ttl-to-rs485-v3
  - https://hshop.vn/products/vietduino-uno

  Wiring:

        Uno/Mega2560                RS485-TTL V3  ---------------SHTC3_RS485
        Vcc-5V -------------------------Vcc--------------------------Vcc
        GND   --------------------------GND--------------------------GND
        11(RX) <--------------<-----RX_RS485_TTL_V3
        12(TX) --------------->-----TX_RS485_TTL_V3
                                    RS485_TTL_V3_A -------------------A
                                    RS485_TTL_V3_B -------------------B
        

*/

#include "SHTC3_RS485.h"

#define TX_RS485_TTL_V3     12
#define RX_RS485_TTL_V3     11

SHTC3_RS485 shtc3_rs485(RX_RS485_TTL_V3, TX_RS485_TTL_V3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start test SHTC3_RS485 ! ++++");

  // init module
  shtc3_rs485.begin(); // default SHTC3_RS485 Baudrate: 4800
  shtc3_rs485.setTimeout(100);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //Get data from your SHTC3_RS485, every 2s (See document)
  SHTC3_RS485_info SHTC3_RS485_Data = shtc3_rs485.getData(0x01);

  Serial.print(SHTC3_RS485_Data.temperature);
  Serial.print(F(" C\t\t"));

  Serial.print(SHTC3_RS485_Data.humidity);
  Serial.print(F(" %\t\t"));

  Serial.println();
  delay(2000);
  
}