#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct Student {
    char surname[50];
    int course;
    int group;
    Student* next;
};

class SingleLinkedList {
private:
    Student* head;

public:
    SingleLinkedList() : head(nullptr) {}

    ~SingleLinkedList() {
        while (head != nullptr) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addNode(const char* surname, int course, int group) {
        Student* newNode = new Student;
        strcpy(newNode->surname, surname);
        newNode->course = course;
        newNode->group = group;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Student* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Студент добавлен." << endl;
    }

    void deleteNode(const char* surname) {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        if (strcmp(head->surname, surname) == 0) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Студент удален." << endl;
            return;
        }

        Student* current = head;
        while (current->next != nullptr && strcmp(current->next->surname, surname) != 0) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Студент не найден." << endl;
        } else {
            Student* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Студент удален." << endl;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        Student* current = head;
        int count = 1;
        cout << "\n=== Список студентов ===" << endl;
        while (current != nullptr) {
            cout << count++ << ". Фамилия: " << current->surname
                 << ", Курс: " << current->course
                 << ", Группа: " << current->group << endl;
            current = current->next;
        }
    }

    bool contains(const char* surname) {
        Student* current = head;
        while (current != nullptr) {
            if (strcmp(current->surname, surname) == 0) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    SingleLinkedList list;
    int choice;
    char surname[50];
    int course, group;

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Удалить студента" << endl;
        cout << "3. Просмотр списка" << endl;
        cout << "4. Проверить принадлежность" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Введите фамилию: ";
                cin.getline(surname, 50);
                cout << "Введите курс: ";
                cin >> course;
                cout << "Введите группу: ";
                cin >> group;
                cin.ignore();
                list.addNode(surname, course, group);
                break;
            case 2:
                cout << "Введите фамилию для удаления: ";
                cin.getline(surname, 50);
                list.deleteNode(surname);
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout << "Введите фамилию для проверки: ";
                cin.getline(surname, 50);
                if (list.contains(surname)) {
                    cout << "Студент найден в списке." << endl;
                } else {
                    cout << "Студент не найден в списке." << endl;
                }
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