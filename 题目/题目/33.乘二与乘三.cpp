# include<bits/stdc++.h>
using namespace std;

void solve(int a , int b){
    if (b % a != 0){
        cout << "No" << endl;
        return;
    }
    int k = b / a;
    while (k % 2 == 0){
        k /= 2;
    }
    while (k % 3 == 0){
        k /= 3;
    }
    if (k == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}


int main(){
    int n;
    cin >> n;
    while (n--){
        int a , b;
        cin >> a >> b;
        solve(a , b);
    }

    return 0;
}