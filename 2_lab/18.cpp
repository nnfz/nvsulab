#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int a, b, r, s;

    cout << "Введите неотрицательные число a: ";
    cin >> a;
    cout << "Введите положительное число b: ";
    cin >> b;
    cout << "Введите числа (r s): ";
    cin >> r >> s;

    int ost = a % b;
    cout << "Остаток: " << ost << endl;

    if (ost == r) {
        cout << "Остаток равен r." << endl;
    } else if (ost == s) {
        cout << "Остаток равен s." << endl;
    } else {
        cout << "Остаток не равен ни r, ни s." << endl;
    }

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}