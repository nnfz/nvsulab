#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int n;

    cout << "Введите число n: ";
    cin >> n;

    int lastDigit = n % 10;
    int lastTwoDigits = (n / 10) % 10;

    int sum = lastDigit + lastTwoDigits;

    cout << "Сумма последних двух цифр: " << sum << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}