#include <stdio.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))

// staticをつけているのでstack.cの終わりまで有効
// externをつけても外ファイルからアクセスできない
static int stack[10];   // スタックのデータを保持する配列
static int sp = -1;     // スタックポインタ：スタックの「トップ」の添字

int push(int item) {
    if (sp >= (int)NELEMS(stack)-1) {   // 配列領域がいっぱいなら
        printf("もう入りません…\n");
        return -1;
    } else 
        return stack[++sp] = item;  // itemをスタックに積む
}

int pop(void) {
    if (sp < 0)
        return -1;  // データが入っていないなら-1を返す
    else 
        return stack[sp--]; // トップのデータを返し、スタックポインタをデクリメントする
}

void show(void) {
    int p;  // スタックポインタの代わりに表示のために使う変数
    if (sp < 0)
        printf("データがありません...\n"); // データが入っていないなら警告を表示
    else {
        p = sp; // show()が呼ばれた時のスタックポインタをpに入れる
        printf("領収書: ");
        while (p >= 0)  // 表示しながらpをデクリメント
            printf("%d ", stack[p--]);
        printf("\n");
    }
}