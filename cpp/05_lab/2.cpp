#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <windows.h>

using namespace std;

struct Student {
    char fio[21];
    int course;
    int group;
};

int hashFunction(const char* fio) {
    if (strlen(fio) < 3) return 0;
    return (unsigned char)fio[0] + (unsigned char)fio[1] + (unsigned char)fio[2];
}

string getCollisionFilename(int hash) {
    ostringstream oss;
    oss << "v" << hash << ".dat";
    return oss.str();
}

int countRecordsWithHash(const string& mainFile, int hash) {
    ifstream file(mainFile, ios::binary);
    if (!file) return 0;

    int count = 0;
    Student s;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (hashFunction(s.fio) == hash) {
            count++;
        }
    }
    file.close();
    return count;
}

void addStudent() {
    Student s;
    cout << "Введите ФИО (до 20 символов, заглавные кириллица): ";
    cin.ignore();
    cin.getline(s.fio, 21);
    cout << "Введите курс: ";
    cin >> s.course;
    cout << "Введите группу: ";
    cin >> s.group;

    int hash = hashFunction(s.fio);
    cout << "Вычислен хеш: " << hash << endl;

    string mainFile = "student.dat";
    int recordsWithHash = countRecordsWithHash(mainFile, hash);

    if (recordsWithHash == 0) {
        ofstream file(mainFile, ios::binary | ios::app);
        file.write(reinterpret_cast<char*>(&s), sizeof(Student));
        file.close();
        cout << "Адрес свободен. Запись добавлена в главный файл student.dat" << endl;
    } else {
        string collisionFile = getCollisionFilename(hash);
        ofstream file(collisionFile, ios::binary | ios::app);
        file.write(reinterpret_cast<char*>(&s), sizeof(Student));
        file.close();
        cout << "Адрес занят! Коллизия. Запись добавлена в файл " << collisionFile << endl;
    }
}

void displayAll() {
    cout << "\n=== Все записи ===" << endl;
    int totalCount = 0;

    cout << "\n--- Главный файл student.dat ---" << endl;
    ifstream mainFile("student.dat", ios::binary);
    if (mainFile) {
        Student s;
        int count = 0;
        while (mainFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            count++;
            totalCount++;
            cout << count << ". " << s.fio << ", курс " << s.course
                 << ", группа " << s.group << " (хеш: " << hashFunction(s.fio) << ")" << endl;
        }
        mainFile.close();
        if (count == 0) {
            cout << "(пусто)" << endl;
        }
    } else {
        cout << "(файл не существует)" << endl;
    }

    cout << "\n--- Вспомогательные файлы (коллизии) ---" << endl;
    bool foundCollisions = false;
    for (int hash = 0; hash < 1000; hash++) {
        string collisionFile = getCollisionFilename(hash);
        ifstream file(collisionFile, ios::binary);

        if (file) {
            Student s;
            int count = 0;
            cout << "\nФайл " << collisionFile << ":" << endl;
            while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
                count++;
                totalCount++;
                cout << "  " << count << ". " << s.fio << ", курс " << s.course
                     << ", группа " << s.group << endl;
            }
            file.close();
            foundCollisions = true;
        }
    }

    if (!foundCollisions) {
        cout << "(нет вспомогательных файлов)" << endl;
    }

    cout << "\nВсего записей: " << totalCount << endl;
}

void findStudent() {
    char fio[21];
    cout << "Введите ФИО для поиска: ";
    cin.ignore();
    cin.getline(fio, 21);

    int hash = hashFunction(fio);
    cout << "Ищем по хешу: " << hash << endl;
    bool found = false;

    ifstream mainFile("student.dat", ios::binary);
    Student s;

    while (mainFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (strcmp(s.fio, fio) == 0) {
            cout << "\nНайдено в student.dat:" << endl;
            cout << "ФИО: " << s.fio << endl;
            cout << "Курс: " << s.course << endl;
            cout << "Группа: " << s.group << endl;
            found = true;
            break;
        }
    }
    mainFile.close();

    if (!found) {
        string collisionFile = getCollisionFilename(hash);
        ifstream file(collisionFile, ios::binary);

        while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            if (strcmp(s.fio, fio) == 0) {
                cout << "\nНайдено в " << collisionFile << ":" << endl;
                cout << "ФИО: " << s.fio << endl;
                cout << "Курс: " << s.course << endl;
                cout << "Группа: " << s.group << endl;
                found = true;
                break;
            }
        }
        file.close();
    }

    if (!found) {
        cout << "Студент не найден." << endl;
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int choice;

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Вывести всех студентов" << endl;
        cout << "3. Найти студента" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                findStudent();
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