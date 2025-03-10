#include <stdio.h>

struct monster {
    char name[10];
    int hp, mp;
};

int hit(struct monster *p, int damage);

int hit(struct monster *p, int damage) {
    p->hp -= damage;
    if (p->hp <= 0) {
        printf("%sを たおした！\n", p->name);
        return 0;
    } else {
        printf("%sに%dのダメージ！\n", p->name, damage);
        return p->hp;
    }
}

int main(void) {
    struct monster mon = {"killer bee", 30, 4};
    int attack;

    for (;;) {
        printf("攻撃力？");
        scanf("%d", &attack);
        if (hit(&mon, attack) == 0)
            break;
    }

    return 0;
}