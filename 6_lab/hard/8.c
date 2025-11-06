#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>

int main() {
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wchar_t str[100];

    wprintf(L"Введите строку: ");
    fgetws(str, sizeof(str) / sizeof(wchar_t), stdin);
    str[wcscspn(str, L"\n")] = L'\0';

    int i, j = 0;
    int len = wcslen(str);
    
    for (i = 0; i < len; i++) {
        if (str[i] != L' ') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    
    wprintf(L"Без пробелов: %ls \n", str);
    
    system("pause");
    return 0;
}