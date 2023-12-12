#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR   DDRD
#define LED_PORT  PORTD

#define DELAY 20

void blink_leds(uint8_t[], uint8_t size);

int main() {
  uint8_t invaders1[] = {
    0b01110000,
    0b00011000,
    0b11111101,
    0b10110110,
    0b00111100,
    0b00111100,
    0b00111100,
    0b10110110,
    0b11111101,
    0b00011000,
    0b01110000
  };
  
  uint8_t invaders2[] = {
    0b00001110,
    0b00011000,
    0b10111101,
    0b01110110,
    0b00111100,
    0b00111100,
    0b00111100,
    0b01110110,
    0b10111101,
    0b00011000,
    0b00001110
  };
  
  // setting data registor to output mode
  LED_DDR = 0xFF;
  
  while (1) {
    blink_leds(invaders1, sizeof(invaders1));
    blink_leds(invaders2, sizeof(invaders2));
  }
  
  return(0);
}


void blink_leds(uint8_t symbol[], uint8_t size) {
  for (uint8_t i = 0; i < size; i++) {
    LED_PORT = symbol[i];
    _delay_ms(DELAY);
  }
  
  // every time after the loop, pause for a while
  _delay_ms(DELAY * 2);
}
