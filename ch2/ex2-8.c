#include <stdio.h>

int main(void) {
    int cards, draw, total;
    printf("カードは全部で何枚？");
    scanf("%d", &cards);
    printf("何枚並べる？");
    scanf("%d", &draw);
    
    total = 1;
    for (int i = 1; i <= draw; i++)
        total *= cards--;
        // total *= cards;  // こう書いても同じ
        // cards--;
    
    printf("並べ方は%d通りあります\n", total);

    return 0;
}
