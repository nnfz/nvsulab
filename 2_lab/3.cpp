#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    double a, b, c;

    cout << "Введите три числа: ";
    cin >> a >> b >> c;

    if (a > b && b > c) {
        a *= 3;
        b *= 3;
        c *= 3;
        cout << "Результат (утроенные): " << endl;
    } else {
        a = fabs(a);
        b = fabs(b);
        c = fabs(c);
        cout << "Результат (абсолютные): " << endl;
    }

    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}