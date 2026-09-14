#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <windows.h>

using namespace std;

int hashFunction(const char* fio) {
    if (strlen(fio) < 3) return 0;
    return (unsigned char)fio[0] + (unsigned char)fio[1] + (unsigned char)fio[2];
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    unsigned char minChar = 'А';
    unsigned char maxChar = 'Я';

    int minHash = minChar * 3;
    int maxHash = maxChar * 3;
    int rangeSize = maxHash - minHash + 1;
    int alphabetSize = maxChar - minChar + 1;
    long long totalCombinations = (long long)alphabetSize * alphabetSize * alphabetSize;

    map<int, int> hashCount;
    set<int> uniqueHashes;

    for (unsigned char c1 = minChar; c1 <= maxChar; c1++) {
        for (unsigned char c2 = minChar; c2 <= maxChar; c2++) {
            for (unsigned char c3 = minChar; c3 <= maxChar; c3++) {
                int hash = c1 + c2 + c3;
                hashCount[hash]++;
                uniqueHashes.insert(hash);
            }
        }
    }

    int maxCollisions = 0;
    int maxHashValue = 0;

    for (auto& p : hashCount) {
        if (p.second > maxCollisions) {
            maxCollisions = p.second;
            maxHashValue = p.first;
        }
    }

    cout << "Word('А') = " << (int)minChar << endl;
    cout << "Word('Я') = " << (int)maxChar << endl;
    cout << "Размер алфавита: " << alphabetSize << endl;
    cout << "Всего комбинаций: " << totalCombinations << endl;
    cout << "Уникальных хешей: " << uniqueHashes.size() << endl;
    cout << "Средний коэффициент коллизий: " << (float)totalCombinations / uniqueHashes.size() << endl;
    cout << "Максимум коллизий на один хеш: " << maxCollisions << endl;

    cout << "\nПримеры:" << endl;
    cout << "АБВ -> " << hashFunction("АБВ") << endl;
    cout << "АВБ -> " << hashFunction("АВБ") << endl;
    cout << "БАВ -> " << hashFunction("БАВ") << endl;

    return 0;
}