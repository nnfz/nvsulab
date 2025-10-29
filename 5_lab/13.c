#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int sogl(wchar_t c) {
    wchar_t lower_c = towlower(c);
    
    wchar_t v[] = L"аеёиоуыэюяaeyuio";
    
    for (int i = 0; v[i] != L'\0'; i++) {
        if (lower_c == v[i]) {
            return 0;  // гласная
        }
    }
    
    return 1;  // согласная
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    wchar_t s;
    
    wprintf(L"Введите букву: ");
    wscanf(L"%lc", &s);
    
    int r = sogl(s);
    
    if (r == 1) {
        wprintf(L"Буква '%lc' согласная\n", s);
    } else {
        wprintf(L"Буква '%lc' гласная\n", s);
    }
    
    return 0;
}