#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int seed;
    int check;

    printf("種？");
    scanf("%u", &seed);
    srand(seed);
    
    while ((check = rand() % 10 + 1) != 1)
        printf("%d等です\n", check);

    printf("1等大当たり！\n");

    return 0;
}
