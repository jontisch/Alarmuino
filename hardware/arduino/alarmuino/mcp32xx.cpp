#include "mcp32xx.h"

MCP32xx::MCP32xx(uint8_t channels):_nchannels(channels){

}

void MCP32xx::init(uint8_t ePin, uint8_t dinPin, uint8_t doutPin, uint8_t clPin):	
	_ePin(ePin), _dinPin(dinPin), _doutPin(doutPin), _clPin(clPin){
	pinMode(_ePin, OUTPUT);
	pinMode(_dinPin, OUTPUT);
	pinMode(_doutPin, INPUT);
	pinMode(_clPin, OUTPUT);
	digitalWrite(_ePin, HIGH);
}

void MCP32xx::start(){

}

void MCP32xx::stop(){

}

void MCP32xx::sample(uint8_t channel){

}

MCP32xx::~MCP32xx(){

}
