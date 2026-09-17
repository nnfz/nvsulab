#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <windows.h>

using namespace std;
using namespace chrono;

void generateFile(const string& filename, int count) {
    ofstream file(filename);
    srand(time(0));
    for (int i = 0; i < count; i++) {
        file << rand() % 100000 << endl;
    }
    file.close();
    cout << "Файл " << filename << " создан с " << count << " числами." << endl;
}

vector<int> readFile(const string& filename) {
    vector<int> arr;
    ifstream file(filename);
    int num;
    while (file >> num) {
        arr.push_back(num);
    }
    file.close();
    return arr;
}

void writeFile(const string& filename, const vector<int>& arr) {
    ofstream file(filename);
    for (int num : arr) {
        file << num << endl;
    }
    file.close();
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string inputFile = "numbers.txt";
    string outputBubble = "sorted_bubble.txt";
    string outputInsertion = "sorted_insertion.txt";
    int count = 10000;

    int choice;
    cout << "1. Сгенерировать файл с " << count << " числами" << endl;
    cout << "2. Сортировать существующий файл" << endl;
    cout << "Выберите действие: ";
    cin >> choice;

    if (choice == 1) {
        generateFile(inputFile, count);
    }

    vector<int> data = readFile(inputFile);
    cout << "Прочитано " << data.size() << " чисел из файла." << endl;

    vector<int> dataBubble = data;
    auto start = high_resolution_clock::now();
    bubbleSort(dataBubble);
    auto end = high_resolution_clock::now();
    auto durationBubble = duration_cast<milliseconds>(end - start);
    writeFile(outputBubble, dataBubble);
    cout << "\nОбменная сортировка:" << endl;
    cout << "Время: " << durationBubble.count() << " мс" << endl;
    cout << "Результат сохранен в " << outputBubble << endl;

    vector<int> dataInsertion = data;
    start = high_resolution_clock::now();
    insertionSort(dataInsertion);
    end = high_resolution_clock::now();
    auto durationInsertion = duration_cast<milliseconds>(end - start);
    writeFile(outputInsertion, dataInsertion);
    cout << "\nСортировка вставками:" << endl;
    cout << "Время: " << durationInsertion.count() << " мс" << endl;
    cout << "Результат сохранен в " << outputInsertion << endl;

    return 0;
}