#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>path(n , 0);
    for (int i = 0 ; i < n ; i++){
        cin >> path[i];
    }

    int ans = path[0];
    int dp = path[0];

    for (int i = 1 ; i < n ; i++){
        dp = max(path[i] , dp+path[i]);
        ans = max(ans , dp);
    }

    cout << ans << endl;
    return 0;
}