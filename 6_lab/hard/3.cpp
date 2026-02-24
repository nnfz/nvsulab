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
    wstring word = L"";

    str += L' ';

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != L' ') {
            word += str[i];
        } else {
            if (word.length() > 0) {
                char firstChar = word[0];
                char lastChar = word[word.length() - 1];
                if (firstChar == lastChar) {
                    cnt++;
                }
            }
            word = L"";
        }
    }
    
    wcout << L"Количество слов, начинающихся и заканчивающихся одной и той же буквой: " << cnt << endl;

    wcout << L"Нажмите Enter для выхода...";
    wcin.ignore();
    wcin.get();

    return 0;
}