#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const int ARRAY_SIZE = 1000;  // Переименовано, чтобы избежать конфликта с SIZE из windows.h

void generateSortedArray(double arr[], int size) {
    srand(time(0));
    arr[0] = rand() % 100;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + (rand() % 10) + 1;
    }
}

int sequentialSearch(double arr[], int size, double key, int& steps) {
    steps = 0;
    for (int i = 0; i < size; i++) {
        steps++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(double arr[], int size, double key, int& steps) {
    steps = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double B[ARRAY_SIZE];
    generateSortedArray(B, ARRAY_SIZE);

    cout << "Сгенерирован отсортированный массив из " << ARRAY_SIZE << " элементов." << endl;
    cout << "Первые 10 элементов: ";
    for (int i = 0; i < 10; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    double key;
    cout << "\nВведите число для поиска: ";
    cin >> key;

    int stepsSeq, stepsBin;

    int resultSeq = sequentialSearch(B, ARRAY_SIZE, key, stepsSeq);
    int resultBin = binarySearch(B, ARRAY_SIZE, key, stepsBin);

    cout << "\n=== Последовательный поиск ===" << endl;
    if (resultSeq != -1) {
        cout << "Элемент найден на позиции: " << resultSeq << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    cout << "Количество шагов: " << stepsSeq << endl;

    cout << "\n=== Бинарный поиск ===" << endl;
    if (resultBin != -1) {
        cout << "Элемент найден на позиции: " << resultBin << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    cout << "Количество шагов: " << stepsBin << endl;

    cout << "\n=== Сравнение ===" << endl;
    cout << "Разница в количестве шагов: " << (stepsSeq - stepsBin) << endl;
    cout << "Бинарный поиск эффективнее в " << (double)stepsSeq / stepsBin << " раз" << endl;

    return 0;
}