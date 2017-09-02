#include "mcp32xx.h"

MCP32xx::MCP32xx(uint8_t channels):_nChannels(channels){

}

void MCP32xx::init(uint8_t ePin, uint8_t dinPin, uint8_t doutPin, uint8_t clPin){	
	_ePin = ePin;
        _dinPin = dinPin;
        _doutPin = doutPin; 
        _clPin = clPin;
	pinMode(_ePin, OUTPUT);
	pinMode(_dinPin, OUTPUT);
	pinMode(_doutPin, INPUT);
	pinMode(_clPin, OUTPUT);
	digitalWrite(_ePin, HIGH);
        digitalWrite(_clPin, LOW);
}

uint16_t MCP32xx::sample(uint8_t channel){
  uint8_t setupData = (0b11 << 4) | channel; //start bit set to 1 and config set to single-ended
  digitalWrite(_ePin, LOW);
  for(int i = 0; i < 5; i++){
    digitalWrite(_dinPin, setupData >> 4-i  & 1);
    digitalWrite(_clPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(_clPin, LOW);
    delayMicroseconds(1);
  }
  
  uint16_t returnData = 0;
  for(int i = 0; i < 12; i++){
    digitalWrite(_clPin, HIGH);
    delayMicroseconds(1);
    returnData = returnData << 1 | digitalRead(_doutPin);
    digitalWrite(_clPin, LOW);
    delayMicroseconds(1);
  }
  digitalWrite(_ePin, HIGH);
  delayMicroseconds(1);
  return returnData;
}

MCP32xx::~MCP32xx(){

}

