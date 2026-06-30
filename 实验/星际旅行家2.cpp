#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9999; // 题目定义的不可达值

int main() {
    int n;
    cin >> n;

    // 使用邻接矩阵存储距离
    vector<vector<int>> dist(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall 算法：更新任意两点间的最短距离
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 按照题目要求的顺序累加路径长度
    int total_steps = 0;
    for (int i = 1; i <= n; i++) {
        int next_node = (i == n) ? 1 : i + 1; // 1->2, 2->3...n->1
        total_steps += dist[i][next_node];
    }

    cout << total_steps << endl;

    return 0;
}