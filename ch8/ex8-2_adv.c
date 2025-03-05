#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sign(void);

void sign(void) {
    static char signal[4] = "";

    if (strcmp(signal, "赤") == 0) {
        sleep(3);
        strcpy(signal, "緑");
        printf("%s\n", signal);
    } else if (strcmp(signal, "緑") == 0) {
        sleep(5);
        strcpy(signal, "黄");
        printf("%s\n", signal);
    } else if (strcmp(signal, "黄") == 0) {
        sleep(1);
        strcpy(signal, "赤");
        printf("%s\n", signal);
    } else {
        strcpy(signal, "緑");
        printf("%s\n", signal);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("点滅する回数を指定してください\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < atoi(argv[1]); i++)
        sign();

    return 0;
}