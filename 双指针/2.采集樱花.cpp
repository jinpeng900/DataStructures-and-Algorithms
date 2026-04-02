# include<bits/stdc++.h>
using namespace std;


int main(){
    int n , V;
    cin >> n >> V;
    vector<int>arr(n);
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    int ans = 0;
    int p = INT_MIN;
    int i = 0;
    for (int j = 0 ; j < n ; j++){
        ans += arr[j];
        while (ans > V && i <= j){
            ans -= arr[i];
            i++;
        }
        p = max(ans , p);
    }
    cout << p << endl;
    
    return 0;


}