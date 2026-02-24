#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    double x, y, z;

    cout << "Введите три попарно различных числа (x y z): ";
    cin >> x >> y >> z;
    
    if (x + y + z < 1){
        if (x < y && x < z) {
            x = (y + z) / 2;
        } else if (y < x && y < z) {
            y = (x + z) / 2;
        } else {
            z = (x + y) / 2;
        }
    }else {
        if (x < y){
            x = (y + z) / 2;
        } else {
            y = (x + z) / 2;
        }
    }

    cout << "Результат: " << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}