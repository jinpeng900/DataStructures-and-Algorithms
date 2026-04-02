#include <iostream>
using namespace std;

#define MAXSIZE 50              // 定义队列中元素的最大个数
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];             // 存放队列中元素
    int front , rear;                   // 队头指针和队尾指针
}SqQueue;


// 初始化队列
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;               // 队头指针和队尾指针初始化为 0
}


// 判断队列是否为空
bool IsEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}


// 判断队列是否已满
bool IsFull(SqQueue Q)
{
    return (Q.rear + 1) % MAXSIZE == Q.front;
}


// 入队
bool EnQueue(SqQueue &Q , ElemType e)
{
    if (IsFull(Q)) return false;        // 队列已满 , 入队失败
    Q.data[Q.rear] = e;                 // 将 e 入队
    Q.rear = (Q.rear + 1) % MAXSIZE;    // 队尾指针加 1
    return true;
}


// 出队
bool DeQueue(SqQueue &Q , ElemType &e)
{
    if (IsEmpty(Q)) return false;       // 队列为空 , 出队失败
    e = Q.data[Q.front];                // 将队头元素赋值给 e
    Q.front = (Q.front + 1) % MAXSIZE;  // 队头指针加 1
    return true;
}
