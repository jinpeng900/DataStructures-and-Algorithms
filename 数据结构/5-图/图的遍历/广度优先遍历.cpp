#include <iostream>
#include <queue>
using namespace std;

#define MaxVertexNum 100            // 最大顶点数
typedef char VertexType;            // 顶点对应的数据类型
typedef int EdgeType;               // 边的权值类型用整型表示

// 邻接表
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



// 邻接矩阵
typedef struct
{
    VertexType Vex[MaxVertexNum];   // 顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵，边表
    int VertexNum, EdgeNum;         // 图的当前顶点数和边数
} MGraph;



void Mg_visit(MGraph Mg ,int i)
{
    cout << Mg.Vex[i] << endl;
}




// 邻接矩阵的广度优先搜索
void BFS(MGraph G , int i){
    Mg_visit(G , i);
    bool vis[MaxVertexNum];
    for(int i=0;i<G.VertexNum;i++){
        vis[i]=false;
    }
    vis[i]=true;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<G.VertexNum;v++){
            if(G.Edge[u][v]!=0&&!vis[v]){
                vis[v]=true;
                Mg_visit(G , v);
                q.push(v);
            }
        }
    }
}

int main()
{
    MGraph G;
    G.VertexNum=5;
    G.EdgeNum=7;
    for(int i=0;i<G.VertexNum;i++){
        G.Vex[i]='A'+i;
    }
    for(int i=0;i<G.VertexNum;i++){
        for(int j=0;j<G.VertexNum;j++){
            G.Edge[i][j]=0;
        }
    }
    G.Edge[0][1]=1;
    G.Edge[0][2]=1;
    G.Edge[1][3]=1;
    G.Edge[2][4]=1;
    G.Edge[3][4]=1;
    G.Edge[3][0]=1;
    BFS(G , 0);
}
