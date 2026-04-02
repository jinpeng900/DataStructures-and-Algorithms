#include <iostream>
using namespace std;

#define MAXSIZE 50              // 定义栈中元素的最大个数
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];             // 存放栈中元素
    int top;                            // 栈顶指针
}SqStack;


// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;                         // 栈顶指针初始化为 -1
}


// 判断栈是否为空
bool IsEmpty(SqStack S)
{
    return S.top == -1;
}


// 判断栈是否已满
bool IsFull(SqStack S)
{
    return S.top == MAXSIZE - 1;
}


// 入栈
bool Push(SqStack &S , ElemType e)
{
    if (IsFull(S)) return false;        // 栈已满 , 入栈失败
    S.data[++S.top] = e;                // 栈顶指针加 1 , 并将 e 入栈
    return true;
}


// 出栈
bool Pop(SqStack &S , ElemType &e)
{
    if (IsEmpty(S)) return false;       // 栈为空 , 出栈失败
    e = S.data[S.top--];                // 将栈顶元素赋值给 e , 并将栈顶指针减 1
    return true;
}


// 获取栈顶元素
bool GetTop(SqStack S , ElemType &e)
{
    if (IsEmpty(S)) return false;       // 栈为空
    e = S.data[S.top];                  // 将栈顶元素赋值给 e
    return true;
}