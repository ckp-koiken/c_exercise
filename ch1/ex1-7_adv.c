#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, n;
    unsigned int seed; 
    printf("疑似乱数の種? ");
    scanf("%d", &seed);
    srand(seed);

    for (i = 0; i < 5; i++) {
        n = rand();
        printf("%d\n", n);
    }
    printf("%d = RAND_MAX\n", RAND_MAX);
    return 0;
}
