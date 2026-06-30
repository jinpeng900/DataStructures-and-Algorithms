#include<bits/stdc++.h>
using namespace std;

int tiaoshu(int n , int m){
    if (n == 1 && m == 1) return 1;

    else if (n < 1 || m < 1) return 0;

    else{
        return tiaoshu(n - 2 , m - 1) + tiaoshu(n - 1 , m - 2);
    }
}