#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    MONSTERSIZE = 5,  // モンスターの数
    LINESIZE = 1024 // 一行読むバッファの大きさ
};

struct skillset {
    int poison, sleep, paralysis;
};

struct monster {
    char name[100];
    int hp, mp;
    struct skillset condition;
};

int read_monster(char *filename, struct monster *mon, int n) {
    FILE *fp;
    char buf[LINESIZE];

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return n;
}

int main(int arg, char *argv[]) {
    struct monster x[MONSTERSIZE];

    read_monster(argv[1], x, 5);
    return 0;
}