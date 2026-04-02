# include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int ans = -1000000000;
    int dp = arr[0];
    for (int i = 1 ; i < n ; i++)
    {
        dp = max(arr[i] , dp+arr[i]);
        ans = max(ans , dp);
    }
    cout << ans << endl;
    return 0;
}