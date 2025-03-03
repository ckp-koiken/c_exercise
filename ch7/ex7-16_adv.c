#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char c;

    // argcでエラー判定
    if (argc < 3) {
        printf("引数の数が誤っています\n");
        exit(EXIT_FAILURE);
    }

    c = *argv[1];
    // argvをNULLまで探索
    for (int i = 2; argv[i] != NULL; i++) {
        printf("\"%s\" ", argv[i]);
        for (int j = 1; argv[i][j] != '\0'; j++) {  
            // 添字ごとの文字列の中からcを探索
            if (argv[i][j] == c)
                printf("%d文字目", j+1);
        }
        printf("\n");
    }

    return 0;
}