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
    srand((unsigned int)time(NULL));

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

void removeEven(Spisok **head) {
    while (*head != NULL && (*head)->data % 2 == 0) {
        Spisok *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    if (*head == NULL) return;

    Spisok *current = *head;
    while (current->next != NULL) {
        if (current->next->data % 2 == 0) {
            Spisok *tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        } else {
            current = current->next;
        }
    }
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
    int N;

    wprintf(L"Введите размер списка: ");
    wscanf(L"%d", &N);

    fillRand(&head, N, 1, 100);

    wprintf(L"Исходный список: ");
    print(head);

    removeEven(&head);

    wprintf(L"После удаления чётных: ");
    print(head);

    clearList(&head);

    system("pause");
    return 0;
}
