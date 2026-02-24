#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001); 
    int a;
    float result1, result2;
    
    cout << "Введите длину ребра куба: ";
    cin >> a;
    
    result1 = a * a * a;
    result2 = 4 * (a*a);
    
    cout << "Обьем куба: " << result1 << endl;
    cout << "Площпдль боковой поверхности куба: " << result2 << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}
