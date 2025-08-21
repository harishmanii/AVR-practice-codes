#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Configure all Port B pins as outputs
    DDRB = 0xFF;        // 0b11111111 - all pins output
    PORTB = 0x00;       // Start with all LEDs off
    
    uint8_t pattern = 0x01;  // Start with PB0 lit (0b00000001)
    int8_t direction = 1;    // 1 = right, -1 = left

    while (1) {
        // Output the current pattern to Port B
        PORTB = pattern;
        
        // Delay for visibility
        _delay_ms(100);
        
        // Move the pattern based on direction
        if (direction == 1) {
            pattern <<= 1;  // Shift left (move light right)
        } else {
            pattern >>= 1;  // Shift right (move light left)
        }
        
        // Change direction when reaching the ends
        if (pattern == 0x80) {  // Reached PB7 (0b10000000)
            direction = -1;
        } else if (pattern == 0x01) {  // Reached PB0 (0b00000001)
            direction = 1;
        }
    }
    
    return 0;
}

/*
This is metod looks diff so thats why paste it from deepseek
*/