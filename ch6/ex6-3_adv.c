#include <stdio.h>

int main(void) {
    int a[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, 
                    {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("a[0][0] is %d\n", a[0][0]);
    printf("next of a[0][0] is %d\n", *(a[0]+1));
    // a[0][0](=1)の隣は2なのでa[0][1]

    printf("address of a[0][0] is %p\n", a[0]);
    printf("next address of a[0][0] is %p\n", (a[0]+1));
    // a[0][0]とその隣は4バイト離れている

    printf("sizeof a[0] is %zu\n", sizeof(a[0]));
    // a[0]の大きさは20バイト

    printf("address of a[0] is %p\n", &a[0]);
    printf("address of a[1] is %p\n", &a[1]);
    // a[0]とa[1]は20バイト離れているので隣接していない
    
    return 0;
}
