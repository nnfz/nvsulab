#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    double data[MAX_SIZE];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    void push(double value) {
        if (topIndex >= MAX_SIZE - 1) {
            throw overflow_error("Стек переполнен!");
        }
        data[++topIndex] = value;
        cout << "Элемент " << value << " добавлен в стек." << endl;
    }

    double pop() {
        if (isEmpty()) {
            throw underflow_error("Стек пуст! Невозможно удалить элемент.");
        }
        double value = data[topIndex--];
        cout << "Элемент " << value << " удален из стека." << endl;
        return value;
    }

    double top() const {
        if (isEmpty()) {
            throw underflow_error("Стек пуст! Нет вершины.");
        }
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == MAX_SIZE - 1;
    }

    int size() const {
        return topIndex + 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Стек пуст!" << endl;
            return;
        }
        cout << "Содержимое стека (сверху вниз): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Stack stack;
    int choice;
    double value;

    do {
        cout << "\n=== МЕНЮ СТЕКА ===" << endl;
        cout << "1. Добавить элемент (push)" << endl;
        cout << "2. Удалить элемент (pop)" << endl;
        cout << "3. Показать вершину стека (top)" << endl;
        cout << "4. Показать содержимое стека" << endl;
        cout << "5. Проверить размер стека" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Введите вещественное число: ";
                    cin >> value;
                    stack.push(value);
                    break;

                case 2:
                    stack.pop();
                    break;

                case 3:
                    cout << "Вершина стека: " << stack.top() << endl;
                    break;

                case 4:
                    stack.display();
                    break;

                case 5:
                    cout << "Размер стека: " << stack.size() << endl;
                    break;

                case 0:
                    cout << "Выход из программы..." << endl;
                    break;

                default:
                    cout << "Неверный выбор! Попробуйте снова." << endl;
            }
        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}