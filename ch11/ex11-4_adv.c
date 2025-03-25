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
struct station *find_position(char *name, struct station *head);
void insert_station(struct station *p, struct station *pos);

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

// 指定駅の直前のノードを返す
struct station *find_position(char *name, struct station *head) {
    struct station *p, *prev;
    prev = NULL;

    for (p = head; p != NULL; p = p->next) {  // pで指定された駅を探す
        if (strcmp(p->name, name) == 0)       // 見つけたらループを抜ける
            break;
        prev = p;                             // ひとつ前のノードをprevで指しておく
    }
    if (p == NULL) {
        printf("%sという駅はありません\n", name);
        exit(EXIT_FAILURE);
    }
    
    return prev;
}

// ノードを挿入する関数
void insert_station(struct station *p, struct station *pos) {
    char yn[10];
    
    // 領域を確保
    if ((p = malloc(sizeof(struct station))) == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // 駅の情報受け取り
    printf("駅名？");
    scanf("%s", p->name);
    printf("のぞみ停車駅？[y/n]？");
    scanf("%s", yn);
    p->express = (*yn == 'y' || *yn == 'Y');

    // 線形リストに追加
    p->next = pos->next;   // そのノードを自分の次につなぐ
    pos->next = p;         // 自分をposの次につなぐ
}

int main(void) {
    struct station *p, *pos;
    struct station head;  // 先頭要素を表すためのダミーポインタ
    char name[50];

    // headのnextに駅のノードを指させる
    // head.nextはstruct station *型
    head.next = make_line();
    show_line(head.next);

    printf("どの駅の前に追加しますか？");
    scanf("%s", name);

    pos = find_position(name, &head);
    insert_station(p, pos);

    show_line(head.next);
    free_line(head.next);

    return 0;
}