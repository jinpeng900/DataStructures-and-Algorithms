#include<bits/stdc++.h>

using namespace std;

int main(){
    int N , M , Q;
    cin >> N >> M >> Q;
    vector<vector<int>> dp;
    dp = vector<vector<int>>(N + 1);
    for (int i = 1 ; i <= M ; i++){
        int u , v;
        cin >> u >> v;
        dp[u].push_back(v);
    }

    for (int i = 1 ; i <= Q ; i++){
        int u , k;
        cin >> u >> k;
        if (k > dp[u].size()){
            cout << -1 << endl;
        }
        else{
            sort(dp[u].begin() , dp[u].end());
            cout << dp[u][k-1] << endl;
        }
    }

    return 0;
}