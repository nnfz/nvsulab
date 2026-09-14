#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct University {
    char name[100];
    University* next;
    University* prev;
};

class DoubleLinkedList {
private:
    University* head;
    University* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoubleLinkedList() {
        while (head != nullptr) {
            University* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addNode(const char* name) {
        University* newNode = new University;
        strcpy(newNode->name, name);
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ВУЗ добавлен." << endl;
    }

    void deleteNode(const char* name) {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        University* current = head;
        while (current != nullptr && strcmp(current->name, name) != 0) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "ВУЗ не найден." << endl;
            return;
        }

        if (current == head) {
            head = current->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (current == tail) {
            tail = current->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        cout << "ВУЗ удален." << endl;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        University* current = head;
        int count = 1;
        cout << "\n=== Список ВУЗов (слева направо) ===" << endl;
        while (current != nullptr) {
            cout << count++ << ". " << current->name << endl;
            current = current->next;
        }
    }

    void displayBackward() {
        if (tail == nullptr) {
            cout << "Список пуст." << endl;
            return;
        }

        University* current = tail;
        int count = 1;
        cout << "\n=== Список ВУЗов (справа налево) ===" << endl;
        while (current != nullptr) {
            cout << count++ << ". " << current->name << endl;
            current = current->prev;
        }
    }

    bool contains(const char* name) {
        University* current = head;
        while (current != nullptr) {
            if (strcmp(current->name, name) == 0) {
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

    DoubleLinkedList list;
    int choice;
    char name[100];

    list.addNode("Югорский государственный университет");
    list.addNode("Сургутский государственный университет");
    list.addNode("Нижневартовский государственный университет");

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить ВУЗ" << endl;
        cout << "2. Удалить ВУЗ" << endl;
        cout << "3. Просмотр списка (слева направо)" << endl;
        cout << "4. Просмотр списка (справа налево)" << endl;
        cout << "5. Проверить принадлежность" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Введите название ВУЗа: ";
                cin.getline(name, 100);
                list.addNode(name);
                break;
            case 2:
                cout << "Введите название ВУЗа для удаления: ";
                cin.getline(name, 100);
                list.deleteNode(name);
                break;
            case 3:
                list.displayForward();
                break;
            case 4:
                list.displayBackward();
                break;
            case 5:
                cout << "Введите название ВУЗа для проверки: ";
                cin.getline(name, 100);
                if (list.contains(name)) {
                    cout << "ВУЗ найден в списке." << endl;
                } else {
                    cout << "ВУЗ не найден в списке." << endl;
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