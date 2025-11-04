#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    
    printf("Введите строку\n");
    printf("-> ");
    fgets(str, sizeof(str), stdin);
    
    int i, j = 0;
    int len = strlen(str);
    
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0'; // Завершаем строку
    
    printf("Без пробелов: %s \n", str);
    
    return 0;
}