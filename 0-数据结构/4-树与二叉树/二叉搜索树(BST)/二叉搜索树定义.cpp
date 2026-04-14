#include <iostream>
using namespace std;

// 定义节点结构
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root = nullptr;

    // 插入节点
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // 中序遍历 (结果应为有序序列)
    void inorder() {
        inorderRecursive(root);
        cout << endl;
    }

private:
    Node* insertRecursive(Node* node, int val) {
        if (node == nullptr) return new Node(val);

        if (val < node->data)
            node->left = insertRecursive(node->left, val);
        else if (val > node->data)
            node->right = insertRecursive(node->right, val);
            
        return node;
    }

    void inorderRecursive(Node* node) {
        if (node) {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }
};

int main() {
    BST tree;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x : values) tree.insert(x);

    cout << "C++ BST 中序遍历结果: ";
    tree.inorder();
    return 0;
}