#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int edge1, edge2, ang; 
    float result, anginrad;
    
    cout << "Введите первую сторону: ";
    cin >> edge1;
    cout << "Введите вторую сторону: ";
    cin >> edge2;
    cout << "Введите угол между сторонами: ";
    cin >> ang;
    
    anginrad = ang * M_PI / 180;
    
    result = sqrt((edge1*edge1) + (edge2*edge2) - 2 * edge1 * edge2 * cos(anginrad));
    
    cout << "Ответ: " << result;
    return 0;
}
