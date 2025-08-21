#include <avr/io.h>
#include <util/delay.h>

/*
00
10 - true
01
11
*/

int main(){

    DDRB &= ~((1 << PB0) | (1<<PB1));
    PORTB |= ((1 << PB0) | (1 << PB1));
    DDRC |= (1 << PC1);

    while(1){
        uint8_t code = PINB & ((1 << PB1) | (1 << PB0)); //crucial point - This operation forces all bits except PB0 and PB1 to be 0

        if(code==(1<<PB1)){
            PORTC |= (1<<PC1);
        }else{
            PORTC &= ~(1<<PC1);
        }

        _delay_ms(1000);
    }

    return 0;
}