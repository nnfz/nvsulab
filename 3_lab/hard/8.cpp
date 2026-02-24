#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    double sum = 0;

    for (int i = 1; i <= 50; i++) {
        sum += 1.0 / (i * i * i);
    }

    cout << fixed << setprecision(10) << "Сумма: " << sum << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}