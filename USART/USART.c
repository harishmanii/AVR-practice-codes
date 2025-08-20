#include "USART.h"

/* --------------------------------------------------------------------------
   Initialise USART0: 9600 baud, 8 data, no parity, 1 stop (8 N 1)
   -------------------------------------------------------------------------- */
void initUSART(void)
{
#if USE_2X
    UCSR0A = (1 << U2X0);                /* double‑speed for better accuracy */
#else
    UCSR0A = 0;
#endif

    UBRR0H = (uint8_t)(UBRR_VALUE >> 8); /* baud divider                     */
    UBRR0L = (uint8_t) UBRR_VALUE;

    UCSR0B = (1 << TXEN0) | (1 << RXEN0); /* enable TX and RX               */
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); /* 8 data, 1 stop, no parity    */
}

/* -------------------------------------------------------------------------- */
void transmitByte(uint8_t data)
{
    while (!(UCSR0A & (1 << UDRE0)))     /* wait for TX buffer empty   */
        ;                                /* (UDRE0 = USART Data Reg. Empty) */

    UDR0 = data;                         /* start transmission               */
}

/* -------------------------------------------------------------------------- */
uint8_t receiveByte(void)                /* blocks until a byte arrives      */
{
    while (!(UCSR0A & (1 << RXC0))) ;    /* wait for data in RX buffer       */
    return UDR0;
}

/* -------------------------------------------------------------------------- */
void printString(const char *s)
{
    while (*s)
        transmitByte((uint8_t)*s++);
}
// Read a string from USART into buffer (ends with '\n' or max length)
void readString(char *buffer, uint8_t maxlen) {
    uint8_t i = 0;
    char c;
    while (i < (maxlen - 1)) {
        c = receiveByte();
        if (c == '\r' || c == '\n') break;
        buffer[i++] = c;
        transmitByte(c); // echo
    }
    buffer[i] = '\0';
    printString("\r\n");
}

// Print 16-bit word as decimal
void printWord(uint16_t value) {
    char buf[6];
    uint8_t i = 5;
    buf[i--] = '\0';
    if (value == 0) {
        buf[i] = '0';
        printString(&buf[i]);
        return;
    }
    while (value && i < 6) {
        buf[i--] = '0' + (value % 10);
        value /= 10;
    }
    printString(&buf[i + 1]);
}