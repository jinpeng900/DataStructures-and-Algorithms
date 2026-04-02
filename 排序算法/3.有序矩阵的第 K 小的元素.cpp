# include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    vector<int> dp;
    int num = 0;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            dp[num] = matrix[i][j];
            num++;
        }
    }
    sort(dp.begin() , dp.end());
    return dp[k-1];       
}