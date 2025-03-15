#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct station {
    char name[50];  // 駅名
    int express;    // のぞみ停車駅なら1、そうでないなら0
    struct station *next;
};

int main(void) {
    char *station_info[] = {
        "1 Tokyo", "1 Shinagawa", "0 Atami", "0 Shizuoka", 
        "1 Nagoya", "0 Maibara", "1 Kyoto", NULL
    };

    struct station *head, *tail, *p; // headは線形リストの先頭要素
    char **sp;  // 文字列へのポインタの配列の要素を1つずつ処理するためのポインタ

    // 線形リストを作る
    head = tail = NULL;
    for (sp = station_info; *sp != NULL; sp++) {
        if ((p = malloc(sizeof(struct station))) == NULL) {
            perror("malloc");
            break;
        }
        strcpy(p->name, *sp+2); // 駅名を入れる（先頭から2文字目からが駅名）
        p->express = (**sp == '1'); // データ文字列の先頭が'1'ならのぞみ停車駅
        if (tail)   // すでに一つ以上リストに入れられている
            tail->next = p; // 最後の要素の次にpが指す要素をつなぐ
        else    // まだ一つもリストに入れていない
            head = p;  // pを先頭の要素とする
        tail = p;  // 今つないだ要素が今のところ最後の要素
    }
    tail->next = NULL;  // 最後の要素のnextに空ポインタを入れる

    // 路線を表示
    for (p = head; p != NULL; p = p->next)  // 要素を一つずつ
        printf("%c %s\n", p->express ? '+' : '|', p->name); // 情報を表示

    // すべてのノードの領域を解放
    while (head) {  // リストにノードがある間
        p = head->next; // 次の要素へのリンクをとっておいて
        free(head); // 先頭要素の領域を解法し
        head = p;   // 取っておいたリンク先を先頭とする
    }
    return 0;
}