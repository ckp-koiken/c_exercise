#include <stdio.h>

// stack.cで実装された関数のプロトタイプ宣言
int push(int item);
int pop(void);
void show(void);

int main(void) {
    int n;

    printf("0で表示、-1で1つ取り出し、-2で終了\n");
    for (;;) {
        printf("いくらの領収書？");
        scanf("%d", &n);
        if (n == -2)
            break;  // 入力が-2ならループを抜ける
        else if (n == -1) {  // 入力が-1なら取り出す
            if ((n = pop()) < 0)
                printf("空です\n"); // 取り出せないならメッセージを出す
            else 
                printf("%d円の領収書です\n", n);
        } else if (n == 0) {    // 入力が0なら一覧を表示する
            show();
        } else      // 入力が正ならスタックに入れる
            push(n);
    }

    while ((n = pop()) > 0) // なくなるまでスタックから取り出す
        printf("%d円の領収書です\n", n);

    printf("お疲れ様でした！\n");
    return 0;
}