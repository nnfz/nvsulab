#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

const string FILENAME = "Num.dat";
const string TEMP_FILENAME = "Temp.dat";

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

        fstream file(FILENAME, ios::in | ios::out | ios::binary);
        if (!file) {
            file.open(FILENAME, ios::out | ios::binary);
        }

        file.seekp(position * sizeof(int), ios::beg);
        file.write(reinterpret_cast<char*>(&num), sizeof(int));
        file.close();

        cout << "Число записано на позицию " << position << endl;
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