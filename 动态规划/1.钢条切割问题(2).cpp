# include<bits/stdc++.h>
using namespace std;
// 效率 O(n^2)
int ans(int n , int p[]){
    if (n == 0) return 0;
    int res = -1;
    for (int i = 1 ; i <= n ; i++){
        res = max(res , p[i] + ans(n - i , p));
    }
    return res;
}