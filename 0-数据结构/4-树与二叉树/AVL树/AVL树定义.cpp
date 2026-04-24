#include <iostream>
#include <algorithm>

struct Node {
    int key;
    int height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    // 获取节点高度，空节点为0
    int height(Node* n) {
        return n ? n->height : 0;
    }

    // 计算平衡因子
    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    // 右旋转 (LL型)
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // 执行旋转
        x->right = y;
        y->left = T2;

        // 更新高度
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x; // 返回新的根节点
    }

    // 左旋转 (RR型)
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // 执行旋转
        y->left = x;
        x->right = T2;

        // 更新高度
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

public:
    Node* insert(Node* node, int key) {
        // 1. 标准 BST 插入
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else 
            return node; // 不允许相同节点

        // 2. 更新高度
        node->height = 1 + std::max(height(node->left), height(node->right));

        // 3. 获取平衡因子并检查是否失衡
        int balance = getBalance(node);

        // Case 1: LL 型 (左左)
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Case 2: RR 型 (右右)
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Case 3: LR 型 (左右)
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Case 4: RL 型 (右左)
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // 中序遍历验证结果
    void inOrder(Node* root) {
        if (root) {
            inOrder(root->left);
            std::cout << root->key << " ";
            inOrder(root->right);
        }
    }
};