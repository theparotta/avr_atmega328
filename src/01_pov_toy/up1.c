#include <avr/io.h> 
#include <util/delay.h>

#define DELAY 20

int main() {
  // setting all the pins in BANK-B as output
  DDRD = 0xFF;
  
  // setting LED display pattern
  uint8_t UP1_PATTERN[] = {
      0b10000100,
      0b01101100,
      0b01111110,
      0b00011111,
      0b01111110,
      0b01101100,
      0b10000100,
      0b00000000,
      0b00000000,
      0b00000000,
      0b10000010,
      0b11111111,
      0b11111111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b01111111,
      0b11111111,
      0b10000000,
      0b11111111,
      0b01111111,
      0b00000000,
      0b00000000,
      0b11111111,
      0b11111111,
      0b00110011,
      0b00110011,
      0b00011110,
      0b00011110
    };
  
  while (1) {
    for (uint8_t i = 0; i < sizeof(UP1_PATTERN); i++) {
      PORTD = UP1_PATTERN[i];
      _delay_ms(DELAY);
    }
    
    // every time the loop finishes, give it a break
    PORTD = 0;
    _delay_ms(DELAY * 2);
  }
  
  return(0);
}
