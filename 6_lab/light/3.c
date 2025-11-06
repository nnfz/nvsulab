#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    char str[100];
    int i;
    
    wprintf(L"Введите число: ");
    scanf("%s", str);

    int is_int = 1;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit((char)str[i])) {
            is_int = 0;
            break;
        }
    }
    
    
    if (is_int) {
        wprintf(L"Целое число.\n");
    } else {
        wprintf(L"Не целое число.\n");
    }
    
    system("pause");
    return 0;
}