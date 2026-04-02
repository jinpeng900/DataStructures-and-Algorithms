#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef priority_queue<ll , vector<ll> , greater<ll>> pq;
typedef map<ll , int> mp;
mp vis;
int sum[5] = {3 , 5 ,7};

int main()
{
    ll tem = 59084709587505;
    pq qu;
    qu.push(1);
    int ans = 0;
    while(1){
        ll cnt = qu.top();
        qu.pop();
        if (cnt == tem) {cout << ans << endl; break;}
        ll temcnt;
        for (int i = 0 ; i < 3 ; i++){
            temcnt = cnt * sum[i];
            if (vis[temcnt] == 0){
                qu.push(temcnt);
                vis[temcnt] = 1;
            }
        }
        ans++;
    }
}
