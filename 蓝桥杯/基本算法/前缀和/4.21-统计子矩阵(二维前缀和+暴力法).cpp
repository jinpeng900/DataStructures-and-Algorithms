/*

    给定一个 N * M 的矩阵 A  , 请你统计有多少个子矩阵(最小 1 * 1 , 最大 N * M)
    满足子矩阵中所有元素的和不超过给定的整数 K

*/
# include<bits/stdc++.h>

using namespace std;
int s[550][550];

int main(){
    int n , m , k; cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            int v ; cin >> v;
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + v;
        }
    }

    long long ans = 0;                          // 暴力查询二维子矩阵
    for (int i1 = 1 ; i1 <= n ; i1++){
        for(int i2 = i1 ; i2 <= n ; i2++){
            for(int j1 = 1 ; j1 <= m ; j1++){
                for(int j2 = j1 ; j2 <= m ; j2++){
                    int sum = s[i2][j2] - s[i2][j1-1] - s[i1-1][j2] + s[i1-1][j1-1];
                    if(sum <= k) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
