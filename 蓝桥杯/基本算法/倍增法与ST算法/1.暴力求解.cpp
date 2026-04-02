#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr = {9 , 3 , 1 , 7 , 5  ,6 , 0 , 8};
    int ans , l , r;
    while(cin >> l >> r){
        ans = INT_MIN;
        for (int i = l ; i <= r ; i++){
            ans = max(ans , arr[i]);
        }
    }
    cout << ans << endl;

    return 0;
}