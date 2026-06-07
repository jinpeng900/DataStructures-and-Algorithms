#include<bits/stdc++.h>
using namespace std;

int main(){
    int V , n;
    cin >>V >> n;
    vector<vector<int>>dp(n+1 , vector<int>(V+1 , 0));
    vector<int>weight(n+1 , 0);
    vector<int>value(n+1 , 0);

    for (int i = 1 ; i <= n ; i++){
        cin >> weight[i] >> value[i];
    }

    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= V ; j++){
            if (weight[i] > j){
                dp[i][j] = dp[i-1][j];
            } else{
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-weight[i]] + value[i]);
            }
        }
    }

    cout << dp[n][V] << endl;

    return 0;



}