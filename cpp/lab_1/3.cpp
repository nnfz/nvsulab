#include <iostream>
#include <stdexcept>
#include <windows.h>

using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    double data[MAX_SIZE];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue() : frontIndex(0), rearIndex(-1), count(0) {}

    void enqueue(double value) {
        if (isFull()) {
            throw overflow_error("Очередь переполнена!");
        }
        rearIndex = (rearIndex + 1) % MAX_SIZE;
        data[rearIndex] = value;
        count++;
        cout << "Элемент " << value << " добавлен в очередь." << endl;
    }

    double dequeue() {
        if (isEmpty()) {
            throw underflow_error("Очередь пуста! Невозможно удалить элемент.");
        }
        double value = data[frontIndex];
        frontIndex = (frontIndex + 1) % MAX_SIZE;
        count--;
        cout << "Элемент " << value << " удален из очереди." << endl;
        return value;
    }

    int length() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == MAX_SIZE;
    }

    double front() const {
        if (isEmpty()) {
            throw underflow_error("Очередь пуста! Нет первого элемента.");
        }
        return data[frontIndex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return;
        }
        cout << "Содержимое очереди (спереди назад): ";
        int index = frontIndex;
        for (int i = 0; i < count; i++) {
            cout << data[index] << " ";
            index = (index + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Queue queue;
    int choice;
    double value;

    do {
        cout << "\n=== МЕНЮ ОЧЕРЕДИ ===" << endl;
        cout << "1. Добавить элемент (enqueue)" << endl;
        cout << "2. Удалить элемент (dequeue)" << endl;
        cout << "3. Показать длину очереди" << endl;
        cout << "4. Показать содержимое очереди" << endl;
        cout << "5. Показать первый элемент" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Введите вещественное число: ";
                    cin >> value;
                    queue.enqueue(value);
                    break;

                case 2:
                    queue.dequeue();
                    break;

                case 3:
                    cout << "Длина очереди: " << queue.length() << endl;
                    break;

                case 4:
                    queue.display();
                    break;

                case 5:
                    cout << "Первый элемент: " << queue.front() << endl;
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