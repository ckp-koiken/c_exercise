#include <stdio.h>

int main(void) {
    int c;

    printf("文字列を入力して下さい: ");
    while((c = getchar()) != '\n') 
        printf("文字'%c' 文字コード%d\n", c, c);
    
    return 0;
}