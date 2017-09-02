#include <TimerOne.h>
#include "mcp32xx.h"

MCP32xx adc1(8);

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(100);
  Timer1.attachInterrupt( timerIsr );
  adc1.init(1,2,3,4);
}

void loop() {
  int test = adc1.sample(4);
  // put your main code here, to run repeatedly:

}

void timerIsr(){
  digitalWrite(13, digitalRead(13) ^ 1 );  
}
