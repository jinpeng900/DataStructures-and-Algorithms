#include<iostream>

using namespace std;


#define LIST_INIT_SIZE 1000         // 线性表存储空间的初始分配量
#define LISTINCREMENT 20            // 线性表存储分量的分配增量

#define ElemType int

typedef struct LNode
{
    ElemType *elem;
    int length;
    int listsize;
}Sqlist;

void Init(Sqlist * L)
{
    L->elem = new ElemType[LIST_INIT_SIZE];
    if (L->elem == nullptr)
    {
        cout << "空间分配失败" << endl;
        return;
    }
    else
    {
        L->length = 0;
        L->listsize = LIST_INIT_SIZE;
    }
}


int del_x(Sqlist &L , ElemType x)
{
    int count = 0;
    int len = L.length;
    for (int i = 1 ; i <= len ; ++i)
    {
        if (L.elem[i] == x)
        {
            ++count;
        }

        else
        {
            L.elem[i-count] = L.elem[i];
        }
    }
    L.length = L.length-count;
    return count;
}


int main()
{
    Sqlist s;
    Init(&s);
    s.elem[1] = 1 ;
    s.elem[2] = 3 ;
    s.elem[3] = 4 ;
    s.elem[4] = 6 ;
    s.elem[5] = 1 ;
    s.elem[6] = 7 ;
    s.elem[7] = 9 ;
    s.elem[8] = 1 ;
    s.elem[9] = 1 ;
    s.length = 9;
    int num = del_x(s , 1);
    cout << num << endl;
    cout << endl;
    for (int i = 1 ; i <= s.length ; i++)
    {
        cout << s.elem[i] << endl;
    }

    delete[] s.elem;

    return 0;
}