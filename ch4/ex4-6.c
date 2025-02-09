#include <stdio.h>

#define MIperKM 1.609344
#define FMT "%.3f"

int main(void) {
    int dir;
    double km, mi;

    printf("変換（1: km->mi, 2: mi->km）？");
    scanf("%d", &dir);

    if (dir == 1) {
        printf("何km？");
        scanf("%lf", &km);
        mi = km / MIperKM;
        printf(FMT, km); printf(" kmは"); printf(FMT, mi); printf(" miです\n");
    } else {
        printf("何mi？");
        scanf("%lf", &mi);
        km = mi * MIperKM;
        printf(FMT, mi); printf(" miは"); printf(FMT, km); printf(" kmです\n");
    }
    return 0;
}
