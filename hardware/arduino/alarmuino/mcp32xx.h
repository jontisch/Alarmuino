#ifndef MCP32XX_cpp
#define MCP32XX_cpp

#include <stdint.h>
#include <Arduino.h>

class MCP32xx{
public:
  
  MCP32xx(uint8_t channels);
  void init(uint8_t ePin, uint8_t dinPin, uint8_t doutPin, uint8_t clPin);
  uint16_t sample(uint8_t channel);
  ~MCP32xx();

private:
  uint8_t _nChannels;
  uint8_t _ePin;
  uint8_t _dinPin;
  uint8_t _doutPin;
  uint8_t _clPin;
  uint8_t _nextBit;
};

#endif
