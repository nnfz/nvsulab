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

    wstring word = L"";
    wstring shortWord = L"";
    int minLength = INT_MAX;

    str += L' ';

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != L' ') {
            word += str[i];
        } else {
            if (word.length() > 0) {
                if (word.length() <= minLength) {
                    minLength = word.length();
                    shortWord = word;
                }
            }
            word = L"";
        }
    }

    wcout << L"Самое короткое слово: " << shortWord << endl;

    wcout << L"Нажмите Enter для выхода...";
    wcin.ignore();
    wcin.get();

    return 0;
}