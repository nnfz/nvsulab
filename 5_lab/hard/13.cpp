#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    srand(time(0));
    int r, c;

    cout << "Введите количесвто строк: ";
    cin >> r;
    cout << "Введите количесвто столбцов: ";
    cin >> c;

    int arr[r][c];
    cout << "Массив:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = rand() % 100 - rand() % 100;
            cout << arr[i][j];
            if (j != c - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    int sums[c];

    for (int j = 0; j < c; j++) {
        sums[j] = 0;
        for (int i = 0; i < r; i++) {
            sums[j] += arr[i][j];
        }
    }

    int maxSum = sums[0];
    int minSum = sums[0];
    int maxCol = 0;
    int minCol = 0;

    for (int j = 1; j < c; j++) {
        if (sums[j] > maxSum) {
            maxSum = sums[j];
            maxCol = j;
        }
        if (sums[j] < minSum) {
            minSum = sums[j];
            minCol = j;
        }
    }

    cout << "Максимальная сумма: " << maxSum << endl;
    cout << "Минимальная сумма: " << minSum << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}