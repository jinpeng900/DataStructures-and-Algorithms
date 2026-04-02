#include <iostream>
using namespace std;

typedef char ElemType;
#define MAX_TREE_SIZE 100

typedef struct      // 树的结点
{
    ElemType data;          // 数据域
    int parent;     // 双亲指针
}ptNode;

typedef struct      // 树
{
    ptNode nodes[MAX_TREE_SIZE];
    int n;      // 根结点的下标 ， 结点数
}ptTree;