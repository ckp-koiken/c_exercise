#include <stdio.h>

enum { NCELL = 31 };

void show(char *p) {
    for (int i = 0; i < NCELL; i++)
        printf("%c", p[i] ? 'O' : '.');
    printf("\n");
}
int main(void) {
    char cell[2][NCELL] = {{0}}; // 交互に使う２つの配列；セルは全て０で初期化
    char *curp = cell[0], *nextp = cell[1]; // curpが今の状態、nextpが次の状態
    char *tp;  // 入れ替え用の一時変数

    curp[NCELL/2] = 1;  // 真ん中のセル1つだけが1、他は0
    show(curp);  // 最初の状態を表示

    return 0;
}
