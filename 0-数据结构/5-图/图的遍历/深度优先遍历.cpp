#include <iostream>
#include <stack>
using namespace std;

#define MaxVertexNum 100            // 最大顶点数
typedef char VertexType;            // 顶点对应的数据类型
typedef int EdgeType;               // 边的权值类型用整型表示

// 邻接矩阵
typedef struct {
    VertexType Vex[MaxVertexNum];   // 顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵，边表
    int VertexNum, EdgeNum;         // 图的当前顶点数和边数
} MGraph;

// 访问函数
void Mg_visit(MGraph Mg, int i) {
    cout << Mg.Vex[i] << " ";
}

// 递归版本的深度优先搜索
void DFS_Recursive(MGraph G, int i, bool vis[]) {
    Mg_visit(G, i);      // 访问顶点i
    vis[i] = true;       // 标记为已访问
    
    // 遍历所有邻接点
    for (int v = 0; v < G.VertexNum; ++v) {
        // 如果存在边且未访问过
        if (G.Edge[i][v] != 0 && !vis[v]) {
            DFS_Recursive(G, v, vis);  // 递归访问
        }
    }
}

// 非递归版本的深度优先搜索
void DFS_Iterative(MGraph G, int start) {
    bool vis[MaxVertexNum] = {false};  // 访问标记数组
    stack<int> s;                      // 使用栈代替递归
    
    s.push(start);
    vis[start] = true;
    
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        Mg_visit(G, u);  // 访问顶点
        
        // 逆序压入邻接点，保证访问顺序与递归版一致
        for (int v = G.VertexNum - 1; v >= 0; --v) {
            if (G.Edge[u][v] != 0 && !vis[v]) {
                s.push(v);
                vis[v] = true;
            }
        }
    }
}

// 统一调用接口
void DFS(MGraph G, int start, bool useRecursive = true) {
    bool vis[MaxVertexNum] = {false};  // 初始化访问标记数组
    
    if (useRecursive) {
        DFS_Recursive(G, start, vis);
    } else {
        DFS_Iterative(G, start);
    }
    cout << endl;
}

int main() {
    MGraph G;
    G.VertexNum = 5;
    G.EdgeNum = 6;  // 修正边数
    
    // 初始化顶点
    for (int i = 0; i < G.VertexNum; ++i) {
        G.Vex[i] = 'A' + i;
    }
    
    // 初始化邻接矩阵
    for (int i = 0; i < G.VertexNum; ++i) {
        for (int j = 0; j < G.VertexNum; ++j) {
            G.Edge[i][j] = 0;
        }
    }
    
    // 添加边
    G.Edge[0][1] = 1;  // A-B
    G.Edge[0][2] = 1;  // A-C
    G.Edge[1][3] = 1;  // B-D
    G.Edge[2][4] = 1;  // C-E
    G.Edge[3][4] = 1;  // D-E
    G.Edge[3][0] = 1;  // D-A
    
    cout << "递归版本DFS结果：";
    DFS(G, 0, true);
    
    cout << "非递归版本DFS结果：";
    DFS(G, 0, false);
    
    return 0;
}