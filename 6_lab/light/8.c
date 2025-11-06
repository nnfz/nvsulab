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
    
    wprintf(L"Введите строку: ");
    scanf("%s", str);

    int cnt = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (isdigit((char)str[i]) || str[i] == '*' || str[i] == '-' || str[i] == '+'){
            cnt++;
        }
    }
    
    wprintf(L"Знаков +-* и цифр: %d\n", cnt);

    system("pause");
    return 0;
}