#include <avr/io.h>
#include <util/delay.h>

#define LED   PB0
#define BTN   PD2

int main(void) {
    // Configure LED pin as output
    DDRB |= (1 << LED);

    // Configure button pin as input with pull-up
    DDRD &= ~(1 << BTN);   // PD2 as input
    PORTD |= (1 << BTN);   // Enable internal pull-up

    while (1) {
        // Check button state (active LOW)
        if (PIND & (1 << BTN)) {
            // Button not pressed → 1 Hz blink
            PORTB ^= (1 << LED);   // toggle LED
            _delay_ms(500);
        } else {
            // Button pressed → 5 Hz blink
            PORTB ^= (1 << LED);   // toggle LED
            _delay_ms(100);
        }
    }

    return 0;
}
