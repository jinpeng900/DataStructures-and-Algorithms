#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> dp = vector<vector<int>>(100001 , vector<int>(100001 , -1));
    
    for (int z = 0 ; z < n ; ++z){
        int a , b , g , k;
        cin >> a >> b >> g >> k;
        for (int i = 0 ; i <= g ; ++i){
            for (int j = 0 ; j <= k ; ++j){
                if (a+i >= 0 && b+j >= 0 && a+i <= 100000 && b+j <= 100000){
                    dp[a+i][b+j] = z;
                }
            }
        }
    }

    int p , q;
    cin >> p >> q;
    cout << dp[p][q] << endl;
    return 0;
}