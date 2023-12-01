// For compiling this: 
//   avr-gcc -mmcu=atmega328p -Os blink_LED_lib.c -D F_CPU=16000000UL


#include <avr/io.h>      // defines pins and ports      (/usr/avr/include/avr/io.h)
#include <util/delay.h>  // function to add delay/sleep 

int main() {
  // set Data Direction Register-B, to denote pin-14 (PB0) as output pin
  DDRB |= 0b00000001;
  
  while (1) {
    // set the pin14 (PB0) to high
    PORTB |= 0b0000001;
    _delay_ms(500);
    
    // set the pin14 (PB0) to low
    PORTB &= 0b11111110;
    _delay_ms(500);
  }  
  return(0);
}
