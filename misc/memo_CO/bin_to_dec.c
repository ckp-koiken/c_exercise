#include <stdio.h>

int decToBin(int dec) {
    int bin = 0; // binary
    int cw = 1; // column weight

    while (dec > 0) {
        bin += dec % 2 * cw;
        dec /= 2; 
        cw *= 10;
    }
    return bin;
}

int binToDec(int bin) {
    int dec = 0; // decimal
    int cw = 1; // column weight

    while (bin > 0) {
        dec += bin % 10 * cw;
        bin /= 10; 
        cw *= 2;
    }
    return dec;
}

int main(void) {
    for (int i = 0; i < 16; i++) {
        printf("%04d %2d\n", decToBin(i), binToDec(decToBin(i)));
    }
    return 0;
}
