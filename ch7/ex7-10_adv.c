#include <stdio.h>

int main(void) {
    unsigned long int num;
    char buf[1024];
    
    printf("金額？");
    scanf("%ld", &num);
    sprintf(buf, "%ld", num);

    // comma_separate(num, buf);
    printf("%s円\n", buf);
    return 0;
}