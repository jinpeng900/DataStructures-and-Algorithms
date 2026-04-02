#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> dp;                 // dp[i][j] 表示在左端点为 i , 长度为 2^j 这样的区间 , 也就是[i , i+ 2^j - 1]


int query(int l , int r){
    int j = (int)log2(r - l + 1);
    return max(dp[l][j] , dp[r - (1 << j) + 1][j]);
}


int main(){
    vector<int> arr = {9 , 3 , 1 , 7 , 5 , 6 , 0 , 8};
    const int n = 8;
    dp = vector<vector<int>>(n , vector<int>((int)log2(n) + 1 , 0));
    for(int i = 0 ; i < n ; i++) dp[i][0] = arr[i];
    for (int j =  1 ; j <= log2(n) ; j++)
        for (int i = 0 ; i + (1 << j) - 1 < n ; i++)
            dp[i][j] = max(dp[i][j-1] , dp[i+ (1<<(j-1))][j-1]);
    int l , r;
    while(cin >> l >> r){
        cout << query(l , r) << endl;
    }

    return 0;
}