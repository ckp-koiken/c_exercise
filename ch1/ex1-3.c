#include <stdio.h>

int main(void) {
    int num;
    
    printf("decimal number? ");
    scanf("%d", &num); // 10進数入力 
    printf("hexdecimal = %x\n", num); // 16進数表示
    return 0;
}
