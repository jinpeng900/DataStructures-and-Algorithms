#include<iostream>
#include<queue>
using namespace std;

typedef char ElemType;

typedef struct BiTNode{
    ElemType data;                  // 数据域
    struct BiTNode *lchild , *rchild;                  // 左、右孩子指针
}BiTNode , *BiTree;


// 初始化二叉树
void InitBiTree(BiTree &T){
    T = NULL;
}


// 先序遍历
void PreOrder(BiTree T){
    if(T){
        cout << T->data << endl;
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}


// 中序遍历
void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        cout << T->data << endl;
        InOrder(T->rchild);
    }
}


// 后序遍历
void PostOrder(BiTree T){
    if(T){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->data << endl;
    }
}


// 层序遍历
void LevelOrder(BiTree T){
    queue<BiTNode*> Q;
    Q.push(T);
    while (!Q.empty()){
        BiTNode *p = Q.front();
        Q.pop();
        cout << p->data << endl;
        if (p->lchild) Q.push(p->lchild);
        if (p->rchild) Q.push(p->rchild);
    }
}


// 计算二叉树的高度
int Height(BiTree T){
    if(T){
        int lchild_height = Height(T->lchild);
        int rchild_height = Height(T->rchild);
        return lchild_height > rchild_height ? lchild_height + 1 : rchild_height + 1;
    }
    else{
        return 0;
    }
}


int main()
{
    /*
     assign data and links to form the tree:
            A
           / \
          B   C
         / \   \
        D   E   F
           /
          G
    */
    BiTree T = new BiTNode;
    T->data = 'A';
    T->lchild = new BiTNode;
    T->lchild->data = 'B';
    T->lchild->lchild = new BiTNode;
    T->lchild->lchild->data = 'D';
    T->lchild->lchild->lchild = NULL;
    T->lchild->lchild->rchild = NULL;
    T->lchild->rchild = new BiTNode;
    T->lchild->rchild->data = 'E';
    T->lchild->rchild->lchild = new BiTNode;
    T->lchild->rchild->lchild->data = 'G';
    T->lchild->rchild->lchild->lchild = NULL;
    T->lchild->rchild->lchild->rchild = NULL;
    T->lchild->rchild->rchild = NULL;
    T->rchild = new BiTNode;
    T->rchild->data = 'C';
    T->rchild->lchild = NULL;
    T->rchild->rchild = new BiTNode;
    T->rchild->rchild->data = 'F';
    T->rchild->rchild->lchild = NULL;
    T->rchild->rchild->rchild = NULL;

    // 先序遍历
    PreOrder(T);
    cout << endl;
    // 中序遍历
    InOrder(T);
    cout << endl;
    // 后序遍历
    PostOrder(T);
    cout << endl;

    // 层序遍历
    LevelOrder(T);
    cout << endl;

    return 0;
}
