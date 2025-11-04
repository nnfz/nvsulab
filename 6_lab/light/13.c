#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    wchar_t str[] = L"Слово буква";
    wchar_t ch;
    int i, cnt = 0;

    wprintf(L"%ls\n", str);
    wprintf(L"Введите букву\n");
    wprintf(L"-> ");
    wscanf(L"%lc", &ch);

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

    return 0;
}