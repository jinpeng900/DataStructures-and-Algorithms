#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr = {9 , 3 , 1 , 7 , 5 , 6 , 0 , 8};
    const int n = 8;
    vector<vector<int>> ans(n , vector<int>(n , 0));
    for (int i = 0 ; i < n ; i++){
        for (int j = i ; j < n ; j++){
            if (i == j) ans[i][j] = arr[i];
            else ans[i][j] = max(ans[i][j-1] , arr[j]);
        }
    }
    int l , r;
    while(cin >> l >> r){
        cout << ans[l][r] << endl;
    }

    return 0;
}