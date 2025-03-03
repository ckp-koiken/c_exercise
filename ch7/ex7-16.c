#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;

    if (argc != 3) {
        printf("使い方: %s 回数 メッセージ\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n  = atoi(argv[1]);    // argv[1]が回数（文字列）、atoiで整数に
    for (int i = 0; i < n; i++)
        printf("%s\n", argv[2]);  // argv[2]がメッセージ
    return 0;
}