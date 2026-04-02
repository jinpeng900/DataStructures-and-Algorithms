#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int num[N];             // num[i] : 记录 id = i 的帖子的赞的数量
int flag[N];            // flag[i] : 记录 id = i 的帖子曾是热门帖子

struct post{int id , ts;}p[N];              //  记录帖子
int cmp(post x , post y) { return x.ts < y.ts; }            // 按照时间从小到大排序

int main()
{
    int n , d , k; cin >> n >> d >> k;
    for (int i = 0 ; i < n ; i++) cin >> p[i].ts >> p[i].id;
    sort(p , p + n , cmp);
    for (int i = 0 , j = 0 ; i < n ; i++){
        num[p[i].id]++;
        while (p[i].ts - p[j].ts >= d) {
            num[p[j].id]--;
            j++;
        }
        if (num[p[i].id] >= k) flag[p[i].id] = 1;
    }
    for (int i = 0 ; i < n ; i++){
        if (flag[i] == 1) cout << i << endl;
    }
    return 0;
}