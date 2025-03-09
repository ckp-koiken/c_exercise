#include <stdio.h>
#include <string.h>

struct skillset {
    int poison, sleep, paralysis;
};

struct monster {
    char name[100];
    int hp, mp;
    struct skillset condition;
};

void print_skill(struct monster x);

void print_skill(struct monster x) {
    printf("スキル: ");
    if (x.condition.poison == 1) {
        printf("どく ");
    }
    if (x.condition.sleep == 1) {
        printf("ねむり ");
    }
    if (x.condition.paralysis == 1) {
        printf("マヒ ");
    }
    printf("\n");
}

int main(void) {
    struct monster temp = {"", 7, 4, {0, 0, 0}};
    struct monster m1, m2, m3;

    m1 = temp;
    strcpy(m1.name, "giant ant");
    printf("%s: HP = %d MP = %d ", m1.name, m1.hp, m1.mp);
    print_skill(m1);

    m2 = temp;
    strcpy(m2.name, "floating eye");
    m2.condition.paralysis = 1;
    printf("%s: HP = %d MP = %d ", m2.name, m2.hp, m2.mp);
    print_skill(m2);

    m3 = temp;
    strcpy(m3.name, "homunculus");
    m3.condition.poison = 1;
    m3.condition.sleep = 1;
    printf("%s: HP = %d MP = %d ", m3.name, m3.hp, m3.mp);
    print_skill(m3);
    return 0;
}