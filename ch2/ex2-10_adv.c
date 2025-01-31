#include <stdio.h>

int main(void) {
    int n, people;
    printf("お菓子の個数？");
    scanf("%d", &n);
    printf("人数？");
    scanf("%d", &people);
    if (people == 0 || n % people > 0) // もう書いてた
        printf("余ります\n");
    else
        printf("配り切れます\n");

    return 0;
}
