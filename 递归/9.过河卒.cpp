#include <bits/stdc++.h>
using namespace std;

long long lujing(int a, int b, vector<vector<int>>& dp) {
    if (a < 0 || b < 0) return 0;   // 必须最前面
    if (dp[a][b] == -1) return 0;    // 马或马控制的位置不能走
    if (a == 0 && b == 0) return 1;

    return lujing(a - 1, b, dp) + lujing(a, b - 1, dp);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    int x[] = {1, -1, 2, -2, 1, -1, 2, -2};
    int y[] = {2, 2, 1, 1, -2, -2, -1, -1};

    // 马本身的位置
    dp[c][d] = -1;

    // 马能控制的位置
    for (int i = 0; i < 8; ++i) {
        int nx = c + x[i];
        int ny = d + y[i];

        if (nx >= 0 && nx <= a && ny >= 0 && ny <= b) {
            dp[nx][ny] = -1;
        }
    }

    cout << lujing(a, b, dp) << endl;

    return 0;
}