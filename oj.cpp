#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , W;
    cin >> n >> W;
    vector<int>weight(n+1 , 0);
    for (int i = 1 ; i <= n ; i++){
        cin >> weight[i];
    }
    sort(weight.begin() + 1 , weight.end());

    int i = 1 , j = n;
    int ans = 0;

    while(i <= j){
        if (weight[i] + weight[j] <= W){
            ans++;
            i++;
            j--;
        }
        else{
            ans++;
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}