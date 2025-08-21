#include <avr/io.h>
#include <util/delay.h>
#include "../../USART/USART.h"
#include <stdio.h>


int main(){
    initUSART();

    DDRB &= ~((1 << PB1) | (1 << PB0) | (1 << PB2) | (1 << PB3));
    PORTB |= (1 << PB1) | (1 << PB0) | (1 << PB2) | (1 << PB3);

    DDRC |= ((1 << PC1) | (1 << PC2));
    char buffer[5]; 
    while(1){
        uint8_t dip_value = (~PINB) & 0xF; //uint8_t first = (~PINB) & 0xF better use inverted logic
        snprintf(buffer, sizeof(buffer), "%d", dip_value);
        printString(buffer);
        if(dip_value>12){
            PORTC |= (1 << PC1);
            PORTC &= ~(1 << PC2);
        }
        else if (dip_value<4){           
            PORTC &= ~(1 << PC1);
            PORTC |= (1 << PC2);
        }else{
            PORTC &= ~(1 << PC1);
            PORTC &= ~(1 << PC2);
        }
         _delay_ms(1000);
    }

    return 0;
}