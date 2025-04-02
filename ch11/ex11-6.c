#include <stdio.h>

void hanoi(int n, char from, char work, char to);

void hanoi(int n, char from, char work, char to) {
    if (n == 1) {
        // 1枚なら直接目的地(to)へ
        // ベースケース
        printf("%d: %c -> %c \n", n, from, to);
    } else {
        // いったん作業場所(work)へ
        hanoi(n - 1, from, to, work);
        printf("%d: %c -> %c\n", n, from, to);
        // 作業場所(work)から目的地(to)へ
        hanoi(n - 1, work, from, to);
    }
}

int main(void) {
    int n;

    printf("円盤の枚数？");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
