#include <iostream>
#include <vector>
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

private:
    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
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

    return 0;
}