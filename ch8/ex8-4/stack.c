#include <stdio.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))

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