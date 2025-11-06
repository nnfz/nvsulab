#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    wchar_t ch;
    int i, cnt = 0;

    wprintf(L"Введите строку: ");
    fgetws(str, 100, stdin);
    str[wcscspn(str, L"\n")] = L'\0';

    wprintf(L"Введите букву: ");
    wscanf(L" %lc", &ch);

    int len = wcslen(str);

    for(i = 0; i < len; i++){
        if ((str[i] == L' ' || str[i] == L'\0') && i > 0) {
            wchar_t last_char = str[i-1];
            if (last_char == ch) {
                cnt++;
            }
        }
    }

    if (len > 0) {
        wchar_t last_char = str[len-1];
        if (last_char == ch) {
            cnt++;
        }
    }

    wprintf(L"Количество слов, заканчивающихся на букву '%lc': %d\n", ch, cnt);

    system("pause");
    return 0;
}