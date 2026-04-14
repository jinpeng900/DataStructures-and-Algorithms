# include<iostream>
using namespace std;

enum PointerTag {Link , Thread};            // Link = 0 : 孩子 ; Thread = 1 : 线索

struct Node{
    char data;
    Node *left , *right;
    PointerTag ltag , rtag;

    Node(char val) : data(val) , left(nullptr) , right(nullptr) , ltag(Link) , rtag(Link) {}
};


Node* pre = nullptr;    // 全局变量，指向当前访问节点的前驱节点


// 中序线索化二叉树
void createInThread(Node* root){
    if (!root) return;

    createInThread(root->left);   // 递归线索化左子树

    // 处理当前节点
    if (!root->left){            // 如果当前节点没有左子树
        root->ltag = Thread;     // 将左标志设为Thread
        root->left = pre;       // 将左指针指向前驱节点
    }
    if (pre && !pre->right){     // 如果前驱节点存在且没有右子树
        pre->rtag = Thread;      // 将前驱节点的右标志设为Thread
        pre->right = root;      // 将前驱节点的右指针指向当前节点
    }
    pre = root;                // 更新前驱节点为当前节点

    createInThread(root->right);  // 递归线索化右子树
}


// 中序遍历线索二叉树
void inOrderThread(Node* root){
    Node* p = root;
    while (p){
        while (p->ltag == Link) p = p->left;  // 沿左子树一直走到最左端
        cout << p->data << " ";  // 访问当前节点
        if (p->rtag == Thread) p = p->right;  // 如果右标志是Thread，直接跳到后继节点
        else p = p->right;  // 否则继续沿右子树走
    }

}