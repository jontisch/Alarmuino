#include <stdint.h>


class MCP32xx{
public:
  MCP32xx(uint8_t channels);
  void init(uint8_t ePin, uint8_t dinPin, uint8_t doutPin, uint8_t clPin);
  void start();
  void stop();
  void sample(uint8_t channel);
  uint16_t getValue();
  ~MCP32xx();
private:
  uint8_t _nChannels;
  uint8_t _enablePin;
  uint8_t _dinPin;
  uint8_t _doutPin;
  uint8_t _clockPin;
};
