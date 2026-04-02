/*

    小蓝的角色一共有 N 个可以加攻击力的技能.
其中第 i 个技能首次升级可以提升 Ai 点攻击力 , 以后每次升级增加的点数都会减少 Bi 点.
Ai / Bi 次(向上取整) 之后 , 再升级该技能的攻击力将不会改变
现在小蓝可以总计升级 M 次 , 他可以任意选择升级的技能和次数 , 请问他最多可以提升多少攻击力?

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef pair<int , int> PII;
priority_queue<PII>q;           // 默认是大根堆
PII p;

int main()
{
    int n , m; cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
    {
        int a , b; cin >> a >> b;
        q.push(make_pair(a , b));
    }
    long long ans = 0;
    while(m--)                  // 升级 m 次
    {
        if (q.empty()) break;
        p = q.top(); q.pop();            // 每次升级取出当前攻击力最大的技能
        ans += p.first;                  // 累加攻击力
        p.first -= p.second;            // 更新当前攻击力
        if (p.first > 0) q.push(p);    // 如果当前攻击力还大于 0 , 则入队
    }
    cout << ans << endl;
    return 0;
}

