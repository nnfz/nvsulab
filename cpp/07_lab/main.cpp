#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;

    Node(int v, Node* p = nullptr) : value(v), left(nullptr), right(nullptr), parent(p) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroy(root);
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }
        Node* current = root;
        while (true) {
            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = new Node(value, current);
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new Node(value, current);
                    return;
                }
                current = current->right;
            }
        }
    }

    void leftOrder(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->value);
        leftOrder(node->left, result);
        leftOrder(node->right, result);
    }

    void rightOrder(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        result.push_back(node->value);
        rightOrder(node->right, result);
        rightOrder(node->left, result);
    }

    void symmetricOrder(Node* node, vector<int>& result) {
        if (node == nullptr) return;
        symmetricOrder(node->left, result);
        result.push_back(node->value);
        symmetricOrder(node->right, result);
    }

    void draw() {
        if (root == nullptr) {
            cout << "Дерево пусто" << endl;
            return;
        }
        int h = height(root);
        int n = count(root);
        int cellW = maxLength(root) + 2;
        int width = n * cellW + maxLength(root);
        vector<string> grid(h * 2 - 1, string(width, ' '));
        int counter = 0;
        fill(root, 0, counter, cellW, grid);
        for (string& line : grid) {
            size_t end = line.find_last_not_of(' ');
            cout << line.substr(0, end + 1) << endl;
        }
    }

private:
    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int count(Node* node) {
        if (node == nullptr) return 0;
        return 1 + count(node->left) + count(node->right);
    }

    int maxLength(Node* node) {
        if (node == nullptr) return 0;
        int own = (int)to_string(node->value).size();
        return max(own, max(maxLength(node->left), maxLength(node->right)));
    }

    int fill(Node* node, int depth, int& counter, int cellW, vector<string>& grid) {
        if (node == nullptr) return -1;

        int leftCenter = fill(node->left, depth + 1, counter, cellW, grid);

        int col = counter * cellW;
        counter++;
        string text = to_string(node->value);
        int row = depth * 2;
        for (size_t i = 0; i < text.size(); i++) {
            grid[row][col + i] = text[i];
        }
        int center = col + (int)text.size() / 2;

        int rightCenter = fill(node->right, depth + 1, counter, cellW, grid);

        if (leftCenter != -1 || rightCenter != -1) {
            grid[row + 1][center] = '+';
            if (leftCenter != -1) {
                for (int x = leftCenter; x < center; x++) grid[row + 1][x] = '-';
                grid[row + 1][leftCenter] = '+';
            }
            if (rightCenter != -1) {
                for (int x = center + 1; x <= rightCenter; x++) grid[row + 1][x] = '-';
                grid[row + 1][rightCenter] = '+';
            }
        }
        return center;
    }
};

vector<int> treeSort(const vector<int>& array) {
    BinaryTree tree;
    for (int x : array) {
        tree.insert(x);
    }
    vector<int> result;
    tree.symmetricOrder(tree.root, result);
    return result;
}

void print(const string& title, const vector<int>& v) {
    cout << title;
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    }
    cout << endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    vector<int> array = {5, 1, 91, 4, 7, 51, 40, 61, 57, 71, 9, 8, 3};

    BinaryTree tree;
    for (int x : array) {
        tree.insert(x);
    }

    vector<int> left, right, symmetric;
    tree.leftOrder(tree.root, left);
    tree.rightOrder(tree.root, right);
    tree.symmetricOrder(tree.root, symmetric);

    print("Исходный массив:      ", array);
    print("Обход слева:          ", left);
    print("Обход справа:         ", right);
    print("Симметрический обход: ", symmetric);
    print("Отсортированный:      ", treeSort(array));

    cout << endl << "Дерево:" << endl;
    tree.draw();

    return 0;
}
