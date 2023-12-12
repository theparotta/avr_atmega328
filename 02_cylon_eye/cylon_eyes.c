#include <avr/io.h>
#include <util/delay.h>

#define DELAY 30            /* 2 milliseconds */

int main() {
  /* setting all the pins in BANK-D as output */
  DDRD = 0xFF;
  
  uint8_t loop = 0;
  
  while (1) {
    
    /* moving forward */
    while (loop < 7) {
      PORTD = (1 << loop);     /* moving '1' bit based on loops value */
      _delay_ms(DELAY);
      loop++;
    }
    
    /* moving backward */
    while (loop > 0) {
      PORTD = (1 << loop);
      _delay_ms(DELAY);
      loop--;
    }
  }
  
  return(0);
}
