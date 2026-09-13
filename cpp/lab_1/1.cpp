#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <windows.h>

using namespace std;

struct Student {
    char fio[100];
    char birthDate[20];
    unsigned char course;
    unsigned short group;
};

void addStudent(const string& filename) {
    Student student;

    cout << "Введите ФИО: ";
    cin.ignore();
    cin.getline(student.fio, 100);

    cout << "Введите дату рождения (ДД.ММ.ГГГГ): ";
    cin.getline(student.birthDate, 20);

    int course;
    unsigned short group;
    cout << "Введите курс (1-6): ";
    cin >> course;
    student.course = static_cast<unsigned char>(course);

    cout << "Введите группу: ";
    cin >> group;
    student.group = group;

    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    file.close();

    cout << "Студент успешно добавлен!" << endl;
}

void deleteStudent(const string& filename) {
    string fioToDelete;
    cout << "Введите ФИО студента для удаления: ";
    cin.ignore();
    getline(cin, fioToDelete);

    ifstream fileIn(filename, ios::binary);
    if (!fileIn) {
        cout << "Файл не найден!" << endl;
        return;
    }

    vector<Student> students;
    Student student;
    bool found = false;

    while (fileIn.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (strcmp(student.fio, fioToDelete.c_str()) != 0) {
            students.push_back(student);
        } else {
            found = true;
        }
    }
    fileIn.close();

    if (!found) {
        cout << "Студент с таким ФИО не найден!" << endl;
        return;
    }

    ofstream fileOut(filename, ios::binary | ios::trunc);
    for (const auto& s : students) {
        fileOut.write(reinterpret_cast<const char*>(&s), sizeof(Student));
    }
    fileOut.close();

    cout << "Студент успешно удален!" << endl;
}

void checkStudent(const string& filename) {
    string fioToCheck;
    cout << "Введите ФИО студента для проверки: ";
    cin.ignore();
    getline(cin, fioToCheck);

    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Файл не найден!" << endl;
        return;
    }

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (strcmp(student.fio, fioToCheck.c_str()) == 0) {
            found = true;
            cout << "\nСтудент найден:" << endl;
            cout << "ФИО: " << student.fio << endl;
            cout << "Дата рождения: " << student.birthDate << endl;
            cout << "Курс: " << (int)student.course << endl;
            cout << "Группа: " << student.group << endl;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Студент с таким ФИО не найден!" << endl;
    }
}

void displayAllStudents(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Файл не найден или пуст!" << endl;
        return;
    }

    Student student;
    int count = 0;

    cout << "\n=== Список всех студентов ===" << endl;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        count++;
        cout << "\nСтудент #" << count << ":" << endl;
        cout << "ФИО: " << student.fio << endl;
        cout << "Дата рождения: " << student.birthDate << endl;
        cout << "Курс: " << (int)student.course << endl;
        cout << "Группа: " << student.group << endl;
        cout << "------------------------" << endl;
    }
    file.close();

    if (count == 0) {
        cout << "Файл пуст!" << endl;
    } else {
        cout << "Всего студентов: " << count << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "students.dat";
    int choice;

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Удалить студента" << endl;
        cout << "3. Проверить принадлежность студента" << endl;
        cout << "4. Вывести всех студентов" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                deleteStudent(filename);
                break;
            case 3:
                checkStudent(filename);
                break;
            case 4:
                displayAllStudents(filename);
                break;
            case 0:
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}