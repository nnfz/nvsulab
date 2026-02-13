#include <iostream>

using namespace std;

int main() {
    int a;
    float result1, result2;
    cout << "Введите длину ребра куба: ";
    cin >> a;
    
    result1 = a * a * a;
    result2 = 4 * (a*a);
    
    cout << "Обьем куба: " << result1 << endl;
    cout << "Площпдль боковой поверхности куба: " << result2 << endl;
    return 0;
}
