#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int gip, cat;
    float res1, res2;
    
    cout << "Введите катет: ";
    cin >> cat;
    cout << "Введите гипотенузу: ";
    cin >> gip;
    
    res1 = sqrt((gip*gip) - (cat*cat));
    res2 = (res1 + cat - gip) / 2;
    
    cout << "Второй катет: " << res1 << endl;
    cout << "Радиус пупупупуп: " << res2 << endl;
    return 0;
}
