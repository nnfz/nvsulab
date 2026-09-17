#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct Node {
    char data[100];
    Node* next;
};

class StringStack {
private:
    Node* top;

public:
    StringStack() : top(nullptr) {}

    ~StringStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const char* str) {
        Node* newNode = new Node;
        strcpy(newNode->data, str);
        newNode->next = top;
        top = newNode;
        cout << "Строка добавлена в стек." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Стек пуст!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Удалена строка: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Стек пуст!" << endl;
            return;
        }
        cout << "Вершина стека: " << top->data << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Стек пуст!" << endl;
            return;
        }

        Node* current = top;
        int count = 1;
        cout << "\n=== Содержимое стека (сверху вниз) ===" << endl;
        while (current != nullptr) {
            cout << count++ << ". " << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    StringStack stack;
    int choice;
    char str[100];

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Push (добавить строку)" << endl;
        cout << "2. Pop (удалить строку)" << endl;
        cout << "3. Peek (посмотреть вершину)" << endl;
        cout << "4. Показать весь стек" << endl;
        cout << "5. Проверить пустоту" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Введите строку: ";
                cin.getline(str, 100);
                stack.push(str);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                if (stack.isEmpty()) {
                    cout << "Стек пуст!" << endl;
                } else {
                    cout << "Стек не пуст!" << endl;
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