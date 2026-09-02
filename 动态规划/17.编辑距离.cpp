# include<bits/stdc++.h>
using namespace std;

int main(){
    string A;
    string B;

    cin >> A >> B;

    int m = A.length();
    int n = B.length();

    vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));

    // 初始化边界条件
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i; // B 是空串，A 需要删除 i 个字符
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j; // A 是空串，A 需要.0插入 j 个字符
    }

    for (int i = 1 ; i <= m ; i++){
        for (int j = 1 ; j <= n ; j++){
            if (A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1]}) + 1;
            }
        }
    }
    
    cout << dp[m][n] << endl;

    return 0;
}