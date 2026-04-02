# include<bits/stdc++.h>
using namespace std;


/*
 动态规划

创建二维数组 dp , 与原始网格大小相同 , dp[i][j] 表示从左上角出发到 (i , j) 的最小路径和 . 显然, dp[0][0] = grid[0][0]. 对于 dp 中的其余元素 , 通过以下状态转移方程计算元素值
    当 i > 0 且 j = 0 时 ,  dp[i][0] = dp[i - 1][0] + grid[i][0]
    当 i = 0 且 j > 0 时 ,  dp[0][j] = dp[0][j - 1] + grid[0][j]
    当 i > 0 且 j > 0 时 ,  dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j]

*/

int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0 && grid[0].size() == 0){
        return 0;
    }        

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp = vector<vector<int>>(m , vector<int>(n , 0));
    dp[0][0] = grid[0][0];

    for (int i = 1 ; i < m ; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for (int j = 1 ; j < n ; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(int i = 1 ; i < m ; i++){
        for (int j = 1 ; j < n ; j++){
            dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[m-1][n-1];

}