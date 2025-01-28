#include <stdio.h>

int main(void) {
    double dia, volume;
    printf("球の半径[cm]？ ");
    scanf("%lf", &dia);
    volume = 4 * 3.14 * dia * dia * dia / 3;
    printf("半径%.1lfcmの球の体積は約%.2lfccです\n", dia, volume);

    return 0;
}
