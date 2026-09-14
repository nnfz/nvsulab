#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

struct Person {
    char surname[50];
    char birthDate[20];
    char address[100];
    char university[100];
};

void generateRandomString(char* str, int length) {
    for (int i = 0; i < length - 1; i++) {
        str[i] = 'A' + rand() % 26;
    }
    str[length - 1] = '\0';
}

void generateRandomDate(char* date) {
    int day = 1 + rand() % 28;
    int month = 1 + rand() % 12;
    int year = 1950 + rand() % 70;
    sprintf(date, "%02d.%02d.%d", day, month, year);
}

void generatePerson(Person& p) {
    generateRandomString(p.surname, 8);
    generateRandomDate(p.birthDate);
    generateRandomString(p.address, 15);
    generateRandomString(p.university, 10);
}

void sortBySurname(Person arr[], int size) {
    for (int i = 1; i < size; i++) {
        Person key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j].surname, key.surname) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int sequentialSearch(Person arr[], int size, const char* surname, int& steps) {
    steps = 0;
    for (int i = 0; i < size; i++) {
        steps++;
        if (strcmp(arr[i].surname, surname) == 0) {
            return i;
        }
    }
    return -1;
}

int binarySearch(Person arr[], int size, const char* surname, int& steps) {
    steps = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid].surname, surname);

        if (cmp == 0) {
            return mid;
        }
        if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void displayPerson(const Person& p) {
    cout << "Фамилия: " << p.surname << endl;
    cout << "Дата рождения: " << p.birthDate << endl;
    cout << "Адрес: " << p.address << endl;
    cout << "ВУЗ: " << p.university << endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    srand(time(0));

    int n;
    cout << "Введите количество записей: ";
    cin >> n;

    Person* people = new Person[n];

    for (int i = 0; i < n; i++) {
        generatePerson(people[i]);
    }

    cout << "Сгенерировано " << n << " записей." << endl;
    cout << "\n5 случайных записей:" << endl;
    for (int i = 0; i < min(5, n); i++) {
        int randomIndex = rand() % n;
        cout << "\n--- Запись #" << randomIndex << " ---" << endl;
        displayPerson(people[randomIndex]);
    }

    sortBySurname(people, n);
    cout << "\nМассив отсортирован по фамилиям." << endl;

    char searchSurname[50];
    cout << "\nВведите фамилию для поиска (или одну из сгенерированных): ";
    cin >> searchSurname;

    int stepsSeq, stepsBin;

    int resultSeq = sequentialSearch(people, n, searchSurname, stepsSeq);
    int resultBin = binarySearch(people, n, searchSurname, stepsBin);

    cout << "\n=== Последовательный поиск ===" << endl;
    if (resultSeq != -1) {
        cout << "Запись найдена на позиции: " << resultSeq << endl;
        displayPerson(people[resultSeq]);
    } else {
        cout << "Запись не найдена" << endl;
    }
    cout << "Количество шагов: " << stepsSeq << endl;

    cout << "\n=== Бинарный поиск ===" << endl;
    if (resultBin != -1) {
        cout << "Запись найдена на позиции: " << resultBin << endl;
        displayPerson(people[resultBin]);
    } else {
        cout << "Запись не найдена" << endl;
    }
    cout << "Количество шагов: " << stepsBin << endl;

    cout << "\n=== Сравнение ===" << endl;
    cout << "Разница в количестве шагов: " << abs(stepsSeq - stepsBin) << endl;

    delete[] people;
    return 0;
}