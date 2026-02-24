#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

bool isEven(int num) {
    return num % 2 == 0;
}

bool hasEven(int num){
    while (num > 0) {
        int digit = num % 10;
        if (isEven(digit)) {
            return true;
        }
        num /= 10;
    }
    return false;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    long long sum = 0;
    int cnt = 0;

    for (int num = 100; num <= 999; num++) {
        if (!hasEven(num)) {
            sum += num;
            cnt++;
        }
    }
    
    cout << "Сумма: " << sum << endl;
    cout << "Количество: " << cnt << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}