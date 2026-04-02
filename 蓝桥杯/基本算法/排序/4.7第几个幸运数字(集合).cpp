#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef set<ll> st;

set<ll> se;

int main()
{
    ll f = 1;
    ll a[3] = {3 , 5 ,  7};
    while(1){
        for (int i = 0 ; i < 3 ; i++){
            if (f * a[i] <= 59084709587505){
                se.insert(f * a[i]);
            }
        }
        f = *se.upper_bound(f);                     // 找到大于f的第一个数
        if (f >= 59084709587505) break;
    }
    cout << se.size() << endl;
    return 0;
}