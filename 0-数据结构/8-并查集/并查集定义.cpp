# include <vector>
# include <iostream>
using namespace std;

// 并查集（Disjoint Set Union，DSU）数据结构
class DSU{
    private:
        vector<int> parent;  // parent[i]表示元素i的父节点
        vector<int> rank;    // rank[i]表示以i为根的树的高度
    
    public:
        // 构造函数，初始化并查集
        DSU(int n){
            // 分配空间并初始化 , 通常习惯从 1 到 n 索引 , 所以开 n+1 大小
            parent.resize(n + 1);
            rank.resize(n + 1, 0);  // 初始时每个元素

            for (int i = 1; i <= n; ++i){
                parent[i] = i;  // 每个元素的父节点初始为自己
            }
        }

        // 查找操作，返回元素x所在集合的代表元素（根节点）
        int find(int x){
            if (parent[x] != x){
                parent[x] = find(parent[x]);  // 路径压缩优化
            }
            return parent[x];
        }

        // 合并操作，将元素x和y所在的集合合并
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY){
                // 按秩合并优化
                if (rank[rootX] > rank[rootY]){
                    parent[rootY] = rootX;  // 将rank较小的树挂到rank较大的树下 , 树的高度不变
                } else if (rank[rootX] < rank[rootY]){
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;  // 如果rank相同，任意选择一个作为新的根
                    rank[rootX]++;         // 增加新根的rank
                }
            }
        }

        // 判断元素x和y是否在同一个集合中
        bool isConnected(int x, int y){
            return find(x) == find(y);
        }

};




int main(){
    // 示例用法
    // 省份数量
    // 给定一个n x n的邻接矩阵isConnected, isConnected[i][j] = 1表示第i个城市和第j个城市直接相连, 否则为0 ; 返回省份的数量
    // 思路: 每成功合并两个不属于同集合的元素，省份数量就减少1 , 初始时每个城市都是一个独立的省份 , 最后剩下的省份数量就是并查集中不同根节点的数量
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> isConnected[i][j];
        }
    }
    DSU dsu(n);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (isConnected[i][j] == 1){
                dsu.unite(i, j);  // 城市编号从1开始
            }
        }
    }
    // 统计不同根节点的数量
    int provinces = 0;
    for (int i = 1; i <= n; ++i){
        if (dsu.find(i) == i){
            provinces++;
        }
    }
    cout << provinces << endl;


}