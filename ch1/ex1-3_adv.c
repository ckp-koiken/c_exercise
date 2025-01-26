#include <stdio.h>

int main(void) {
    int i, j;
    printf("16進数を1つ入力してください: ");
    scanf("%x", &i);

    printf("16進数をもう1つ入力してください: ");
    scanf("%x", &j);

    printf("16進で %x * %x = %x です\n", i ,j, i*j);
    return 0;
}
