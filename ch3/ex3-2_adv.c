#include <stdio.h>

int main(void) {
    // TODO: 配列を使わない形式を模索
    int count, heavy, light;
    printf("りんごの個数？");
    scanf("%d", &count);
    int a[count];
    for (int i = 0; i < count; i++) {
        printf("重さ[g]？");
        scanf("%d", &a[i]);
    }

    heavy = a[0];
    light = a[0];

    for (int i = 0; i < count; i++) {
        if (a[i] > heavy) 
            heavy = a[i];
        else if (a[i] < light) 
            light = a[i];
    }

    printf("一番軽いもの %d g、一番重いもの %d g\n", light, heavy);

    return 0;
}
