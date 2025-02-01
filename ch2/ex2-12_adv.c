#include <stdio.h>

int main(void) {
    int n;
    double m, o, check;
    printf("正の整数を1つ入れてください ");
    scanf("%d", &n);
    m = 1.0 / n;
    o = 0;
    for (int i = 0; i < n; i++) {
        o += m;
    }
    check = 1.0 - o;
    printf("%lfを%d回足すと%lf、1との差は%e\n", m, n, o, check);
    if (o == 1)
        printf("戻りました\n");
    else 
        printf("戻りません\n");
    return 0;
}
