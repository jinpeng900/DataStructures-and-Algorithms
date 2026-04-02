#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N;
    cin >> N;
    vector<ll> H(N + 1);
    for (int i = 1 ; i <= N ; ++i){
        cin >> H[i];
    }
    vector<ll> ans(N + 1 , 0);
    stack<int> stk;
    for (ll i = N ; i >= 1 ; --i){
        while (!stk.empty() && H[stk.top()] <= H[i]){
            stk.pop();
        }
        if (!stk.empty()){
            ans[i] = stk.top();
        }
        stk.push(i);
    }
    for (ll i = 1 ; i <= N ; ++i){
        cout << ans[i] << " ";
    }
}
