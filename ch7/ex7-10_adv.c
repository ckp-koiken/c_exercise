#include <stdio.h>

void comma_separate(unsigned long int n, char *bufp);

void comma_separate(unsigned long int n, char *bufp) {
    int count;
    char *p, c;
    
    sprintf(bufp, "%ld", n);

    p = bufp;
    
    // pを最後まで進ませる
    while (*p != '\0') {
        p++;
    }
    p--; // \0のひとつ前を指す

    count = 0;
    // pを戻しながら、3桁ごとに,を入れてbufpに入れる
    // TODO: bufpに入れる処理を要修正
    while (*bufp != '\0') {
        if (count % 3 != 0) {
            c = *p;
            *bufp = *p;
            *p = c;
        } else {
            *bufp = ',';
            bufp++;
            c = *p;
            *bufp = *p;
            *p = c;
        }
        count++;
        bufp++;
        p--;
    }

    // TODO: bufpをひっくり返す
}

int main(void) {
    unsigned long int num;
    char buf[1024];

    printf("金額？");
    scanf("%ld", &num);

    comma_separate(num, buf);
    printf("%s円\n", buf);
    return 0;
}