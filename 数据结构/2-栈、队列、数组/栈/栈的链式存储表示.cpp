/*

栈是限定仅在表尾进行插入或删除操作（后进先出）的线性表
    表尾端具有特殊的含义，称为栈顶
    相应地 ， 表头端称为栈底
    不含元素的称为空栈
    
*/
#include<iostream>
#include <cstdlib>

using namespace std;

#define STACK_INIT_SIZE 100         // 存储空间初始分配量
#define STACKINCREMENT 10           // 存储空间分配增量
#define SElemType int

typedef struct
{
    SElemType * base;               // base 称为栈底指针 ， 其初值指向栈底 ， base 的值为 NULL 时 ， 可作为栈空的标记
    SElemType * top;                // top 称为栈顶指针 ， 其初始值指向栈底   top = base 可作为栈空的标记
    int stacksize;                  // 栈当前可使用的最大容量
}SqStack;



void InitStack(SqStack & S)
{
    // 构造一个空栈S
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (S.base == NULL)
    {
        return;     //  存储分配失败                              
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
} 
 


void GetTop(SqStack  S , SElemType &e)
{
    // 若栈不为空 ， 则用 e 返回 S 的栈顶元素
    if (S.top == S.base)
    {
        cout << "栈为空" << endl;
        return;
    }
    e = *(S.top - 1);
}



void Push(SqStack & S , SElemType e)
{
    // 插入元素 e 为新的栈顶元素
    if (S.top - S.base >= S.stacksize)
    {
        // 栈满 ， 追加存储空间
        S.base = (SElemType *)realloc(S.base , (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (S.base == NULL)
        {
            cout << "追加存储空间失败" << endl;
            return;
        }
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
}



void Print(SqStack & S)
{
    SElemType *p = S.base;
    while (p != S.top)
    {
        cout << *p << " ";
        p++;
    }
}



bool StackEmpty(SqStack &S)
{
    if(S.base == S.top)
    {
        return true;
    }
    return false;
}



void ClearStack(SqStack &S)
{
    S.top = S.base;
}



void DestoryStack(SqStack &s)
{
    ClearStack(s);
    free(s.base);
}



void Pop(SqStack & S , SElemType & e)
{
    if (S.top == S.base)
    {

        return;
    }
    e = *(S.top-1);
    S.top--;
}



void conversion()
{
    // 实例1：输入的任意一个非负十进制整数 ， 打印输出与其等值的八进制数
    SqStack S;
    InitStack(S);       // 构造空栈
    int N;
    cin >> N;
    while(N)
    {
        Push(S , N % 8);
        N = N / 8;
    }
    while(StackEmpty(S) != true)
    {
        int e;
        Pop(S , e);
        cout << e << " ";
    }

}



bool kuohao()
{
    // 3.2.2 检验括号匹配的检验
    int num;
    cout << "输入数量" << endl;
    cin >> num;
    if (num % 2 != 0)
    {
        return false;
    }
    int arr[num];
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
    }
    SqStack s;
    InitStack(s);
    for(int i = 0 ; i < num ; i++)
    {
        int e;
        if (arr[i] < 0)
        {
            Push(s , arr[i]);
        }
        else
        {
            if (*(s.top-1) == -arr[i])
            {
                Pop(s , e);
            }
            else
            {
                return false;
            }
        }
    }
    if (s.base == s.top)
    {
        return true;
    }
    return false;
}



int main()
{

    system("pause");
    return 0;
}