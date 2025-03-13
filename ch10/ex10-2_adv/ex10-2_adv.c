#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    NAMESIZE = 55+1, // 名前の最大文字数＋空文字バイト
    MONSTERSIZE = 5,  // モンスターの数
    LINESIZE = 1024 // 一行読むバッファの大きさ
};

struct skillset {
    int poison, sleep, paralysis;
};

struct monster {
    char name[100];
    char family[100]; // ファミリー名
    int hp, mp;
    struct skillset condition;
};

int read_monster(char *filename, struct monster *mon, int n);

int read_monster(char *filename, struct monster *mon, int n) {
    FILE *fp;
    int i;
    char buf[LINESIZE], *p, *buf_b, *buf_c;

    // ファイルを開く
    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        // 1行ずつ読み込んで改行文字を除去
        if ((p = strchr(buf, '\n')) != NULL)
            *p = '\0';

        // TODO: 要リファクタ
        // カンマの位置を順番に探して空白文字で潰し、空白文字の前部分を構造体の該当メンバに代入
        // 残った文字列を別のポインタで指す
        // 同じようにカンマを探して空白文字で潰し、前部分をメンバに代入し続ける

        // 1つ目のカンマ(name)
        if ((p = strchr(buf, ',')) == NULL) {
            fprintf(stderr, "変なデータです：%s\n", buf);
            continue;  // カンマが無ければ変な行なので無視
        }
        buf_b = p + 1; // カンマの次からの残りの文字列
        *p = '\0';  // 最初のカンマを空文字で潰す。bufがnameのみになる
        strncpy(mon[i].name, buf, NAMESIZE-1); // nameを入れる
        mon[i].name[NAMESIZE-1] = '\0';  // 長すぎた場合対策

        // 2つ目のカンマ(family)
        p = strchr(buf_b, ',');
        buf_c = p + 1;
        *p = '\0';
        strncpy(mon[i].family, buf_b, NAMESIZE-1); // familyを入れる
        mon[i].family[NAMESIZE-1] = '\0';

        // 3つ目のカンマ(HP)
        p = strchr(buf_c, ',');
        buf_b = p + 1;
        *p = '\0';
        mon[i].hp = atoi(buf_c);

        // 4つ目のカンマ(MP)
        p = strchr(buf_b, ',');
        buf_c = p + 1;
        *p = '\0';
        mon[i].mp = atoi(buf_b);

        // 5つ目のカンマ(Poison)
        p = strchr(buf_c, ',');
        buf_b = p + 1;
        *p = '\0';
        mon[i].condition.poison = atoi(buf_c);

        // 6つ目のカンマ(sleep)
        p = strchr(buf_b, ',');
        buf_c = p + 1;
        *p = '\0';
        mon[i].condition.sleep = atoi(buf_b);

        // 残りはParalysis
        mon[i].condition.paralysis = atoi(buf_c);

        if (++i >= n)
            break;
    }

    fclose(fp);
    return i;
}

int main(int arg, char *argv[]) {
    struct monster x[MONSTERSIZE];
    int n;

    n = read_monster(argv[1], x, MONSTERSIZE);
    for (int i = 0; i < n; i++) 
        printf("%s (%s): HP=%d MP=%d poison=%d sleep=%d paralysis=%d\n",
             x[i].name, x[i].family, x[i].hp, x[i].mp, 
             x[i].condition.poison, x[i].condition.sleep,
             x[i].condition.paralysis);
    return 0;
}