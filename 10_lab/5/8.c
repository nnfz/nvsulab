#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>

#include "mymod.h"

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
