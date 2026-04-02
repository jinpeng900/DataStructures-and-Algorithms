#include<iostream>
using namespace std;

typedef int ElementType;

typedef struct LNode{       // 定义单链表节点类型
    ElementType data;               // 数据域   
    struct LNode *next;     // 指针域 , 指向下一个节点
}LNode,*LinkList;



// 初始化带头结点单链表
void InitList(LinkList &L)
{
    L = new LNode;          // 申请一个新节点作为头节点
    L->next = NULL;         // 头节点的指针域指向 NULL
}



// 判断单链表是否为空
bool IsEmpty(LinkList L)
{
    return L->next == NULL;
}



// 求单链表的长度
int GetLength(LinkList L)
{
    int len = 0;                        // 计数变量 , 初始为 0
    LNode *p = L;
    while (p->next!=NULL){
        p = p->next;
        len++;                          // 每遍历一个节点 , 长度加 1
    }
    return len;
}



// 求单链表的第 i 个元素
LNode* GetElem(LinkList L , int i)
{
    if (i < 1) return NULL;             // i 不合法
    LNode *p = L;                       // 从头节点开始遍历
    int j = 0;                          // 计数变量 , 初始为 0
    while (p && j < i){
        p = p->next;
        j++;
    }
    return p;
}



// 查找单链表中第一个值为 e 的节点
LNode* LocateElem(LinkList L , int e)
{
    LNode *p = L->next;
    while (p && p->data != e){
        p = p->next;
    }
    return p;
}



// 插入操作
bool ListInsert(LinkList L , int i , ElementType e)
{
    if (i < 1) return false;           // i 不合法
    LNode *p = L;                       // 从头节点开始遍历
    int j = 0;                          // 计数变量 , 初始为 0
    while (p && j < i-1){               // 遍历到第 i-1 个元素
        p = p->next;
        j++;
    }
    if (!p) return false;              // 第 i-1 个元素不存在
    LNode *s = new LNode;              // 申请一个新节点
    s->data = e;                       // 新节点的数据域为 e
    s->next = p->next;                 // 新节点的指针域指向第 i 个元素
    p->next = s;                       // 第 i-1 个元素的指针域指向新节点
    return true;
}



// 删除操作
bool ListDelete(LinkList L , int i , ElementType &e)
{
    if (i < 1) return false;           // i 不合法
    LNode *p = L;                       // 从头节点开始遍历
    int j = 0;                          // 计数变量 , 初始为 0
    while (p && j < i-1){               // 遍历到第 i-1 个元素
        p = p->next;
        j++;
    }
    if (!p) return false;              // 第 i-1 个元素不存在
    LNode *q = p->next;                 // 第 i-1 个元素的指针域指向第 i 个元素
    if (!q) return false;              // 第 i 个元素不存在
    e = q->data;                       // 用 e 返回第 i 个元素的数据域
    p->next = q->next;                 // 第 i-1 个元素的指针域指向第 i+1 个元素
    delete q;                          // 释放第 i 个元素的空间
}



// 打印单链表
void PrintList(LinkList L)
{
    LNode *p = L->next;
    while (p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}



int main()
{
    LinkList L;
    InitList(L);
    ListInsert(L , 1 , 1);
    ListInsert(L , 2 , 2);
    ListInsert(L , 3 , 3);
    ElementType e;
    ListDelete(L , 2 , e);
    PrintList(L);
    return 0;
}