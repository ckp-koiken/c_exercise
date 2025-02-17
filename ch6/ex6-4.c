#include <stdio.h>

int main(void) {
    float t[] = {-1, 28.89, 29.18, 29.22, 29.66, 30.77, 31.33, -1};
    int i;

    for (i = 1; i < sizeof(t)/sizeof(t[0]) - 1; i++) 
        printf("%d位 %.2f秒\n", i, t[i]);
    printf("何位の前後？");
    scanf("%d", &i);

    return 0;
}
