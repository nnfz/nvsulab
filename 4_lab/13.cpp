#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

bool isFullSquare(int num) {
    if (num < 0) {
        return false;
    }
    int root = (int)sqrt(num);
    return root * root == num;
}

bool isSumSquares(int n, int &a, int &b) {
    for (int i = 1; i * i < n; i++) {
        int ost = n - i * i;

        if (isFullSquare(ost)) {
            int j = (int)sqrt(ost);
            if (j >= 1) {
                a = i;
                b = j;
                return true;
            }
        }
    }
    return false;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int n;

    cout << "Введите число n: ";
    cin >> n;

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        int a, b;
        if (isSumSquares(i, a, b)) {
            cnt++;
        }
    }

    cout << "Всего: " << cnt << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}