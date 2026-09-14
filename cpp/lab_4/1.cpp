#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

const string FILENAME = "Num.dat";
const string TEMP_FILENAME = "Temp.dat";

void writeToFile() {
    int num;
    cout << "˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜ 1000 (0 ˜˜˜ ˜˜˜˜˜˜˜˜˜˜):" << endl;

    while (true) {
        cout << "˜˜˜˜˜: ";
        cin >> num;

        if (num == 0) break;

        if (num <= 1000) {
            cout << "˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜ 1000!" << endl;
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

        cout << "˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜ " << position << endl;
    }
}

void displayFile() {
    ifstream file(FILENAME, ios::binary);
    if (!file) {
        cout << "˜˜˜˜ ˜˜˜˜ ˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜˜˜!" << endl;
        return;
    }

    int num;
    int position = 0;
    cout << "\n=== ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ===" << endl;

    while (file.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        cout << "˜˜˜˜˜˜˜ " << position << ": " << num << endl;

        position++;
    }
    file.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        cout << "\n=== ˜˜˜˜ ===" << endl;
        cout << "1. ˜˜˜˜˜˜ ˜ ˜˜˜˜" << endl;
        cout << "2. ˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜" << endl;
        cout << "0. ˜˜˜˜˜" << endl;
        cout << "˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                displayFile();
                break;
            case 0:
                cout << "˜˜˜˜˜..." << endl;
                break;
            default:
                cout << "˜˜˜˜˜˜˜˜ ˜˜˜˜˜!" << endl;
        }
    } while (choice != 0);

    return 0;
}