#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <windows.h>

using namespace std;

struct Person {
    char surname[50];
    char name[50];
};

int hashFunction(const char* surname) {
    if (strlen(surname) < 2) return 0;
    return (unsigned char)surname[0] * 256 + (unsigned char)surname[1];
}

string getMainFilename(int hash) {
    ostringstream oss;
    oss << "hash_" << hash << ".dat";
    return oss.str();
}

string getCollisionFilename(int hash) {
    ostringstream oss;
    oss << "collision_" << hash << ".dat";
    return oss.str();
}

void addPerson() {
    Person p;
    cout << "Введите фамилию: ";
    cin.ignore();
    cin.getline(p.surname, 50);
    cout << "Введите имя: ";
    cin.getline(p.name, 50);

    int hash = hashFunction(p.surname);
    string mainFile = getMainFilename(hash);

    ifstream checkFile(mainFile, ios::binary);
    Person existing;
    bool mainOccupied = false;

    if (checkFile.read(reinterpret_cast<char*>(&existing), sizeof(Person))) {
        mainOccupied = true;
    }
    checkFile.close();

    if (!mainOccupied) {
        ofstream outFile(mainFile, ios::binary);
        outFile.write(reinterpret_cast<char*>(&p), sizeof(Person));
        outFile.close();
        cout << "Запись добавлена в основной файл (хеш: " << hash << ")" << endl;
    } else {
        string collisionFile = getCollisionFilename(hash);
        ofstream outFile(collisionFile, ios::binary | ios::app);
        outFile.write(reinterpret_cast<char*>(&p), sizeof(Person));
        outFile.close();
        cout << "Коллизия! Запись добавлена в файл коллизий (хеш: " << hash << ")" << endl;
    }
}

void displayAll() {
    cout << "\n=== Все записи ===" << endl;
    int count = 0;

    for (int hash = 0; hash < 65536; hash++) {
        string mainFile = getMainFilename(hash);
        ifstream file(mainFile, ios::binary);

        if (file) {
            Person p;
            if (file.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
                count++;
                cout << count << ". " << p.surname << " " << p.name
                     << " (хеш: " << hash << ", основной)" << endl;
            }
            file.close();
        }

        string collisionFile = getCollisionFilename(hash);
        ifstream collFile(collisionFile, ios::binary);

        if (collFile) {
            Person p;
            while (collFile.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
                count++;
                cout << count << ". " << p.surname << " " << p.name
                     << " (хеш: " << hash << ", коллизия)" << endl;
            }
            collFile.close();
        }
    }

    if (count == 0) {
        cout << "Записей нет." << endl;
    } else {
        cout << "Всего записей: " << count << endl;
    }
}

void findPerson() {
    char surname[50];
    cout << "Введите фамилию для поиска: ";
    cin.ignore();
    cin.getline(surname, 50);

    int hash = hashFunction(surname);
    bool found = false;

    string mainFile = getMainFilename(hash);
    ifstream file(mainFile, ios::binary);
    Person p;

    if (file.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
        if (strcmp(p.surname, surname) == 0) {
            cout << "Найдено: " << p.surname << " " << p.name << endl;
            found = true;
        }
    }
    file.close();

    if (!found) {
        string collisionFile = getCollisionFilename(hash);
        ifstream collFile(collisionFile, ios::binary);

        while (collFile.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
            if (strcmp(p.surname, surname) == 0) {
                cout << "Найдено: " << p.surname << " " << p.name << endl;
                found = true;
                break;
            }
        }
        collFile.close();
    }

    if (!found) {
        cout << "Запись не найдена." << endl;
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int choice;

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить запись" << endl;
        cout << "2. Вывести все записи" << endl;
        cout << "3. Найти запись" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPerson();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                findPerson();
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