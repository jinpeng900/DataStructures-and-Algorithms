#include <bits/stdc++.h>
using namespace std;

int dps(int m , int n){
    if (m == 1 && n == 1) return 1;
    if (m < 1 || n < 1) return 0;
    else{
        return dps(m - 2 , n - 1) + dps(m - 1 , n - 2);
    }
}

int main(){
    int n , m;
    cin >> n >> m;
    cout << dps(m , n) << endl;
    return 0;
}