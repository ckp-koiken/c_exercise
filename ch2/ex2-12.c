#include <stdio.h>

int main(void) {
    int n;
    double m, o;
    printf("正の整数を1つ入れてください ");
    scanf("%d", &n);
    m = 1.0 / n;
    o = 0;
    for (int i = 0; i < n; i++) {
        o += m;
    }
    printf("%lfを%d回足すと%lf\n", m, n, o);
    if (o == 1)
        printf("戻りました\n");
    else 
        printf("戻りません\n");
    return 0;
}
