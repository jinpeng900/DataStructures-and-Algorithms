#include <iostream>
using namespace std;

#define MaxVertexNum 100            // 最大顶点数
typedef char VertexType;            // 顶点对应的数据类型
typedef int EdgeType;               // 边的权值类型用整型表示

typedef struct ArcNode              // 边表结点
{
    int AdjVex;                     // 邻接点的下标
    struct ArcNode *NextArc;        // 指向下一个邻接点的指针
    EdgeType Info;                  // 边的权值
} ArcNode;

typedef struct VNode                // 顶点表结点
{
    VertexType Data;                // 顶点信息
    ArcNode *FirstArc;              // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;               // 邻接表
    int VertexNum, EdgeNum;         // 图的当前顶点数和边数
} ALGraph;