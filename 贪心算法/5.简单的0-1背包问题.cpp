#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int W , n;
    cin >> W >> n;
    vector<int> w(n) , v(n);
    for (int i = 0 ; i < n ; i++){
        cin >> w[i] >> v[i];
    }
    vector<vector<int>> dp(n + 1 , vector<int>(W + 1 , 0));
    for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= W; j++) { // 正序遍历
        if (j >= w[i - 1]) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        } else {
            dp[i][j] = dp[i - 1][j]; // 关键：承接上一行的状态
        }
    }
}
    cout << dp[n][W] << endl;
    return 0;
}