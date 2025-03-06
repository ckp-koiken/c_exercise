#include <stdio.h>

// TODO: stack.cで関数を実装
int push();
int pop();

int main(void) {
    int n;

    printf("0を入力すると1つ抜き、-1を入力すると全部取り出します\n");
    for (;;) {
        printf("いくらの領収書？");
        scanf("%d", &n);
        if (n < 0)
            break;  // 入力が-1ならループを抜ける
        else if (n == 0) {  // 入力が0なら取り出す
            if ((n = pop()) < 0)
                printf("空です\n"); // 取り出せないならメッセージを出す
            else 
                printf("%d円の領収書です\n", n);
        } else      // 入力が正ならスタックに入れる
            push(n);
    }

    while ((n = pop()) > 0) // なくなるまでスタックから取り出す
        printf("%d円の領収書です\n", n);

    printf("お疲れ様でした！\n");
    return 0;
}