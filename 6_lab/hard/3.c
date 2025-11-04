#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>

int main() {

    char str[] = "Один два двадцатьтри четыре";
    char search[100];
    
    printf("Заданная строка: %s\n", str);
    printf("Введите слово для поиска: ");
    printf("-> ");
    scanf("%s", search);
    
    char *word = strtok(str, " ");
    int found = 0;
    
    printf("Слова, содержащие буквосочетание '%s': [\n", search);
    
    while (word != NULL) {
        if (strstr(word, search) != NULL) {
            printf("%s\n", word);
            found = 1;
        }
        word = strtok(NULL, " ");
    }
    printf("]");
    if (!found) {
        printf("Слов с буквосочетанием '%s' не найдено.\n", search);
    }
    
    return 0;
}