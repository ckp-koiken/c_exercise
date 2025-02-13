#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { T_SIZE = 9 };

int main(void) {
    int i, j, rnt[T_SIZE][T_SIZE];    

    printf(" |   1|   2|   3|   4|   5|   6|   7|   8|   9|\n");
    printf("-+----+----+----+----+----+----+----+----+----+\n");
    // 乱数表を作りながら表示
    srand(time(0));

    for (i = 0; i < T_SIZE; i++) {
        printf("%1d|", i+1);
        for (j = 0; j < T_SIZE; j++) {
            rnt[i][j] = rand() % 10000;
            printf("%04d|", rnt[i][j]);
        }
        printf("\n");
    }

    printf("行？");
    scanf("%d", &i);
    printf("列？");
    scanf("%d", &j);
    printf("%04dです\n", rnt[i-1][j-1]); 
    
    return 0;
}
