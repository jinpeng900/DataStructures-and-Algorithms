# include<iostream>
# include<vector>
using namespace std;


int fa[100005];  // fa[i]表示元素i的父节点

// 初始化并查集
void init(int n){
    for (int i = 1; i <= n; ++i){
        fa[i] = i;  // 每个元素的父节点初始为自己
    }
}

// 查找操作，返回元素x所在集合的代表元素（根节点）
int find(int x){
    if (fa[x] != x){
        fa[x] = find(fa[x]);  // 路径压缩优化
    }
    return fa[x];
}

// 合并操作，将元素x和y所在的集合合并
void unite(int x, int y){
    fa[find(x)] = find(y);  // 将x所在集合的根节点指向y所在集合的根节点 , 将x所在集合合并到y所在集合
}


int main(){
    // 示例用法
    // 省份数量
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> isConnected[i][j];
        }
    }
    init(n);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (isConnected[i][j] == 1){
                unite(i, j);  // 城市编号从1开始
            }
        }
    }
    // 统计不同根节点的数量
    int provinces = 0;
    for (int i = 1; i <= n; ++i){
        if (find(i) == i){
            provinces++;
        }
    }
    cout << provinces << endl;
}