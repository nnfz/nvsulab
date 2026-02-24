#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
using namespace std;

double min(double x, double y) {
    return (x < y) ? x : y;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    double a, b, c;

    cout << "Введите три числа (a b c): ";
    cin >> a >> b >> c;

    double min1 = min(c, a - b);
    double min2 = min(b, a + 2 * c);
    double min3 = min(a + c, 2 * b);

    double result = (min1 - min2) / (100 - min3);

    cout << fixed << setprecision(6) << "Результат: " << result << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}