#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>

using namespace std;

const string FILENAME = "Num.dat";
const string TEMP_FILENAME = "Temp.dat";

bool writeNumber(int num, int position) {
    ifstream in(FILENAME, ios::binary);
    ofstream out(TEMP_FILENAME, ios::binary | ios::trunc);
    if (!out) {
        return false;
    }

    int current;
    int index = 0;

    while (in.read(reinterpret_cast<char*>(&current), sizeof(int))) {
        if (index == position) {
            out.write(reinterpret_cast<const char*>(&num), sizeof(int));
        } else {
            out.write(reinterpret_cast<const char*>(&current), sizeof(int));
        }
        index++;
    }

    if (index <= position) {
        int zero = 0;
        while (index < position) {
            out.write(reinterpret_cast<const char*>(&zero), sizeof(int));
            index++;
        }
        out.write(reinterpret_cast<const char*>(&num), sizeof(int));
    }

    in.close();
    out.close();

    remove(FILENAME.c_str());
    return rename(TEMP_FILENAME.c_str(), FILENAME.c_str()) == 0;
}

void writeToFile() {
    int num;
    cout << "Введите целые числа больше 1000 (0 для завершения):" << endl;

    while (true) {
        cout << "Число: ";
        cin >> num;

        if (num == 0) break;

        if (num <= 1000) {
            cout << "Число должно быть > 1000!" << endl;
            continue;
        }

        int position = num - 1000;

        if (writeNumber(num, position)) {
            cout << "Число записано на позицию " << position << endl;
        } else {
            cout << "Ошибка записи в файл!" << endl;
        }
    }
}

void displayFile() {
    ifstream file(FILENAME, ios::binary);
    if (!file) {
        cout << "Файл пуст или не существует!" << endl;
        return;
    }

    int num;
    int position = 0;
    cout << "\n=== Содержимое файла ===" << endl;

    while (file.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        cout << "Позиция " << position << ": " << num << endl;
        position++;
    }
    file.close();
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int choice;

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Запись в файл" << endl;
        cout << "2. Вывод записей на экран" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                displayFile();
                break;
            case 0:
                cout << "Выход..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}
