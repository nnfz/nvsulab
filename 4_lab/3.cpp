#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
using namespace std;

double f(double a, double b, double c) {
    return (a + 2 * b + log(c)) / (a + c);
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    double s, t;
    
    cout << "Введите два числа (s t): ";
    cin >> s >> t;

    double result1 = f(t, s + t, fabs(-7));
    double result2 = f(3, s - 10, 5*s);

    double result = result1 + result2;

    cout << fixed << setprecision(10) << "Результат: " << result << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}