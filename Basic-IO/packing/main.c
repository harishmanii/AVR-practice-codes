#include <stdint.h>
#include <stdio.h>

/*
>>: only when you need higher bits → discard lower bits.

&: to extract exactly the bits you need.

<<: to shift the bits into their proper position for packing.
*/


//In the question we need to pack a(3 bits), b(2 bits), c(3 bits) into 1 byte as: aaa bb ccc
uint8_t pack_data(uint8_t a, uint8_t b, uint8_t c) {
    // Mask first to be safe (in case caller passes > 3 or > 7 etc.)
    a &= 0x07; // 3 bits (0-7) here we use mask operator to explictly tells we need 3 bits same as bove three
    b &= 0x03; // 2 bits (0-3)
    c &= 0x07; // 3 bits (0-7)

    //it look like this so thats why we shift to 5 and 3 10100000 | 00010000 | 00000111
    return (a << 5) | (b << 3) | c;
}


uint8_t unpack_a(uint8_t packed) {
    return (packed >> 5) & 0x07; // take bits 7..5
}

uint8_t unpack_b(uint8_t packed) {
    return (packed >> 3) & 0x03; // take bits 4..3
}

uint8_t unpack_c(uint8_t packed) {
    return packed & 0x07;        // take bits 2..0
}



int main(void) {
    uint8_t a = 5;  // 101 (3-bit)
    uint8_t b = 2;  // 10  (2-bit)
    uint8_t c = 7;  // 111 (3-bit)

    uint8_t packed = pack_data(a, b, c);

    uint8_t ua = unpack_a(packed);
    uint8_t ub = unpack_b(packed);
    uint8_t uc = unpack_c(packed);

    printf("Packed = 0x%02X\n", packed); 
    return 0;
}
