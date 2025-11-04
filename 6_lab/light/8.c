#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    int i;
    
    printf("Введите строку\n");
    printf("-> ");
    scanf("%s", str);

    int cnt = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (isdigit((char)str[i]) || str[i] == '*' || str[i] == '-' || str[i] == '+'){
            cnt++;
        }
    }
    
    printf("Знаков +-* и цифр: %d\n", cnt);

    
    return 0;
}