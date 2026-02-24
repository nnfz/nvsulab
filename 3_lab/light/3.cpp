#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int m, n;

    cout << "Введите границы интервала (m n): ";
    cin >> m >> n;

    long long sum = 0;

    for (int i = m; i <= n; i++) {
        if (i % 2 != 0) {
            sum += i * i;
        }
    }

    cout << "Сумма квадратов нечетных чисел: " << sum << endl;
    
    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}