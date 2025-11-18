#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>

#define N 6


typedef struct {
    wchar_t surname[30];
    wchar_t subject[30];
    int expa;
} Teacher;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);


    Teacher teachers[N] = {
        {L"Иванова",  L"Математика",   12},
        {L"Петров",   L"Физика",        8},
        {L"Сидорова", L"Химия",        10},
        {L"Кузнецов", L"Информатика",   5},
        {L"Смирнов",  L"Математика",   20},
        {L"Орлова",   L"Биология",      7}
    };

    wchar_t inSubj[30];
    int found = 0;


    wprintf(L"Список всех учителей:\n");
    wprintf(L"---------------------------------------------------------------\n");
    wprintf(L"%-15ls | %-15ls | %ls\n", 
            L"Фамилия", L"Предмет", L"Стаж");
    wprintf(L"---------------------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        wprintf(L"%-15ls | %-15ls | %2d лет\n",
                teachers[i].surname,
                teachers[i].subject,
                teachers[i].expa);
    }

    wprintf(L"---------------------------------------------------------------\n\n");


    wprintf(L"Введите предмет: ");
    fgetws(inSubj, 30, stdin);


    int len = wcslen(inSubj);
    if (len > 0 && inSubj[len - 1] == L'\n')
        inSubj[len - 1] = L'\0';


    wprintf(L"\nУчителя, которые преподают предмет \"%ls\":\n", inSubj);
    wprintf(L"---------------------------------------------------------------\n");

    for (int i = 0; i < N; i++) {

        if (_wcsicmp(teachers[i].subject, inSubj) == 0) {
            wprintf(L"%ls — %ls, стаж: %d лет\n",
                    teachers[i].surname,
                    teachers[i].subject,
                    teachers[i].expa);
            found = 1;
        }
    }

    if (!found) {
        wprintf(L"Нет учителей, преподающих этот предмет.\n");
    }

    wprintf(L"\n");
    system("pause");
    return 0;
}
