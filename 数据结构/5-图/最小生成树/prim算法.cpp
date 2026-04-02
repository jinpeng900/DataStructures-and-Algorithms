#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000 , INF = 0x3f3f3f3f;       // 定义一个 INF 表示无穷大
int g[MAXN][MAXN] , dist[MAXN] , n , m , res;
// 我们用 g[][] 数组存储这个图 ， dist[] 储存到集合 S 的距离 ， res 保存结果
bool book[MAXN];            // 用 book 数组记录某个点是否加入到集合 S 之中

void prim();


int main()
{
    cin >> n >> m;      // 读入这个图的点数 n 和 边数 m
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            g[i][j] = INF;      // 初始化任意两点之间的距离为正无穷 (表示这两个点之间没有边)
        }
        dist[i] = INF;          // 初始化所有点到集合 S 的距离都是正无穷
    }

    for (int i = 1 ; i <= m ; i++)
    {
        int a , b , w;
        cin >> a >> b ;         // 读入 a , b 两个点之间的边
        w = rand()%100;
        cout << w << endl;
        g[a][b] = g[b][a] = w;          // 由于是无向边 ， 我们对 g[a][b] 和 g[b][a] 都要进行赋值
    }

    prim();         // 调用 prim 函数
    if (res == INF)         // 如果 res 的 值为正无穷 ， 表示该图不能转换为一棵树 ， 输出 orz
    {
        cout << "orz" << endl;
    }
    else
    {
        cout << res << endl;
    }
    return 0;
}



void prim()
{
    dist[1] = 0;            // 把 点1 加入到 集合S 中 ， 将它到集合的距离初始化为 0 
    book[1] = true;         // 表示 点1 已经加入到 集合S 中
    for (int i = 2 ; i <= n ; i++)
    {
        dist[i] = min(dist[i] , g[1][i]);
    }       // 用 点1 去更新 dist[]

    for (int i = 2 ; i <= n ; i++)
    {
        int temp = INF;         // 初始化距离
        int t = -1;             // 接下来去寻找距离集合S 最近的点加入到集合之中 ， 用 t 记录下这个点的下标
        for (int j = 2 ; j <= n ; j++)
        {
            if (!book[j] && dist[j] < temp)
            {
                temp = dist[j];         // 更新集合 V 到集合 S 的最小值
                t = j;                  // 把点赋值给 t
            }
        }
        if (t == -1)
        {
            // 如果 t == -1 , 意味着在集合 V 找不到边连向集合 S , 生成树构建失败 ， 将 res 赋值正无穷表示构建失败 ， 结束函数
            res = INF;
            return;
        }
        book[t] = true;     // 如果加上这个点 ， 就把它加入到集合 S
        res += dist[t];     // 加上这个点到集合 S 的距离
        for (int j = 2 ; j <= n ; j++)
        {
            dist[j] = min(dist[j] , g[t][j]);
        }
    }
}