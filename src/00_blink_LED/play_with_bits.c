#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR  DDRD
#define LED_PORT PORTD

#define DELAY 85


void design1();
void design2();


int main() {
  // setting data-direction registor to high to denot as output
  LED_DDR = 0xFF;
  
  while (1) {
    design1();
    design2();
  }  
  
  return(0);
}


/* Design 01 - from forward */
void design1() {
  for (uint8_t i = 0; i < 8; i++) {
    LED_PORT |= (1 << i);
    _delay_ms(DELAY);
  }
  
  for (uint8_t i = 0; i < 8; i++) {
    LED_PORT &= ~(1 << i);
    _delay_ms(DELAY);
  }
  
  _delay_ms(DELAY * 5);  
}


/* Design 02 - from backward */
void design2() {
  for (uint8_t i = 7; i < 255; i--) {
    LED_PORT |= (1 << i);
    _delay_ms(DELAY);
  }
  
  for (uint8_t i = 7; i < 255; i--) {
    LED_PORT &= ~(1 << i);
    _delay_ms(DELAY);
  }
  
  _delay_ms(DELAY * 5);  
}
