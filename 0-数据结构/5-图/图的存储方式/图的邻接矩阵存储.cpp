#include <iostream>
using namespace std;

#define MaxVertexNum 100            // 最大顶点数
typedef char VertexType;            // 顶点对应的数据类型
typedef int EdgeType;               // 边的权值类型用整型表示

typedef struct
{
    VertexType Vex[MaxVertexNum];   // 顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵，边表
    int VertexNum, EdgeNum;         // 图的当前顶点数和边数
} MGraph;