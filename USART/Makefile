# Project name
TARGET = main

# Library files
LIB = USART.c

# Microcontroller and clock
MCU = atmega328p
F_CPU = 1000000UL
BAUD = 9600UL

# Programmer
PROGRAMMER = usbasp
BITCLOCK = -B 5
AVRSIZE = avr-size

# Tools and flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -std=gnu99
OBJCOPY = avr-objcopy
OBJCOPYFLAGS = -O ihex

# Source files
SRC = $(TARGET).c $(LIB)
OBJ = $(SRC:.c=.o)
ELF = $(TARGET).elf
HEX = $(TARGET).hex

all: $(HEX)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files
$(ELF): $(OBJ)
	$(CC) $(CFLAGS) -o $(ELF) $(OBJ)

# Create HEX file
$(HEX): $(ELF)
	$(OBJCOPY) $(OBJCOPYFLAGS) $(ELF) $(HEX)

# Flash to MCU
flash: $(HEX)
	avrdude -c $(PROGRAMMER) -p m328p $(BITCLOCK) -U flash:w:$(HEX)

# Optional: size of the compiled program
size: $(ELF)
	$(AVRSIZE) -C --mcu=$(MCU) $(ELF)

# Clean compiled files
clean:
	rm -f *.o *.elf *.hex

# Terminal mode for avrdude
avrdude_terminal:
	avrdude -c $(PROGRAMMER) -p $(MCU) $(BITCLOCK) -nt
