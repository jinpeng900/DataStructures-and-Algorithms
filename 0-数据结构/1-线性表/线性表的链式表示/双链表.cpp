#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct DNode{
    ElemType data;                  // 数据域
    struct DNode *prior;            // 指向前一个节点的指针域
    struct DNode *next;             // 指向后一个节点的指针域
}DNode,*DLinkList;


// 初始化双链表
void InitDList(DLinkList &L)
{
    L = new DNode;                  // 申请一个新节点作为头节点
    L->prior = NULL;                // 头节点的前一个节点指针域指向 NULL
    L->next = NULL;                 // 头节点的后一个节点指针域指向 NULL
}


// 判断双链表是否为空
bool IsEmpty(DLinkList L)
{
    return L->next == NULL;
}


// 求双链表的长度
int GetLength(DLinkList L)
{
    int len = 0;                        // 计数变量 , 初始为 0
    DNode *p = L;
    while (p->next!=NULL){
        p = p->next;
        len++;                          // 每遍历一个节点 , 长度加 1
    }
    return len;
}


// 插入操作
bool ListInsert(DLinkList L , int i , ElemType e)
{
    if (i < 1) return false;           // i 不合法
    DNode *p = L;                       // 从头节点开始遍历
    int j = 0;                          // 计数变量 , 初始为 0
    while (p && j < i-1){               // 遍历到第 i-1 个元素
        p = p->next;
        j++;
    }
    if (!p) return false;              // 第 i-1 个元素不存在
    DNode *s = new DNode;              // 申请一个新节点
    s->data = e;                       // 新节点的数据域为 e
    s->next = p->next;                 // 新节点的指针域指向第 i 个元素
    p->next = s;                       // 第 i-1 个元素的指针域指向新节点
    s->prior = p;                      // 新节点的前一个节点指针域指向第 i-1 个元素
    if (s->next) s->next->prior = s;   // 如果第 i 个元素存在 , 则第 i 个元素的前一个节点指针域指向新节点
    return true;
}


// 删除操作
bool ListDelete(DLinkList L , int i , ElemType &e)
{
    if (i < 1) return false;           // i 不合法
    DNode *p = L;                       // 从头节点开始遍历
    int j = 0;                          // 计数变量 , 初始为 0
    while (p->next && j < i-1){        // 遍历到第 i-1 个元素
        p = p->next;
        j++;
    }
    if (!p->next) return false;        // 第 i-1 个元素不存在
    DNode *q = p->next;                 // 第 i-1 个元素的指针域指向第 i 个元素
    e = q->data;                       // 用 e 返回第 i 个元素的数据域
    p->next = q->next;                 // 第 i-1 个元素的指针域指向第 i+1 个元素
    if (p->next) p->next->prior = p;   // 如果第 i+1 个元素存在 , 则第 i+1 个元素的前一个节点指针域指向第 i-1 个元素
    delete q;                          // 释放第 i 个元素的空间
}


// 打印双链表
void PrintDList(DLinkList L)
{
    DNode *p = L->next;
    while (p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}



int main()
{
    DLinkList L;
    InitDList(L);
    ListInsert(L , 1 , 1);
    ListInsert(L , 2 , 2);
    ListInsert(L , 3 , 3);
    ElemType e;
    ListDelete(L , 2 , e);
    PrintDList(L);
    return 0;
}