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

int main(void) {
    for (int i = 0; i < 16; i++) {
        printf("%2d %04d\n", i, decToBin(i));
    }

    return 0;
}
