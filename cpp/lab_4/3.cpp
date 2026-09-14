#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct Node {
    char city[100];
    Node* next;
    Node* prev;
};

class CityQueue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    CityQueue() : front(nullptr), rear(nullptr), count(0) {}

    ~CityQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(const char* city) {
        Node* newNode = new Node;
        strcpy(newNode->city, city);
        newNode->next = nullptr;
        newNode->prev = rear;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        cout << "Город добавлен в очередь." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Очередь пуста!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Удален город: " << front->city << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }

        delete temp;
        count--;
    }

    int size() {
        return count;
    }

    void display() {
        if (front == nullptr) {
            cout << "Очередь пуста!" << endl;
            return;
        }

        Node* current = front;
        int num = 1;
        cout << "\n=== Города в очереди (от начала к концу) ===" << endl;
        while (current != nullptr) {
            cout << num++ << ". " << current->city << endl;
            current = current->next;
        }
    }

    void displayReverse() {
        if (rear == nullptr) {
            cout << "Очередь пуста!" << endl;
            return;
        }

        Node* current = rear;
        int num = 1;
        cout << "\n=== Города в очереди (от конца к началу) ===" << endl;
        while (current != nullptr) {
            cout << num++ << ". " << current->city << endl;
            current = current->prev;
        }
    }

    bool contains(const char* city) {
        Node* current = front;
        while (current != nullptr) {
            if (strcmp(current->city, city) == 0) {
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

    CityQueue queue;
    int choice;
    char city[100];

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Добавить город" << endl;
        cout << "2. Удалить город" << endl;
        cout << "3. Мощность множества" << endl;
        cout << "4. Просмотр всех элементов (начало -> конец)" << endl;
        cout << "5. Просмотр всех элементов (конец -> начало)" << endl;
        cout << "6. Проверить принадлежность" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Введите название города: ";
                cin.getline(city, 100);
                queue.enqueue(city);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << "Мощность множества: " << queue.size() << endl;
                break;
            case 4:
                queue.display();
                break;
            case 5:
                queue.displayReverse();
                break;
            case 6:
                cout << "Введите название города для проверки: ";
                cin.getline(city, 100);
                if (queue.contains(city)) {
                    cout << "Город найден в очереди." << endl;
                } else {
                    cout << "Город не найден в очереди." << endl;
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