#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>

int main() {
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wchar_t str[100];
    wchar_t search[100];
    
    wprintf(L"Введите строку: ");
    fgetws(str, 100, stdin);
    str[wcscspn(str, L"\n")] = L'\0';

    wprintf(L"Введите слово для поиска: ");
    wscanf(L"%s", search);
    
    wchar_t *context_ptr = NULL; 
    wchar_t *word = wcstok(str, L" ", &context_ptr);

    int found = 0;
    
    wprintf(L"Слова, содержащие буквосочетание '%s': [\n", search);
    
    while (word != NULL) {
        if (wcsstr(word, search) != NULL) {
            wprintf(L"%s\n", word);
            found = 1;
        }
        word = wcstok(NULL, L" ", &context_ptr);
    }
    printf("]");
    if (!found) {
        wprintf(L"Слов с буквосочетанием '%s' не найдено.\n", search);
    }
    
    system("pause");
    return 0;
}