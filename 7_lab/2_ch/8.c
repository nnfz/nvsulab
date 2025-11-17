#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>

typedef struct {
    wchar_t surname[30];
    int visits;
    wchar_t trainer[30];
} Client;

void printClients(Client c[], int n) {
    for (int i = 0; i < n; i++) {
        wprintf(L"%ls | Посещений: %d | Тренер: %ls\n",
                c[i].surname, c[i].visits, c[i].trainer);
    }
}

void sortByVisits(Client c[], int n) {
    Client temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i].visits < c[j].visits) {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
}

int search(Client c[], int n, wchar_t *surname) {
    for (int i = 0; i < n; i++) {
        if (wcscmp(c[i].surname, surname) == 0)
            return i;
    }
    return -1;
}

void modifyClient(Client c[], int n) {
    wchar_t surname[30];

    wprintf(L"Введите фамилию клиента: ");
    wscanf(L"%ls", surname);

    int index = search(c, n, surname);
    if (index == -1) {
        wprintf(L"Клиент не найден.\n");
        return;
    }

    int choice;
    wprintf(L"\nИзменить:\n");
    wprintf(L"1. Фамилию\n");
    wprintf(L"2. Частоту посещений\n");
    wprintf(L"3. Тренера\n");
    wprintf(L"Выбор: ");
    wscanf(L"%d", &choice);

    switch (choice) {
        case 1:
            wprintf(L"Новая фамилия: ");
            wscanf(L"%ls", c[index].surname);
            break;

        case 2:
            wprintf(L"Новое количество посещений: ");
            wscanf(L"%d", &c[index].visits);
            break;

        case 3:
            wprintf(L"Новый тренер: ");
            wscanf(L"%ls", c[index].trainer);
            break;
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);

    Client clients[] = {
        {L"Иванов", 3, L"Петров"},
        {L"Сидоров", 5, L"Алексеев"},
        {L"Смирнов", 2, L"Романов"},
        {L"Кузнецов", 4, L"Сергеев"}
    };

    int n = 4;
    int choice;

    wprintf(L"Список клиентов:\n");
    printClients(clients, n);

    wprintf(L"\n1. Сортировать по посещениям\n");
    wprintf(L"2. Изменить данные клиента\n");
    wprintf(L"Выберите: ");
    wscanf(L"%d", &choice);

    if (choice == 1) {
        sortByVisits(clients, n);
        wprintf(L"\nОтсортированный список:\n");
        printClients(clients, n);
    }
    else if (choice == 2) {
        modifyClient(clients, n);
        wprintf(L"\nПолучившийся список:\n");
        printClients(clients, n);
    }

    system("pause");
    return 0;
}
