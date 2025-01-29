#include <stdio.h>

int main(void) {
    int key;
    char plain, cipher;

    printf("平文？");
    scanf("%c", &plain);
    printf("暗号キー？");
    scanf("%d", &key);
    int check = (plain - 97 - key) % 26;
    
    // TODO: if文を使わない方法もあるのか模索
    if (check < 0) {
        cipher = 26 + check + 97;
    } else {
        cipher = 0 + check + 97;
    }
    printf("暗号文は「%c」\n", cipher);
    return 0;
}
