#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>

#define N 5
#define SUBJ 3

typedef struct {
    wchar_t surname[30];
    int ball[SUBJ];
} Student;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Student students[N] = {
        {L"Иванов"},
        {L"Петров"},
        {L"Сидоров"},
        {L"Кузнецов"},
        {L"Смирнов"}
    };

    int i, j;
    int subject;
    float clasavg = 0.0;
    float all_avg = 0.0;

    srand(time(NULL));

    wprintf(L"Список учеников:\n");

    wprintf(L"Фамилия         | П1 | П2 | П1\n");
    printf("-----------------------------------\n");

    for (i = 0; i < N; i++) {
        wprintf(L"%-15ls | ", students[i].surname);

        for (j = 0; j < SUBJ; j++) {
            students[i].ball[j] = 2 + rand() % 4;
            wprintf(L"%2d | ", students[i].ball[j]);
        }
        printf("\n");
    }

    printf("-----------------------------------\n");

    wprintf(L"\nВведите номер предмета (1-3): ");
    scanf("%d", &subject);
    subject--;

    for (i = 0; i < N; i++) {
        clasavg += students[i].ball[subject];
    }
    clasavg /= N;

    wprintf(L"\nСредний балл класса по предмету %d: %.2f\n",
           subject + 1, clasavg);

    for (i = 0; i < N; i++) {
        float avg = 0;
        for (j = 0; j < SUBJ; j++) {
            avg += students[i].ball[j];
        }
        avg /= SUBJ;
        all_avg += avg;
    }
    all_avg /= N;

    wprintf(L"Средний балл класса: %.2f\n\n", all_avg);

    wprintf(L"Ученики со средним баллом выше среднего:\n");


    for (i = 0; i < N; i++) {
        float avg = 0;
        for (j = 0; j < SUBJ; j++) {
            avg += students[i].ball[j];
        }
        avg /= SUBJ;

        if (avg > all_avg) {
            wprintf(L"  %ls — средний балл: %.2f\n",
                    students[i].surname, avg);
        }
    }

    system("pause");
    return 0;
}
