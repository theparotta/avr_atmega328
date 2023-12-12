#include <avr/io.h> 
#include <util/delay.h>

#define DELAY 2

void blink_leds(uint8_t);

int main() {
  // setting all the pins in BANK-B as output
  DDRD = 0xFF;
  
  while (1) {
    // turning on/off LEDS in below pattern
    blink_leds(0b00001110);
    blink_leds(0b00011000);
    blink_leds(0b10111101);
    blink_leds(0b01110110);
    blink_leds(0b00111100);
    blink_leds(0b00111100);
    blink_leds(0b00111100);
    blink_leds(0b01110110);
    blink_leds(0b10111101);
    blink_leds(0b00011000);
    blink_leds(0b00001110);
    
    PORTB = 0;
    _delay_ms(10);
  }
  
  return(0);
}


void blink_leds(uint8_t portd) {
  PORTD = portd;
  _delay_ms(DELAY);  
}
