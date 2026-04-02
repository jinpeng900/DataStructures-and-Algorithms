#include<iostream>

using namespace std;

#define MaxSize 50          // 定义线性表的最大长度
#define ElemType int

typedef struct{
    ElemType data[MaxSize];         // 顺序表的元素
    int length;                     // 顺序表的当前长度
}Sqlist;                            // 顺序表的类型定义

// 顺序表的初始化
void InitList(Sqlist &L){           
    L.length = 0;                   // 顺序表初始长度为0
}