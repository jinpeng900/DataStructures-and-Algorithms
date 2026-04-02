#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main()
{
    int n , S; cin >> n >> S;
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    int sum = 0 , ans = 1e8;
    for (int i = 0 , j = 0 ; i < n;){
        if (sum < S) {sum += a[i] ; i++;}
        else {ans = min(ans , i - j); sum -= a[j];j++;}
    }
    if (ans == 1e8) cout << 0 << endl;
    else cout << ans << endl;

}