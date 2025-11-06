#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>

int sogl(wchar_t c) {
    wchar_t lower_c = towlower(c);
    wchar_t v[] = L"аеёиоуыэюяaeyuio";
    
    for (int i = 0; v[i] != L'\0'; i++) {
        if (lower_c == v[i]) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wchar_t s;
    
    wprintf(L"Введите букву: ");
    wscanf(L"%lc", &s);
    
    if (sogl(s)) {
        wprintf(L"Буква '%lc' согласная\n", s);
    } else {
        wprintf(L"Буква '%lc' гласная\n", s);
    }
    system("pause");
    return 0;
}