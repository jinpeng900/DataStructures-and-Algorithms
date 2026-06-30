#include<bits/stdc++.h>
using namespace std;


int main(){
    int n , V;
    cin >> n >> V;
    vector<int>path(n+1 , 0);
    for(int i = 1 ; i <= n ; i++){
        cin >> path[i];
    }

    int i = 1;
    int ans = 0;
    int p = INT_MIN;

    for (int j = 1 ; j <= n ; ++j){
        ans += path[j];
        while (ans > V && i <= j){
            ans -= path[i];
            i++;
        }
        p = max(p , ans);
    }
    cout << p << endl;
    return 0;

}