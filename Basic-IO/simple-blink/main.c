#include <avr/io.h>
#include <util/delay.h>

#define PORT PORTB
#define DDR DDRB
#define LED PB1 

int main(){

    DDR |= (1 << LED);
    PORT &= ~(1 << LED);
    while(1){

        PORTB ^= (1 << LED); 
         _delay_ms(1000);
    }

    return 0;
}