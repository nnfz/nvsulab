#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>

typedef struct {
    wchar_t surname[30];
    wchar_t gorod[30];
    wchar_t phone[15];
} Participant;

void sort(Participant p[], int n) {
    Participant temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (wcscmp(p[i].surname, p[j].surname) > 0) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int search(Participant p[], int n, wchar_t *surname) {
    for (int i = 0; i < n; i++) {
        if (wcscmp(p[i].surname, surname) == 0)
            return i;
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);

    Participant p[] = {
        {L"Иванов", L"Москва", L"123-45-67"},
        {L"Петров", L"Казань", L"234-56-78"},
        {L"Сидоров", L"Самара", L"345-67-89"},
        {L"Алексеев", L"Омск", L"456-78-90"}
    };
    int n = 4;
    int choice;
    wchar_t surname[30];
    
    wprintf(L"Список участников конференции:\n");
    for (int i = 0; i < n; i++)
        wprintf(L"%ls %ls %ls\n", p[i].surname, p[i].gorod, p[i].phone);
    
    wprintf(L"\n1. Сортировать по фамилии\n2. Найти участника\n\nВыберите: ");
    wscanf(L"%d", &choice);
    
    if (choice == 1) {
        sort(p, n);
        wprintf(L"\nОтсортированный список:\n");
        for (int i = 0; i < n; i++)
            wprintf(L"%ls %ls %ls\n", p[i].surname, p[i].gorod, p[i].phone);
    }
    else if (choice == 2) {
        wprintf(L"Введите фамилию: ");
        wscanf(L"%ls", surname);
        int i = search(p, n, surname);
        if (i != -1)
            wprintf(L"\nНайдено: %ls %ls %ls\n", p[i].surname, p[i].gorod, p[i].phone);
        else
            wprintf(L"\nНе найдено\n");
    }
    
    system("pause");
    return 0;
}