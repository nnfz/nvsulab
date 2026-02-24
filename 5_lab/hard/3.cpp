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
            arr[i][j] = rand() % 10;
            cout << arr[i][j];
            if (j != c - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    
    int evenCnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] % 2 == 0) {
                evenCnt++;
            }
        }
    }

    cout << "Количество четных элементов: " << evenCnt << endl;

    if (evenCnt == 0){
        cout << "Четных элементов нет." << endl;
        return 0;
    }

    int arr2[evenCnt];
    int pos = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] % 2 == 0) {
                arr2[pos] = arr[i][j];
                pos++;
            }
        }
    }

    cout << "Массив четных элементов: " << endl << "[";
    for (int i = 0; i < evenCnt; i++) {
        cout << arr2[i];
        if (i != evenCnt - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}