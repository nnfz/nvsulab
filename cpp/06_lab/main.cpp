#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <windows.h>

using namespace std;

const int TABLE_SIZE = 766;

struct Rec {
    char used;
    char fam[21];
    char name[11];
    char otch[16];
    char dr[13];
};

string levelName(int k) {
    if (k == 0) return "main.dat";
    return "aux_" + to_string(k) + ".dat";
}

bool fileExists(int k) {
    ifstream f(levelName(k), ios::binary);
    return f.good();
}

void ensureFile(int k) {
    if (fileExists(k)) return;
    ofstream f(levelName(k), ios::binary);
    Rec empty;
    memset(&empty, 0, sizeof(Rec));
    for (int i = 0; i < TABLE_SIZE; i++) {
        f.write(reinterpret_cast<char*>(&empty), sizeof(Rec));
    }
}

int hashOf(const char* fam, const char* name, const char* otch) {
    int a = fam[0] ? (unsigned char)fam[0] : 0;
    int b = name[0] ? (unsigned char)name[0] : 0;
    int c = otch[0] ? (unsigned char)otch[0] : 0;
    return a + b + c;
}

void readSlot(fstream& f, int h, Rec& r) {
    f.seekg((streamoff)h * sizeof(Rec), ios::beg);
    f.read(reinterpret_cast<char*>(&r), sizeof(Rec));
}

void writeSlot(fstream& f, int h, const Rec& r) {
    f.seekp((streamoff)h * sizeof(Rec), ios::beg);
    f.write(reinterpret_cast<const char*>(&r), sizeof(Rec));
    f.flush();
}

void copyField(char* dest, const string& src, size_t maxLen) {
    memset(dest, 0, maxLen + 1);
    strncpy(dest, src.c_str(), maxLen);
}

bool sameKey(const Rec& r, const char* fam, const char* name, const char* otch) {
    return strcmp(r.fam, fam) == 0 && strcmp(r.name, name) == 0 && strcmp(r.otch, otch) == 0;
}

void printRec(const Rec& r) {
    cout << r.fam << " | " << r.name << " | " << r.otch << " | " << r.dr << endl;
}

string readLine(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

void addRecord() {
    Rec r;
    memset(&r, 0, sizeof(Rec));
    r.used = 1;
    copyField(r.fam, readLine("Фамилия (до 20 символов): "), 20);
    copyField(r.name, readLine("Имя (до 10 символов): "), 10);
    copyField(r.otch, readLine("Отчество (до 15 символов): "), 15);
    copyField(r.dr, readLine("Дата рождения (до 12 символов): "), 12);

    int h = hashOf(r.fam, r.name, r.otch);

    for (int k = 0;; k++) {
        ensureFile(k);
        fstream f(levelName(k), ios::in | ios::out | ios::binary);
        Rec cur;
        readSlot(f, h, cur);
        if (!cur.used) {
            writeSlot(f, h, r);
            cout << "Запись добавлена (файл " << levelName(k) << ", позиция " << h << ")" << endl;
            return;
        }
        if (sameKey(cur, r.fam, r.name, r.otch) && strcmp(cur.dr, r.dr) == 0) {
            cout << "Такая запись уже существует" << endl;
            return;
        }
    }
}

void searchRecord() {
    char fam[21], name[11], otch[16];
    memset(fam, 0, sizeof(fam));
    memset(name, 0, sizeof(name));
    memset(otch, 0, sizeof(otch));
    copyField(fam, readLine("Фамилия: "), 20);
    copyField(name, readLine("Имя: "), 10);
    copyField(otch, readLine("Отчество: "), 15);

    int h = hashOf(fam, name, otch);
    int found = 0;

    for (int k = 0; fileExists(k); k++) {
        fstream f(levelName(k), ios::in | ios::binary);
        Rec cur;
        readSlot(f, h, cur);
        if (!cur.used) break;
        if (sameKey(cur, fam, name, otch)) {
            cout << "[" << levelName(k) << ", позиция " << h << "] ";
            printRec(cur);
            found++;
        }
    }

    if (found == 0) cout << "Запись не найдена" << endl;
}

void viewAll() {
    int total = 0;
    for (int k = 0; fileExists(k); k++) {
        fstream f(levelName(k), ios::in | ios::binary);
        for (int h = 0; h < TABLE_SIZE; h++) {
            Rec cur;
            readSlot(f, h, cur);
            if (cur.used) {
                cout << "[" << levelName(k) << ", " << h << "] ";
                printRec(cur);
                total++;
            }
        }
    }
    if (total == 0) cout << "Записей нет" << endl;
    else cout << "Всего записей: " << total << endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ensureFile(0);
    while (true) {
        cout << endl;
        cout << "1 - Добавить запись" << endl;
        cout << "2 - Поиск записи" << endl;
        cout << "3 - Просмотр всех записей" << endl;
        cout << "0 - Выход" << endl;
        string choice = readLine("Выбор: ");
        int c = atoi(choice.c_str());
        if (c == 1) addRecord();
        else if (c == 2) searchRecord();
        else if (c == 3) viewAll();
        else if (c == 0) break;
        else cout << "Неверный пункт меню" << endl;
    }
    return 0;
}