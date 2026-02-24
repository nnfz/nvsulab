#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001); 
    double a, b, c, x, y;

    cout << "Введите размер кирпича(a b c): ";
    cin >> a >> b >> c;
    cout << "Введите размер отверстия (x y): ";
    cin >> x >> y;

    if ((a <= x && b <= y) || (a <= y && b <= x) ||
        (a <= x && c <= y) || (a <= y && c <= x) ||
        (b <= x && c <= y) || (b <= y && c <= x)) {
        cout << "Кирпич пройдет в отверстие." << endl;
    } else {
        cout << "Кирпич НЕ пролезет в отверстие." << endl;
    }
    
    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}