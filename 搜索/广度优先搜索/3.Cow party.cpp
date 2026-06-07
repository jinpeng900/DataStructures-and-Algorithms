#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int qiao_dijkstra(int start , int target , int n , const vector<vector<int>>& matrix){
    vector<int> dist(n+1 , INF);                     // 记录从 start 到各个点的当前最短距离
    vector<bool> visited(n+1 , false);               // 记录哪些点已经确定了最短路径

    dist[start] = 0;                                 // 起点到自己的距离是 0
    
    for (int i = 1 ; i <= n ; i++){
        int u = -1;                                  // 选择当前未访问的点中距离最小的点
        for (int j = 1 ; j <= n ; j++){
            if (!visited[j] && (u == -1 || dist[j] < dist[u])){
                u = j;
            }
        }

        if (dist[u] == INF) break;                   // 如果最小距离是无穷大，说明剩余的点不可达，直接退出

        visited[u] = true;                          // 标记 u 已经访问

        for (int v = 1 ; v <= n ; v++){             // 更新与 u 相邻的点 v 的距离
            if (!visited[v] && matrix[u][v] != INF){ // 如果 v 没有访问且 u 和 v 之间有边
                dist[v] = min(dist[v], dist[u] + matrix[u][v]); // 更新 v 的距离
            }
        }
    }
    return dist[target];
}

int main(){
    int m , n , x;
    cin >> m >> n >> x;

    vector<vector<int>> matrix(n+1 , vector<int>(n+1 , INF)); // 邻接矩阵，初始为无穷大

    for (int i = 0 ; i < m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        matrix[u][v] = min(matrix[u][v] , w); // 处理重边
    }

    cout << qiao_dijkstra(x , 1 , n , matrix) << endl;
    
}