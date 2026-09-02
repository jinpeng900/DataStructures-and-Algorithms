#include<bits/stdc++.h>
using namespace std;

struct Carpet{
    int a , b , g , k;
};

int main(){
    int n;
    cin >> n;
    
    vector<Carpet> v(n);
    
    for (int i = 0 ; i < n ; ++i){
        cin >> v[i].a >> v[i].b >> v[i].g >> v[i].k;
    }

    int p , q;
    cin >> p >> q;
  
    for (int i = n - 1 ; i >= 0 ; i--){
        int a = v[i].a;
        int b = v[i].b;
        int g = v[i].g;
        int k = v[i].k;

        if (p >= a && p <= a+g && q >= b && q <= b+k){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}