#include <stdio.h>
#include <math.h>

#define AREA (M_PI * r * r)

int main(void) {
    double r, wvol, depth;

    printf("プールの半径[m]？");
    scanf("%lf", &r);
    printf("水量[m^3]？");
    scanf("%lf", &wvol);

    depth = wvol / AREA;
    printf("水深は%.1f mです\n", depth);

    return 0;
}
