#include<iostream>

using namespace std;

#define InitSize 10          // 定义线性表的初始长度
#define ElemType int
#define IncreaseSize 5       // 数组增量

typedef struct{
    ElemType *data;                 // 指示动态分配数组的指针
    int MaxSize , length;           // 数组的最大容量和当前个数
}Sqlist;                            // 动态分配数组顺序表的类型定义

// 顺序表的初始化
void InitList(Sqlist &L){
    L.data = new ElemType[InitSize];        // 分配存储空间
    L.length = 0;                           // 顺序表的初始长度为0
    L.MaxSize = InitSize;                   // 初始存储容量
}

// 在第 i 个元素之前插入元素 e
bool ListInsert(Sqlist &L , int i , ElemType e){
    if (i < 1 || i > L.length + 1) return false;        // 判断 i 的范围是否有效
    if (L.length >= L.MaxSize){
        ElemType *newbase = new ElemType[L.MaxSize + IncreaseSize];
        L.MaxSize = L.MaxSize + IncreaseSize;
        for (int k = 0 ; k < L.length ; k++)
        {
            newbase[k] = L.data[k];
        }
        L.data = newbase;
    }
    for (int j = L.length ; j >= i ; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;                // 在位置 i 处放入 e
    L.length++;                     // 线性表长度加 1
    return true;
}

// 打印操作
void Print(Sqlist &L)
{
    for (int i = 0 ; i < L.length-1 ; i++)
    {
        cout << L.data[i] << "->";
    }
    cout << L.data[L.length-1] << endl;
}

// 删除操作
bool ListDelete(Sqlist &L , int i , ElemType &e)
{
    if (i < 1 || i > L.length) return false;            // 判断 i 的范围是否有效
    e = L.data[i-1];                                    // 将被删除的元素赋值给 e
    for (int j = i ; j < L.length ; j++)                // 将第 i 个位置的元素前移
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;                             // 线性表长度减一
    return true;
}

// 按值查找（顺序查找）
int LocateElem(Sqlist &L , ElemType e){
    int i;
    for (i = 0 ; i < L.length ; i++)
    {
        if (L.data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}

int main()
{
    Sqlist L;
    InitList(L);
    for (int i = 1 ; i <= 1 ; i++)
    {
        ListInsert(L , 1 , i);
    }
    Print(L);
    return 0;
}