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

int main(void) {
    struct monster temp = {"", 7, 4, {0, 0, 0}};
    struct monster m1, m2, m3;

    m1 = temp;
    strcpy(m1.name, "giant ant");
    printf("%s: HP = %d MP = %d ", m1.name, m1.hp, m1.mp);
    printf("スキル: %s %s %s\n", m1.condition.poison == 1 ? "どく" : "", m1.condition.sleep == 1 ? "ねむり" : "", m1.condition.paralysis == 1 ? "マヒ" : "");
    // TODO: スキルの表示を改善

    m2 = temp;
    strcpy(m2.name, "floating eye");
    m2.condition.paralysis = 1;
    printf("%s: HP = %d MP = %d ", m2.name, m2.hp, m2.mp);
    printf("スキル: %s %s %s\n", m2.condition.poison == 1 ? "どく" : "", m2.condition.sleep == 1 ? "ねむり" : "", m2.condition.paralysis == 1 ? "マヒ" : "");

    m3 = temp;
    strcpy(m3.name, "homunculus");
    m3.condition.poison = 1;
    m3.condition.sleep = 1;
    printf("%s: HP = %d MP = %d ", m3.name, m3.hp, m3.mp);
    printf("スキル: %s %s %s\n", m3.condition.poison == 1 ? "どく" : "", m3.condition.sleep == 1 ? "ねむり" : "", m3.condition.paralysis == 1 ? "マヒ" : "");

    return 0;
}