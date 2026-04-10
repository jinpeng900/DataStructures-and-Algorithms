#include<bits/stdc++.h>
using namespace std;


void search(long a , long b , long k){
    long z;
    if ((a+b) % 2 == 0){
        z = (a+b) / 2;
    }
    else{
        z = (a+b-1) / 2;
    }
    if (z == k){
        cout << "G" << "";
        return ;
    }

    else if (z < k){
        cout << "R" << "";
        search(z+1 , b , k);
    }

    else{
        cout << "L" << "";
        search(a , z-1 , k);
    }
}


int main(){
    long x , y , z;
    cin >> x >> y >> z;
    search(x , y , z);
    return 0;
}