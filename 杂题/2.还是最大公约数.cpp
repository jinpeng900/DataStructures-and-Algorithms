# include<bits/stdc++.h>
using namespace std;



int GCD3(int a , int b , int c){
    int m = __gcd(a , b);
    int n = __gcd(b , c);
    return __gcd(m , n);
}



int main(){
    int m;
    cin >> m;
    while (m--){
        int a, b , c;
        cin >> a >> b >> c;
        cout << GCD3(a , b , c) << endl;
    }
    return 0;
}

