#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { T_SIZE = 9 };

int main(void) {
    int i, j, dir, rnt[T_SIZE][T_SIZE];    

    printf(" | 1| 2| 3| 4| 5| 6| 7| 8| 9|\n");
    printf("-+--+--+--+--+--+--+--+--+--+\n");
    // 乱数表を作りながら表示
    srand(time(0));

    for (i = 0; i < T_SIZE; i++) {
        printf("%1d|", i+1);
        for (j = 0; j < T_SIZE; j++) {
            rnt[i][j] = rand() % 10;
            printf("%2d|", rnt[i][j]);
        }
        printf("\n");
    }

    printf("行？");
    scanf("%d", &i);
    printf("列？");
    scanf("%d", &j);
    
    // 方向の読み取り
    printf("向き[1=右、2=下]？");
    scanf("%d", &dir);

    // 暗証番号の表示
    printf("暗証番号は");
    if (dir == 1) {
        for (int k = 0; k < 4; k++)
            printf("%d", rnt[i-1][j-1+k]);
    } else {
        for (int k = 0; k < 4; k++)
            printf("%d", rnt[i-1+k][j-1]);
    }
    printf("です\n");
    
    return 0;
}
