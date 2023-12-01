### CHIP CONFIGURATION ###
CHIP = atmega328p
CPU_FREQ = 16000000UL


### COMPILER CONFIGURATION ###
CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(CHIP) -Os -D F_CPU=$(CPU_FREQ)
CHFLAGS = -O ihex -j.text -j.data


### UPLOADER & FLASHER CONFIGURATIONS ###
BAUD = 115200
PROGRAMMER_TYPE = stk500v1
FLASHER = avrdude
DEVICE = /dev/ttyACM0
CONF = /etc/avrdude/avrdude.conf

FFLAGS = -p $(CHIP) -b $(BAUD) -C $(CONF) -c $(PROGRAMMER_TYPE) -P $(DEVICE) -V -F -v -v


### FILE CONFIGURATION ###
# every time a new project is created, copy this Makefile within project dir
# and change the file name variable below
FILE = pov_toy



all: flash clean

flash: hex
	$(FLASHER) $(FFLAGS) -U flash:w:$(FILE).hex:i

hex: $(FILE)
	$(OBJCOPY) $(FILE).out $(FILE).hex $(CHFLAGS)

$(FILE): $(FILE).c
	$(CC) $(CFLAGS) $(FILE).c  -o $(FILE).out

clean:
	rm -rf $(FILE).out $(FILE).hex
