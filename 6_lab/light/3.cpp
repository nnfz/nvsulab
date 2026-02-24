#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
using namespace std;

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    wstring str;

    wcout << L"Введите строку: ";
    getline(wcin, str);

    int cnt = 0;
    int maxCnt = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == L'а' || str[i] == L'a' || str[i] == L'А' || str[i] == L'A') {
            cnt++;
            if (cnt > maxCnt) {
                maxCnt = cnt;
            }
        } else {
            cnt = 0;
        }
    }
    
    wcout << L"Максимальное количество подряд идущих букв 'а': " << maxCnt << endl;

    wcout << L"Нажмите Enter для выхода...";
    wcin.ignore();
    wcin.get();

    return 0;
}