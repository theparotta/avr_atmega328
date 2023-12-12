/* DDRB *((volatile unsigned char*) 0x24)    - what this means
 * 
 * 0x24 is memory's address represented in hexadecimal
 * 
 * (unsigned char *) 0x24
 *     - we are creating a pointer to point to an address 0x24
 *     - and the data in that address will be of type unsigned char
 * 
 * *((unsigned char *) 0x24)
 *     - '*' will get the value pointed by the address
 *     - means it gets the value at the address 0x24
 * 
 * volatile
 *     - forces the compiler to issue LOAD or STORE anytime DDRB is accessed as
 *       the value may change without the compiler knowing it
 */

// DDRB represents Data-Direction Register for PortB (14 to 19 pins)
// It is a 1-byte register defined by ATmega328p at the address 0x24
// setting a bit to 0 means the pin is set to input mode, setting to 1 means it's output
#define DDRB *((volatile unsigned char *) 0x24)

// PORTB represents all the pins value at bankB (pin14 to pin19)
// It is a 1-byte register defined by ATmega328p at the address 0x25
// setting a bit to 0 means it's set to low, setting a bit to 1 means it's high
#define PORTB *((volatile unsigned char*) 0x25)


/* EVERYTHING STARTS HERE */
int main() {
  // setting pin-14 (PB0) as output pin
  DDRB |= 0b00000001;
  
  while (1) {
    // setting a pin-14 (PB0) to high
    // using BITWISE-OR to turn on the 1st pin without affecting other bits in PORTB
    PORTB |= 0b0000001;
    
    // LED ON time for arbitary amount of time
    for (long i = 0; i < 1000; i++) {
      
      // to make sure the compiler doesn't optimize this out, continue setting
      // the 1st pin of PORTB to high
      PORTB |= 0b00000001;
    }


    // setting a pin-14 (PB0) to low
    // using BITWISE-AND to turn off the 1st pin without affecting other bits in PORTB
    PORTB &= 0b11111110;
    
    // LED OFF time for arbitary amount of time
    for (long i = 0; i < 100000; i++) {
      
      // to make sure the compiler doesn't optimize this out, continue setting
      // the 1st pin of PORTB to low
      PORTB &= 0b11111110;
    }
    
  }  
}
