#include <WS2812FX.h>

#define LED_COUNT 2
#define LED_PIN 12
 String val,varb;
 int i=0;

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
bool  cal=true;
void setup() {
   Serial.begin(9600); 
  ws2812fx.init();
  ws2812fx.setColor(0xff4587);
  ws2812fx.setBrightness(100);
  ws2812fx.setSpeed(700);
  ws2812fx.setMode(0);
  ws2812fx.start();
  Serial.println("-----begun----");
 
}

void loop() {
  ws2812fx.service();
  while (Serial.available()) {
//    val = Serial.readString();
       varb = Serial.readString();
// //   val=("0x"+val);
  // char* end;
  // unsigned long col = strtol(val.c_str(), &end, 0);
////  //  uint32_t colorr = strtoul(val,nullptr,HEX);
//  ws2812fx.setColor(col);
//  Serial.println("new mode "+val);
if(varb=="l"){i=i+1;}
 ws2812fx.setMode(i);
  Serial.println("new mode "+i);
//  if(cal){ws2812fx.setColor(0xff45ff);cal=false;}
    }  
  
}
