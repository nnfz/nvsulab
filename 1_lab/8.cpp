#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int xa, ya, xb, yb;
    float result;
    cout << "Введите координаты первой точки (a b): ";
    cin >> xa >> ya;
    cout << "Введите координаты второй точки (a b): "; 
    cin >> xb >> yb;
    
    result = sqrt(((xa - xb)*(xa - xb)) + ((ya - yb)*(ya - yb)));
    cout << "Ответ: " << result;
    return 0;
}
