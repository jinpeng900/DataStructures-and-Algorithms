#include<iostream>
using namespace std;

typedef int QElemType ;


typedef struct QNode
{
    QElemType data;
    QNode * next;
}QNode;

typedef struct
{
    QNode * front;           // 队头指针
    QNode * rear;            // 队尾指针
}LinkQueue;


// ----- 基本操作的函数 ----
void InitQueue(LinkQueue &Q)
{
    // 构造一个空队列 Q
    Q.front = Q.rear = (QNode *)malloc(sizeof(QNode));
    if (Q.front == NULL)
    {
        cout << "分配空间失败" << endl;
        return;
    }
    Q.front->next = NULL;
}


void DestroyQueue(LinkQueue &Q)
{
    // 销毁队列Q
    while(Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}


void EnQueue(LinkQueue &Q , QElemType e)
{
    // 插入元素 e 为 Q 的新的队尾元素
    QNode * p = (QNode *)malloc(sizeof(QNode));
    if (p == NULL)
    {
        cout << "分配 p 空间失败" << endl;
        return;
    }
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}


void DeQueue(LinkQueue &Q , QElemType e)
{
    // 若队列不空 ， 则删除 Q 的队头元素 ， 用 e 返回其值
    if (Q.front == Q.rear)
    {
        cout << "队列空了" << endl;
        return;
    }
    QNode * p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
}