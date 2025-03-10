#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MONSTER 5   // 出現するモンスターの数の上限値

struct skillset {
    int poison, sleep, paralysis;
};

struct monster {
    char name[100];
    int hp, mp;
    struct skillset condition;
};

void print_info(struct monster x);

void print_info(struct monster x) {
    printf("%sが あらわれた！", x.name);
    printf("（HP=%d MP=%d ", x.hp, x.mp);
    if (x.condition.poison == 1) {
        printf("どく ");
    }
    if (x.condition.sleep == 1) {
        printf("ねむり ");
    }
    if (x.condition.paralysis == 1) {
        printf("マヒ ");
    }
    printf("）\n");
}

int main(void) {
    struct monster template = {"", 7, 4, {0, 0, 0}};
    int num;

    srand(time(0));

    // モンスターの数を上限値の範囲でランダムに決める
    num = rand() % MONSTER + 1; 
    struct monster mon[num];

    // モンスターの名前
    char *mon_name[5] = {"nymph", "konaki jijii", "dragon", "floating eye", "dragon"};

    for (int i = 0; i < num; i++) {
        mon[i] = template;
        strcpy(mon[i].name, mon_name[rand() % 5]);
        mon[i].hp = rand() % 101 + 1;
        mon[i].mp = rand() % 21;
        mon[i].condition.poison = rand() % 2;
        mon[i].condition.sleep = rand() % 2;
        mon[i].condition.paralysis = rand() % 2;
        print_info(mon[i]);
    }

    return 0;
}