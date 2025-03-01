#include <stdio.h>

int main(void) {
    char *month[13] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December", NULL};

    int m;

    printf("何月[1-12]？");
    scanf("%d", &m);

    printf("%d月は%sです\n", m, month[m-1]);

    return 0;
}