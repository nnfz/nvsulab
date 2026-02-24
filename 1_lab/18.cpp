#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001); 
    int gip, cat;
    float res1, res2;
    
    cout << "Введите катет: ";
    cin >> cat;
    cout << "Введите гипотенузу: ";
    cin >> gip;
    
    res1 = sqrt((gip*gip) - (cat*cat));
    res2 = (res1 + cat - gip) / 2;
    
    cout << "Второй катет: " << res1 << endl;
    cout << "Радиус: " << res2 << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}
