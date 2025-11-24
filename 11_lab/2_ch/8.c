#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>

typedef struct Spisok {
    int data;
    struct Spisok *next;
} Spisok;

Spisok* create(int value) {
    Spisok *newSpisok = (Spisok*)malloc(sizeof(Spisok));
    newSpisok->data = value;
    newSpisok->next = NULL;
    return newSpisok;
}

void add(Spisok **head, int value) {
    Spisok *newSpisok = create(value);
    if (*head == NULL) {
        *head = newSpisok;
        return;
    }
    Spisok *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newSpisok;
}

void fillRand(Spisok **head, int N, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int randomValue = min + rand() % (max - min + 1);
        add(head, randomValue);
    }
}

void print(Spisok *head) {
    Spisok *current = head;
    while (current != NULL) {
        wprintf(L"[%d] ", current->data);
        current = current->next;
    }
    wprintf(L"\n");
}

Spisok* copyList(Spisok *head) {
    if (head == NULL) return NULL;
    Spisok *newHead = create(head->data);
    Spisok *currentNew = newHead;
    Spisok *currentOld = head->next;
    while (currentOld != NULL) {
        currentNew->next = create(currentOld->data);
        currentNew = currentNew->next;
        currentOld = currentOld->next;
    }
    return newHead;
}

void insE(Spisok **head, int E) {
    Spisok *current = *head;
    while (current != NULL && current->data != E) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    Spisok *copy = copyList(*head);
    Spisok *temp = current->next;
    current->next = copy;

    while (copy->next != NULL) {
        copy = copy->next;
    }
    copy->next = temp;
}

void clearList(Spisok **head) {
    Spisok *current = *head;
    Spisok *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    
    Spisok *head = NULL;
    int N, E;
    
    wprintf(L"Введите размер списка: ");
    wscanf(L"%d", &N);
    
    fillRand(&head, N, 1, 5);
    
    wprintf(L"Список: ");
    print(head);
    
    wprintf(L"Введите значение Е для поиска: ");
    wscanf(L"%d", &E);
    
    insE(&head, E);
    
    wprintf(L"Список после вставки копии после первого вхождения %d: ", E);
    print(head);
    
    clearList(&head);
    
    system("pause");
    return 0;
}
