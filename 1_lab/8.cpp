#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001); 
    int xa, ya, xb, yb;
    float result;
    
    cout << "Введите координаты ПРЕВОЙ точки (a b): ";
    cin >> xa >> ya;
    cout << "Введите координаты ВТОРОЙ точки (a b): "; 
    cin >> xb >> yb;
    
    result = sqrt(((xa - xb)*(xa - xb)) + ((ya - yb)*(ya - yb)));
    cout << "Ответ: " << result << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}
