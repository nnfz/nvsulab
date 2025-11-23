#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <io.h>
#include <fcntl.h>

#define SUBJ 3

typedef struct {
    wchar_t surname[30];
    int ball[SUBJ];
} Student;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    
    int N;
    wprintf(L"Введите количество учеников: ");
    wscanf(L"%d", &N);

    Student *students = (Student*)calloc(N, sizeof(Student));

    int i, j;
    int subject;
    float clasavg = 0.0;
    float all_avg = 0.0;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        wprintf(L"Введите фамилию ученика %d: ", i + 1);
        wscanf(L"%ls", students[i].surname);
    }

    wprintf(L"\nСписок учеников:\n");
    wprintf(L"Фамилия         | П1 | П2 | П3\n");
    wprintf(L"-----------------------------------\n");

    for (i = 0; i < N; i++) {
        wprintf(L"%-15ls | ", students[i].surname);

        for (j = 0; j < SUBJ; j++) {
            students[i].ball[j] = 2 + rand() % 4;
            wprintf(L"%2d | ", students[i].ball[j]);
        }
        wprintf(L"\n");
    }

    wprintf(L"-----------------------------------\n");

    wprintf(L"\nВведите номер предмета (1-3): ");
    wscanf(L"%d", &subject);
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

    // Освобождение памяти
    free(students);

    system("pause");
    return 0;
}
