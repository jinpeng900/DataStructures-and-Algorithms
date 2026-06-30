#include<bits/stdc++.h>
using namespace std;

bool paduan(int a , int b){
    if (b % a != 0){
        return false;
    }

    int t = b / a;

    while (t % 3 == 0){
        t = t / 3;
    }
    while (t % 2 == 0){
        t = t / 2;
    }

    if (t == 1){
        return true;
    }

    return false;
}


int main(){
    int n;
    cin >> n;

    while(n--){
        int a , b;
        cin >> a >> b;
        if (paduan(a , b)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;

}