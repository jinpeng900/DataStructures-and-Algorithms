#include <bits/stdc++.h>
using namespace std;

// 蓝桥杯题号 2080
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll pq[n];
    for (ll i = 1; i <= n; ++i) {     // 改为0-based索引
        int x; 
        cin >> x;
        pq[i] = x;
    }
    ll sum[n];
    sum[0] = 0;
    for (ll i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + pq[i];
    }
    unsigned long long ans = 0;
    for (ll i = n; i >= 2; --i) {
        ans += sum[i - 1] * pq[i];
    }
    cout << ans << endl;
}