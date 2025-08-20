#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <stdint.h>

/* --------------------------------------------------------------------------
   USART settings – tuned for F_CPU = 1 000 000 Hz
   -------------------------------------------------------------------------- */
#ifndef F_CPU
#  define F_CPU 1000000UL                /* make sure everyone sees the clock */
#endif

#define BAUD           9600UL            /* desired baud rate                */
#define UBRR_VALUE     12                /* see explanation below            */
#define USE_2X         1                 /* use double‑speed mode (U2X0)     */

/* --------------------------------------------------------------------------
   public API
   -------------------------------------------------------------------------- */
void  initUSART(void);
void  transmitByte(uint8_t data);
uint8_t receiveByte(void);               /* blocking read                    */
void  printString(const char *s);
void readString(char *buffer, uint8_t maxlen);
void printWord(uint16_t value);

#endif /* UART_H */
