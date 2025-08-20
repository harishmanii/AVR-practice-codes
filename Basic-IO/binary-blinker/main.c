#include <avr/io.h>
#include <util/delay.h>

#define DDR DDRB
#define PORT PORTB

int main(){
    DDR |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3);
    while(1){
        for(uint8_t i=0;i<16;i++){
            PORT = (PORTB & 0xF0) | (i & 0x0F);
            _delay_ms(500);
        }
    }

    return 0;
}