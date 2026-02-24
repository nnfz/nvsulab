#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int a, n;
    
    cout << "Введите целое число a: ";
    cin >> a;
    cout << "Введите натуральное число n: ";
    cin >> n;

    long long result = 1;

    for (int i = 0; i < n; i++) {
        result *= a;
    }

    cout << "Результат: " << result << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}