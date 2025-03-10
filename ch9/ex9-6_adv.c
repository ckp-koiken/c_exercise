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
    printf("%s: ", x.name);
    printf("HP=%d MP=%d skills=%d, %d, %d \n", x.hp, x.mp, x.condition.poison, x.condition.sleep, x.condition.paralysis);
}

void create_monster(struct monster *p) {
    char *mon_name[5] = {"nymph", "konaki jijii", "dragon", "floating eye", "dragon"};
    char *q;

    strcpy(p->name, mon_name[rand() % 5]);
    p->hp = rand() % 101 + 1;
    p->mp = rand() % 21;
    p->condition.poison = rand() % 2;
    p->condition.sleep = rand() % 2;
    p->condition.paralysis = rand() % 2;
}


int main(void) {
    struct monster template = {"", 7, 4, {0, 0, 0}};
    struct monster m[MONSTER];
    int num;

    srand(time(0));

    // モンスターの数を上限値の範囲でランダムに決める
    num = rand() % MONSTER + 1; 
    struct monster mon[num];

    for (int i = 0; i < num; i++) {
        mon[i] = template;
        create_monster(&mon[i]);
        print_info(mon[i]);
    }

    return 0;
}