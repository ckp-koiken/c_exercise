#include <stdio.h>

struct monster {
    char name[10];
    int hp, mp;
};

int main(void) {
    struct monster temp = {"", 7, 4};
    struct monster m1, m2;

    m1 = temp;
    printf("モンスター#1の名前？");
    scanf("%s", m1.name);
    
    m2 = temp;
    printf("モンスター#2の名前？");
    scanf("%s", m2.name);

    printf("モンスター名: %s HP=%d MP=%d \n", m1.name, m1.hp, m1.mp);

    printf("モンスター名: %s HP=%d MP=%d \n", m2.name, m2.hp, m2.mp);

    return 0;
}