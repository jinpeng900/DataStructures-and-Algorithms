#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout << "输入矩阵的个数" << endl;
    cin >> n;
    int p[n+1];
    for (int i = 1 ; i <= n ; i++){
        cout << "输入矩阵" << i << "的行数和列数" << endl;
        cin >> p[i-1] >> p[i];
    }

    // dp[i][j] : 矩阵 i 到矩阵 j 的最小乘法次数
    int dp[n+1][n+1] = {};

    // 链长从2开始
    for (int len = 2 ; len <= n ; len++){
        for (int i = 1 ; i <= n - len + 1 ; i++){
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i ; k < j ; k++){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]);
            }
        }
    }
    cout << "矩阵链乘法的最小乘法次数为" << dp[1][n] << endl;
}