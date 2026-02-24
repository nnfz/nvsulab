#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    srand(time(0));
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    int arr[n];
    
    cout << "Массив: " << endl << "[";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
        if (i == n - 1) {
            cout << arr[i];
        } else {
        cout << arr[i] << ", ";
        }
    }
    cout << "]" << endl;

    long result = 1;

    for (int i = 1; i < n; i += 2) {
        result *= arr[i];
    }

    cout << "Произведение нечетных элементов: " << result << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}