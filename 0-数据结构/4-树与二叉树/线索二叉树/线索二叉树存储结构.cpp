#include<iostream>
using namespace std;

typedef char ElemType;

typedef struct ThreadNode{
    ElemType data;              // 数据域
    struct ThreadNode * lchild , * rchild;          // 左右孩子指针
    int ltag , rtag;                // 左右线索标志
}ThreadNode , *ThreadTree;


// 中序线索化二叉树
void InThread(ThreadTree &T , ThreadTree &pre){
    if(T){
        InThread(T->lchild , pre);              // 递归 , 线索化左子树
        if(T->lchild == NULL){                  // 如果左子树为空 , 则将左线索指向中序遍历的前一个节点
            T->lchild = pre;                    // 将左线索指向中序遍历的前一个节点
            T->ltag = 1;
        }
        if(pre->rchild == NULL){                // 如果右子树为空 , 则将右线索指向中序遍历的后一个节点
            pre->rchild = T;                    // 将右线索指向中序遍历的后一个节点
            pre->rtag = 1;
        }
        pre = T;
        InThread(T->rchild , pre);              // 递归 , 线索化右子树
    }
}


void create_ThreadTree(ThreadTree T){
    ThreadTree pre = NULL;
    if (T){
        InThread(T , pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}


ThreadTree *FirstNode(ThreadTree *T){
    while (T->ltag == 0) T = T->lchild;
    return T;   // 返回中序遍历的第一个节点
}


ThreadTree *NextNode(ThreadTree *T){
    if (T->rtag == 0) return FirstNode(T->rchild);
    else return T->rchild;
}
