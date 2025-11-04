#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    int i;
    
    printf("Введите число и нажмите <Enter>\n");
    printf("-> ");
    scanf("%s", str);

    int is_int = 1;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit((char)str[i])) {
            is_int = 0;
            break;
        }
    }
    
    
    if (is_int) {
        printf("Введенная строка является целым числом.\n");
    } else {
        printf("Введенная строка не является целым числом.\n");
    }
    
    return 0;
}