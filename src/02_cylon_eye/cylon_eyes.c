#include <avr/io.h>
#include <util/delay.h>

#define DELAY 50            /* 2 milliseconds */

/*
BIT SHIFTING
============ 
1        = 0b00000001
(1 << 0) = 0b00000001
(1 << 1) = 0b00000010
(1 << 3) = 0b00001000
(1 << 7) = 0b10000000

*/



int main() {
  /* setting all the pins in BANK-D as output */
  DDRD = 0xFF;
  
  uint8_t loop = 0;
  
  while (1) {
    
    /* moving forward */
    while (loop < 7) {
      PORTD = ~(1 << loop);     /* moving '1' bit based on loops value */
      _delay_ms(DELAY);
      loop++;
    }
    
    /* moving backward */
    while (loop > 0) {
      PORTD = ~(1 << loop);
      _delay_ms(DELAY);
      loop--;
    }
  }
  
  return(0);
}
