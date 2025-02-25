#include <stdio.h>

int main(void) {
    int i, n;
    char str[1024] = "Yahho-";

    i = 0;
    while (str[i] != '\0')
        i++;

    n = 0;
    for (int j = i; j < i+i; j++) {
        str[j] = str[n];
        n++;
    }

    printf("%s\n", str);
    return 0;
}