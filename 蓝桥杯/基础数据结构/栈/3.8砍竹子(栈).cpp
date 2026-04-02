#include<bits/stdc++.h>
using namespace std;
/*
    计算将每根竹子砍到高度为 1 , 将所有竹子砍到高度为 1 的次数相加得到一个整数 , 记作 ans
    记录每根竹子被砍后的高度 , 用 f[i][j] 表示第 i 根竹子被砍后的高度 ,  f[i][0]  表示竹子被砍最后一次的高度
    最后 , 从 f[0][0] 开始 , 每次判断是否与上一根竹子的高度相同 , 如果相同 , 则 ans-- , 否则继续判断下一个高度
*/
typedef long long ll;
const int N  = 200010 , M = 10;         // 一根竹子砍到高度为 1 , 最多需要 6 次 , 这里设置 M = 10

ll f[N][M];                         // f[i][j]: 第 i 根竹子被砍后的高度 ,  f[i][0]  表示竹子被砍最后一次的高度
ll stk[M];                       // 手写栈

int main()
{
    int n; cin >> n;
    int ans = 0;
    for (int i = 0 ; i < n ; ++i){
        ll x; cin >> x;
        int top = 0;
        while (x > 1){
            stk[++top] = x;                       // 记录竹子高度
            x = floor(sqrt(floor(x / 2) + 1));      // 砍后更新竹子高度
        }
        ans += top;                             // 每根竹子单独砍 , 总共砍 top 次
        for (int j = 0 , k = top ; k ; j++ , k--){
            f[i][j] = stk[k];                     // 第 i 根竹子的高度
        }
    }
    for (int j = 0; j < M; j++)
    {
        for (int i = 1 ; i < n ; i++)
        {
            if (f[i][j] && f[i][j] == f[i-1][j])
            {
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}