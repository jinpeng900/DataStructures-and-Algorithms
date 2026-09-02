#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<vector<long long>> dp(a+1, vector<long long>(b+1, 0));

    int x[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int y[] = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < 8; ++i){
        int nx = c + x[i];
        int ny = d + y[i];

        if (nx >= 0 && ny >= 0 && nx <= a && ny <= b){
            dp[nx][ny] = -1;
        }
    }

    dp[c][d] = -1;
    dp[0][0] = 1;

    for (int i = 1; i <= a; ++i){
        if (dp[i][0] == -1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i-1][0];
    }

    for (int j = 1; j <= b; ++j){
        if (dp[0][j] == -1)
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j-1];
    }

    for (int i = 1; i <= a; ++i){
        for (int j = 1; j <= b; ++j){
            if (dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}