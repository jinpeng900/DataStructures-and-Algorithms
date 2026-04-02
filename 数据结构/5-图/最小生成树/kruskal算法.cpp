#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000, MAXM = 10000, INF = 0x3f3f3f3f;

// 边的结构体
typedef struct Edge {
    int a, b, w; // 边的两个顶点和权重
} Edge;

Edge edges[MAXM]; // 存储所有边
int fa[MAXN]; // 并查集数组
int n, m, res; // 点数、边数、结果

// 并查集的查找操作（带路径压缩）
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

// 比较函数，用于边的排序
bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

void kruskal();

int main() {
    cin >> n >> m; // 读入点数n和边数m
    
    // 初始化并查集
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    
    // 读入边
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b;
        w = rand() % 100;
        cout << w << endl;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].w = w;
    }
    
    kruskal(); // 调用Kruskal算法
    
    if (res == INF) {
        cout << "orz" << endl;
    } else {
        cout << res << endl;
    }
    
    return 0;
}

void kruskal() {
    sort(edges + 1, edges + m + 1, cmp); // 按边权从小到大排序
    
    int cnt = 0; // 记录已选边的数量
    res = 0;     // 初始化结果
    
    // 遍历所有边
    for (int i = 1; i <= m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;
        
        int fa_a = find(a);
        int fa_b = find(b);
        
        if (fa_a != fa_b) { // 如果两个顶点不在同一集合中
            fa[fa_b] = fa_a; // 合并两个集合
            res += w;        // 累加边权
            cnt++;           // 边数加1
            
            if (cnt == n - 1) { // 如果已选边数达到n-1，说明生成树已完成
                return;
            }
        }
    }
    
    // 如果遍历完所有边都没有选够n-1条边，说明图不连通
    res = INF;
}