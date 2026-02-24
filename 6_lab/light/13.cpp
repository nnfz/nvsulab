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

    wstring result = L"";
    bool brackets = false;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == L'(') {
            brackets = true;
        } else if (str[i] == L')') {
            brackets = false;
        } else if (!brackets) {
            result += str[i];
        }
    }

    wcout << L"Результат: " << result << endl;

    wcout << L"Нажмите Enter для выхода...";
    wcin.ignore();
    wcin.get();

    return 0;
}