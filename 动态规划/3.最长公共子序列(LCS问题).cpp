// 最长公共子序列(LCS问题)
        /*
            给定两个序列X和Y，求X和Y的最长公共子序列。

            刻画LCS问题的最优子结构性质
                令X={x1,x2,...,xm}和Y={y1,y2,...,yn}为两个序列，
                若z={z1,z2,...,zk}为X和Y的一个LCS，则
                    若xm=yn，则zk=xm=yn且z1,z2,...,zk-1是Xm-1和Yn-1的一个LCS
                    若xm!=yn，则zk!=xm且z是Xm-1和Y的一个LCS
                    若xm!=yn，则zk!=yn且z是X和Yn-1的一个LCS
        */

#include<bits/stdc++.h>
#include<string>
using namespace std;

int LCS(string X , string Y){
    int m = X.length();
    int n = Y.length();

    // dp[i][j] : X的前i个字符和Y的前j个字符的LCS长度
    int dp[m+1][n+1] = {};
    for (int i = 1 ; i <= m ; ++i){
        dp[i][0] = 0;
    }
    for (int j = 0 ; j <= n ; ++j){
        dp[0][j] = 0;
    }

    for (int i = 1 ; i <= m ; ++i){
        for (int j = 1 ; j <= n ; ++j){
            if (X[i-1] == Y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}