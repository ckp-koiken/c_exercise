#include <stdio.h>

int main(void) {
    int n, people;
    printf("お菓子の個数？");
    scanf("%d", &n);
    printf("人数？");
    scanf("%d", &people);
    if (people == 0 || n % people > 0) // 論理演算子と条件演算子は左から評価する
        printf("余ります\n");
    else
        printf("配り切れます\n");

    return 0;
}
    
    // 別解
    // if (people != 0 && n % people == 0)
    //     printf("配り切れます\n");
    // else 
    //     printf("余ります\n");
