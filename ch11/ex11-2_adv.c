#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct station {
    char name[50];  // 駅名
    int express;    // のぞみ停車駅なら1、そうでないなら0
    struct station *next;
};

char *station_info[] = {
    "1 Tokyo", "1 Shinagawa", "0 Atami", "0 Shizuoka", 
    "1 Nagoya", "0 Maibara", "1 Kyoto", NULL
};

struct station *make_line(void);
void show_line(struct station *head);
void free_line(struct station *head);
struct station *find_station(char *name, struct station *head);

//　線形リストを作る
struct station *make_line(void) {
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
    return head;
}

// 路線を表示する
void show_line(struct station *head) {
    struct station *p;

    for (p = head; p != NULL; p = p->next)  // 要素を一つずつ
        printf("%c %s\n", p->express ? '+' : '|', p->name); // 情報を表示
}

// 線形リストを解放する
void free_line(struct station *head) {
    struct station *p;

    while (head) {  // リストにノードがある間
        p = head->next; // 次の要素へのリンクをとっておいて
        free(head); // 先頭要素の領域を解法し
        head = p;   // 取っておいたリンク先を先頭とする
    }
}

// 指定された名前の駅を探す（なければNULLを返す）
struct station *find_station(char *name, struct station *head) {
    struct station *p;

    for (p = head; p != NULL; p = p->next) {  // ノードを一つずつみる
        if (strcmp(p->name, name) == 0)
            break;  // 駅名が一致したらループを抜ける
    }
    return p;  // ループを回り切ったらpはNULL、breakしたなら見つけたノード
}

int main(void) {
    struct station *head, *p;
    char name[50];
    int flag;

    head = make_line();
    show_line(head);
    printf("駅名[無指定なら*]？");
    scanf("%s", name);
    printf("のぞみ停車駅[停車しない0、停車する1、無指定は2]？");
    scanf("%d", &flag);

    // TODO: 要リファクタ（関数にする）
    if (!strcmp(name, "*")) {
        // *なら線形リストをheadからNULLまで検索
        for (p = head; p != NULL; p = p->next) {
            // flagの値に応じて絞り込みを変える
            switch (flag) {
                case 0:
                    // のぞみが停車しない駅を抽出
                    if (p->express == 0)
                        printf("駅名%s、のぞみは停車しません\n", p->name);
                    break;
                case 1:
                    // のぞみが停車する駅を抽出
                    if (p->express == 1)
                        printf("駅名%s、のぞみ停車駅です\n", p->name);
                    break;
                case 2:
                    // のぞみ無指定
                    if (p->express == 0)
                        printf("駅名%s、のぞみは停車しません\n", p->name);
                    else
                        printf("駅名%s、のぞみ停車駅です\n", p->name);
                    break;
                default:
                    printf("検索条件が間違っています\n");
                    break;
            }
        }
    } else {
        // 駅名が指定されているなら線形リストをその駅まで進める
        // find_stationを使う
        if ((p = find_station(name, head)) == NULL)
            printf("%sという駅はありません\n", name);
        else if (p->express) { // 駅名がのぞみ停車駅のとき
            if (flag == 0)
                printf("条件に合う駅はありません\n");
            else
                printf("駅名%s、のぞみ停車駅です\n", name);
        }
        else { // 駅名がのぞみ停車駅でないとき
            if (flag == 1)
                printf("条件に合う駅はありません\n");
            else
                printf("駅名%s、のぞみは停まりません\n", name);
        }
    }
        
    free_line(head);
        
    return 0;
}
